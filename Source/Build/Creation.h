//---------------------------------------------------------------------------
#ifndef CreationH
#define CreationH
//---------------------------------------------------------------------------
#include <list>
#include "Build/BuildProcess.h"
#include "Build/AgdSection/SectionBuilder.h"
//---------------------------------------------------------------------------
class Creation : public BuildProcess
{
private:
    typedef std::list<std::unique_ptr<SectionBuilders::SectionBuilder>> SectionBuilderList;

    SectionBuilderList           m_AgdBuilders;

public:
                    __fastcall  Creation(BuildMessages& buildMessages);
    virtual         __fastcall ~Creation();

            bool    __fastcall  Execute() final;
};
//---------------------------------------------------------------------------
#endif
