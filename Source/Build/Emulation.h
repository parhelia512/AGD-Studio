//---------------------------------------------------------------------------
#ifndef EmulationH
#define EmulationH
//---------------------------------------------------------------------------
#include "ShellProcess.h"
//---------------------------------------------------------------------------
namespace Build
{
//---------------------------------------------------------------------------
class Emulation : public ShellProcess
{
public:
                     Emulation(BuildMessages& buildMessages);
    virtual         ~Emulation();

            bool     Execute() final;
};
//---------------------------------------------------------------------------
} // Build namespace
//---------------------------------------------------------------------------
#endif
