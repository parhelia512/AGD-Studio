//---------------------------------------------------------------------------
#ifndef fSelectionImageH
#define fSelectionImageH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "Visuals/GraphicsBuffer.h"
//---------------------------------------------------------------------------
class TSelectionImageFrame : public TFrame
{
__published:// IDE-managed Components
    TImage *imgBitmap;
    TPanel *panHint;
    void __fastcall imgBitmapClick(TObject *Sender);

private:    // User declarations
 const Visuals::GraphicsBuffer&
                            m_Image;
                String      m_Hint;
                bool        m_Selected;
                int         m_Scale;
                float       m_ScalarX;
                float       m_ScalarY;
               TNotifyEvent FOnClick;

    void    __fastcall          SetSelected(bool state);
    void    __fastcall          SetScale(int scale);
public:     // User declarations
            __fastcall          TSelectionImageFrame(TComponent* Owner, const Visuals::GraphicsBuffer& image, const String& hint = "");

    void    __fastcall          Update() override;

    bool    __property          Selected        = { read = m_Selected, write = SetSelected };
    int     __property          Scale           = { read = m_Scale   , write = SetScale    };

            // click events
        __property TNotifyEvent OnSelectedClick = { read = FOnClick  , write = FOnClick    };
};
//---------------------------------------------------------------------------
#endif
