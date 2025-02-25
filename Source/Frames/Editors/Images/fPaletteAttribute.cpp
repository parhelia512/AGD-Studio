//---------------------------------------------------------------------------
#include "AGD Studio.pch.h"
//---------------------------------------------------------------------------
#include "fPaletteAttribute.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
__fastcall TfrmPaletteAttribute::TfrmPaletteAttribute(TComponent* Owner)
: TFrame(Owner)
, m_Ink(7)
, m_Paper(0)
, m_Bright(0)
, m_Flash(0)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPaletteAttribute::Set(Visuals::GraphicsBuffer& canvas)
{
    // change the color set of the canvas
    canvas.Color[0] = m_Ink;
    canvas.Color[1] = m_Paper;
    canvas.Color[2] = m_Bright;
    canvas.Color[3] = m_Flash;
}
//---------------------------------------------------------------------------
void __fastcall TfrmPaletteAttribute::spdInkBlackClick(TObject *Sender)
{
    m_Ink = static_cast<unsigned char>(static_cast<TControl*>(Sender)->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPaletteAttribute::spdPaperBlackClick(TObject *Sender)
{
    m_Paper = static_cast<unsigned char>(static_cast<TControl*>(Sender)->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPaletteAttribute::spdBrightOffClick(TObject *Sender)
{
    m_Bright = static_cast<unsigned char>(static_cast<TControl*>(Sender)->Tag);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPaletteAttribute::spdFlashOffClick(TObject *Sender)
{
    m_Flash = static_cast<unsigned char>(static_cast<TControl*>(Sender)->Tag);
}
//---------------------------------------------------------------------------

