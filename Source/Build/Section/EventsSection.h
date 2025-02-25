//---------------------------------------------------------------------------
#ifndef EventsSectionH
#define EventsSectionH
//---------------------------------------------------------------------------
#include "Section.h"
//---------------------------------------------------------------------------
namespace Build
{
//---------------------------------------------------------------------------
class EventsSection : public Section
{
protected:
    void    __fastcall  Execute() final;
public:
            __fastcall  EventsSection();
    virtual __fastcall ~EventsSection() override;
};
//---------------------------------------------------------------------------
} // Build namespace
//---------------------------------------------------------------------------
#endif
