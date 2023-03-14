//---------------------------------------------------------------------------
#ifndef ControlsDocumentH
#define ControlsDocumentH
//---------------------------------------------------------------------------
#include "Project/Document.h"
//---------------------------------------------------------------------------
enum eAgdKey { keyFirst = 0, keyUp = 0, keyDown, keyLeft, keyRight, keyFire1, keyFire2, keyFire3, keyOption1, keyOption2, keyOption3, keyOption4, keyLast };
class ControlsDocument : public Document
{
private:
        std::vector<unsigned char>  m_Keys;
            unsigned char           m_Key;

            void        __fastcall  DoSave();
            void        __fastcall  OnEndObject(const String& object);
            void        __fastcall  OnLoading();
            void        __fastcall  OnLoaded();
            String      __fastcall  Get(int index);
            bool        __fastcall  IsActive() const;
            void        __fastcall  DefaultKeys();

public:
                        __fastcall  ControlsDocument(const String& name);

    static  Document*   __fastcall  Create(const String& name, const String& extra) { return new ControlsDocument(name); };

        unsigned char   __fastcall  GetAsciiCode(eAgdKey key);
        void            __fastcall  SetAsciiCode(eAgdKey key, unsigned char keyCode);

__published:
        String          __property  Left = { read = Get, index = keyLeft };
        String          __property  Right = { read = Get, index = keyRight };
        String          __property  Up = { read = Get, index = keyUp };
        String          __property  Down = { read = Get, index = keyDown };
        String          __property  Fire1 = { read = Get, index = keyFire1 };
        String          __property  Fire2 = { read = Get, index = keyFire2 };
        String          __property  Fire3 = { read = Get, index = keyFire3 };
        String          __property  Option1 = { read = Get, index = keyOption1 };
        String          __property  Option2 = { read = Get, index = keyOption2 };
        String          __property  Option3 = { read = Get, index = keyOption3 };
        String          __property  Option4 = { read = Get, index = keyOption4 };
};
//---------------------------------------------------------------------------
#endif
