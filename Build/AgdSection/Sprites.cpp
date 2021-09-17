//---------------------------------------------------------------------------
#include "agdx.pch.h"
#include "Build/AgdSection/Sprites.h"
#include "Project/DocumentManager.h"
#include "Project/SpriteDocument.h"
#include "Graphics/GraphicsMode.h"
#include "Graphics/Image.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall SectionBuilders::Sprites::Sprites()
: SectionBuilder("Sprites")
{
}
//---------------------------------------------------------------------------
__fastcall SectionBuilders::Sprites::~Sprites()
{
}
//---------------------------------------------------------------------------
void __fastcall SectionBuilders::Sprites::Execute()
{
    const auto& dm = theDocumentManager;
    DocumentList images;
    dm.GetAllOfType("Image", images);
    for (auto image : images)
    {
        // TODO: Add support for big images
        auto sprite = dynamic_cast<SpriteDocument*>(image);
        if (sprite != nullptr)
        {
            String line = "DEFINESPRITE " + IntToStr(sprite->Frames) + " ";
            AddLine(line);
            const auto& gm = (*(theDocumentManager.ProjectConfig()->MachineConfiguration().GraphicsMode()));
            auto image = std::make_unique<Agdx::Image>(sprite, gm);
            for (auto i = 0; i < sprite->Frames; i++)
            {
                line = "             ";
                image->ChangeFrame(i);
                auto data = image->GetExportNativeFormat();
                // export the machine graphics data
                auto w = 0;
                for (auto byte : data)
                {
                    line += IntToStr(byte) + " ";
                    if (++w % 16 == 0)
                    {
                        line += "\r\n             ";
                    }
                }
                AddLine(line);
            }
            LineBreak();
        }
    }

    // no sprites is ok
    Success();
}
//---------------------------------------------------------------------------

