//---------------------------------------------------------------------------
#include "AgdStudio.pch.h"
//---------------------------------------------------------------------------
#include "PreChecks.h"
#include "Project/DocumentManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace Build;
//---------------------------------------------------------------------------
 PreChecks::PreChecks(BuildMessages& buildMessages)
: BuildProcess(buildMessages, bmChecking, "Checking Project Dependencies")
{
}
//---------------------------------------------------------------------------
PreChecks::~PreChecks()
{
}
//---------------------------------------------------------------------------
bool PreChecks::Execute()
{
    const auto& mc = theDocumentManager.ProjectConfig()->MachineConfiguration();
    auto cp = Services::File::Exists(mc.Compiler.Path) || Services::File::Exists(Services::File::Combine(Services::Folders::Application, mc.Compiler.Path));
    auto ep = Services::File::Exists(mc.Engine.Path) || Services::File::Exists(Services::File::Combine(Services::Folders::Application, mc.Engine.Path));
    auto ap = Services::File::Exists(mc.Assembler.Path) || Services::File::Exists(Services::File::Combine(Services::Folders::Application, mc.Assembler.Path));
    auto mp = Services::File::Exists(mc.Emulator.Path) || Services::File::Exists(Services::File::Combine(Services::Folders::Application, mc.Emulator.Path));
    BUILD_LINE(cp ? bmOk : bmFailed, "Checking for AGD Compiler: " + mc.Compiler.Path);
    BUILD_LINE(ep ? bmOk : bmFailed, "Checking for AGD Engine: " + mc.Engine.Path);
    BUILD_LINE(ap ? bmOk : bmFailed, "Checking for Assembler: " + mc.Assembler.Path);
    BUILD_LINE(mp ? bmOk : bmFailed, "Checking for Emulator: " + mc.Emulator.Path);
    return cp && ap && ep;
}
//---------------------------------------------------------------------------
