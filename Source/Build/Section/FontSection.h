//---------------------------------------------------------------------------
#ifndef FontSectionH
#define FontSectionH
//---------------------------------------------------------------------------
#include "Section.h"
//---------------------------------------------------------------------------
namespace Build
{
//---------------------------------------------------------------------------
class FontSection : public Section
{
protected:
    void    __fastcall  Execute() final;
public:
            __fastcall  FontSection();
    virtual __fastcall ~FontSection();
};
//---------------------------------------------------------------------------
} // Build namespace
//---------------------------------------------------------------------------
#endif