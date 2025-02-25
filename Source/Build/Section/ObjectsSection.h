//---------------------------------------------------------------------------
#ifndef ObjectsSectionH
#define ObjectsSectionH
//---------------------------------------------------------------------------
#include "Section.h"
//---------------------------------------------------------------------------
namespace Build
{
//---------------------------------------------------------------------------
class ObjectsSection : public Section
{
protected:
    void    __fastcall  Execute() final;
public:
            __fastcall  ObjectsSection();
    virtual __fastcall ~ObjectsSection() override;
};
//---------------------------------------------------------------------------
} // Build namespace
//---------------------------------------------------------------------------
#endif
