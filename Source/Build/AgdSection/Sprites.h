//---------------------------------------------------------------------------
#ifndef SpritesH
#define SpritesH
//---------------------------------------------------------------------------
#include "Build/AgdSection/SectionBuilder.h"
//---------------------------------------------------------------------------
namespace SectionBuilders
{
class Sprites : public SectionBuilder
{
protected:
    void    __fastcall  Execute() final;
public:
            __fastcall  Sprites();
    virtual __fastcall ~Sprites();
};
}
//---------------------------------------------------------------------------
#endif
