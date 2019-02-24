//---------------------------------------------------------------------------
#ifndef fEditorControlsH
#define fEditorControlsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "LMDDckSite.hpp"
#include "Project/ControlsDocument.h"
//---------------------------------------------------------------------------
class TfrmEditorControls : public TFrame
{
__published:// IDE-managed Components
    void __fastcall FrameMouseActivate(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate);
private:    // User declarations
    ControlsDocument*           m_Document;
    std::unique_ptr<TBitmap>    m_View;

    bool            __fastcall  IsActive() const;
    void            __fastcall  SetDocument(Document* document);
    void            __fastcall  ShowKeysHelp();
    void            __fastcall  DrawView();

public:        // User declarations
                    __fastcall  TfrmEditorControls(TComponent* Owner);
    static  TFrame* __fastcall  Create(Document* document, TComponent* owner)
                                {
                                    auto editor = new TfrmEditorControls(owner);
                                    editor->SetDocument(document);
                                    document->DockPanel = dynamic_cast<TLMDDockPanel*>(owner);
                                    return editor;
                                }
};
//---------------------------------------------------------------------------
#endif
