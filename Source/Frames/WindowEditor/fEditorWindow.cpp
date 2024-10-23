//---------------------------------------------------------------------------
#include "AgdStudio.pch.h"
#include "fEditorWindow.h"
#include "Project/DocumentManager.h"
#include "Frames/EditorManager.h"
#include "Settings/ThemeManager.h"
#include "Visuals/GraphicsMode.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TfrmEditorWindow::TfrmEditorWindow(TComponent* Owner)
: TFrame(Owner)
{
    const auto& mc = theDocumentManager.ProjectConfig()->MachineConfiguration();
    const auto& gm = *(mc.GraphicsMode());
    m_View = make_unique<TBitmap>();
    m_View->PixelFormat = pf32bit;
    m_View->Width = gm.Width / mc.ImageSizing[Visuals::itCharacterSet].Minimum.Width;
    m_View->Height = gm.Height / mc.ImageSizing[Visuals::itCharacterSet].Minimum.Height;

    m_Registrar.Subscribe<Event>(OnEvent);
}
//---------------------------------------------------------------------------
TfrmEditorWindow::~TfrmEditorWindow()
{
    m_Registrar.Unsubscribe();
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::FrameResize(TObject *Sender)
{
    Color = ThemeManager::Background;
    auto s = 8;
    for (; s <= 128; s++)
    {
        auto w = m_View->Width  * s;
        auto h = m_View->Height * s;
        if (w + 32 >= Width || h + 52 > Height)
        {
            s--;
            break;
        }
    }
    // center view window
    m_Scalar = s;
    imgView->Width  = m_View->Width  * s;
    imgView->Height = m_View->Height * s;
    imgView->Left   = (Width  - imgView->Width ) / 2;
    imgView->Top    = (Height - imgView->Height - sbrWindow->Height) / 2;

    DrawView();
}
//---------------------------------------------------------------------------
void TfrmEditorWindow::DrawView()
{
    // draw the window area
    if (m_View != nullptr)
    {
        m_View->Canvas->Brush->Color = ThemeManager::Background;
        m_View->Canvas->FillRect(TRect(0, 0, m_View->Width, m_View->Height));
        for (auto y = m_Document->Top; y <= m_Document->Bottom; y++)
        {
            for (auto x = m_Document->Left; x <= m_Document->Right; x++)
            {
                m_View->Canvas->Pixels[x][y] = (y + x) % 2 ? ThemeManager::Highlight : ThemeManager::Foreground;
            }
        }

        imgView->Picture->Bitmap->Width  = imgView->Width;
        imgView->Picture->Bitmap->Height = imgView->Height;
        StretchBlt(imgView->Picture->Bitmap->Canvas->Handle, 0, 0, imgView->Width, imgView->Height, m_View->Canvas->Handle, 0, 0, m_View->Width, m_View->Height, SRCCOPY);

        // draw the character grid
        imgView->Picture->Bitmap->Canvas->Pen->Color = ThemeManager::Shadow;
        for (auto y = 0; y < m_View->Height; y++)
        {
            imgView->Picture->Bitmap->Canvas->MoveTo(0, y * m_Scalar);
            imgView->Picture->Bitmap->Canvas->LineTo(imgView->Picture->Bitmap->Width, y * m_Scalar);
        }
        imgView->Picture->Bitmap->Canvas->MoveTo(0, m_View->Height * m_Scalar - 1);
        imgView->Picture->Bitmap->Canvas->LineTo(imgView->Picture->Bitmap->Width, m_View->Height * m_Scalar - 1);
        for (auto x = 0; x < m_View->Width; x++)
        {
            imgView->Picture->Bitmap->Canvas->MoveTo(x * m_Scalar, 0);
            imgView->Picture->Bitmap->Canvas->LineTo(x * m_Scalar, imgView->Picture->Bitmap->Height);
        }
        imgView->Picture->Bitmap->Canvas->MoveTo(m_View->Width * m_Scalar - 1, 0);
        imgView->Picture->Bitmap->Canvas->LineTo(m_View->Width * m_Scalar - 1, imgView->Picture->Bitmap->Height);
    }
    sbrWindow->Panels->Items[0]->Text = "Left: "   + IntToStr(m_Document->Left  );
    sbrWindow->Panels->Items[1]->Text = "Top: "    + IntToStr(m_Document->Top   );
    sbrWindow->Panels->Items[2]->Text = "Right: "  + IntToStr(m_Document->Right );
    sbrWindow->Panels->Items[3]->Text = "Bottom: " + IntToStr(m_Document->Bottom);
    sbrWindow->Panels->Items[4]->Text = "Width: "  + IntToStr(m_Document->Width );
    sbrWindow->Panels->Items[5]->Text = "Height: " + IntToStr(m_Document->Height);
}
//---------------------------------------------------------------------------
void TfrmEditorWindow::SetDocument(Project::Document* document)
{
    m_Document = dynamic_cast<Project::WindowDocument*>(document);
    ShowKeysHelp();
}
//---------------------------------------------------------------------------
bool TfrmEditorWindow::IsActive() const
{
    return theEditorManager.IsActive(this);
}
//---------------------------------------------------------------------------
void TfrmEditorWindow::OnEvent(const Event& event)
{
    if (IsActive())
    {
        ShowKeysHelp();
    }
}
//---------------------------------------------------------------------------
void TfrmEditorWindow::ShowKeysHelp()
{
    const String help =
        "Cursor Keys       : Move Window\r\n"
        "Shift+Cursor Keys : Resize Window\r\n";
    HelpKeysMessage(help);
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::imgViewMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
    //
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actMoveLeftExecute(TObject *Sender)
{
    if (IsActive() && m_Document->Left - 1 >= 0)
    {
        m_Document->Set(TRect (m_Document->Left - 1, m_Document->Top, m_Document->Right - 1, m_Document->Bottom));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actMoveRightExecute(TObject *Sender)
{
    auto w = m_Document->Width;
    if (IsActive() && m_Document->Left + w + 1 <= m_View->Width)
    {
        m_Document->Set(TRect (m_Document->Left + 1, m_Document->Top, m_Document->Right + 1, m_Document->Bottom));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actMoveUpExecute(TObject *Sender)
{
    if (IsActive() && m_Document->Top - 1 >= 0)
    {
        m_Document->Set(TRect (m_Document->Left, m_Document->Top - 1, m_Document->Right, m_Document->Bottom - 1));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actMoveDownExecute(TObject *Sender)
{
    auto h = m_Document->Height;
    if (IsActive() && m_Document->Top + h + 1 <= m_View->Height)
    {
        m_Document->Set(TRect (m_Document->Left, m_Document->Top + 1, m_Document->Right, m_Document->Bottom + 1));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actWidthDecExecute(TObject *Sender)
{
    if (IsActive() && m_Document->Width > 8)
    {
        m_Document->Set(TRect (m_Document->Left, m_Document->Top, m_Document->Right - 1, m_Document->Bottom));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actWidthIncExecute(TObject *Sender)
{
    if (IsActive() && m_Document->Left + m_Document->Width + 1 <= m_View->Width)
    {
        m_Document->Set(TRect (m_Document->Left, m_Document->Top, m_Document->Right + 1, m_Document->Bottom));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actHeightDecExecute(TObject *Sender)
{
    if (IsActive() && m_Document->Height >= 8)
    {
        m_Document->Set(TRect (m_Document->Left, m_Document->Top, m_Document->Right, m_Document->Bottom - 1));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::actHeightIncExecute(TObject *Sender)
{
    if (IsActive() && m_Document->Top + m_Document->Height + 1 <= m_View->Height)
    {
        m_Document->Set(TRect (m_Document->Left, m_Document->Top, m_Document->Right, m_Document->Bottom + 1));
        DrawView();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmEditorWindow::FrameMouseActivate(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate)
{
    theEditorManager.SetActive(this);
}
//---------------------------------------------------------------------------

