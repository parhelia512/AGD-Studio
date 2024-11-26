//---------------------------------------------------------------------------
#include "AgdStudio.pch.h"
//---------------------------------------------------------------------------
#include "Tile.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace Project;
//---------------------------------------------------------------------------
__fastcall TileDocument::TileDocument(const String& name, const String& extra)
: ImageDocument(name)
{
    m_ImageType = Visuals::itTile;
    m_File = GetFile();
    m_SubType = "Tile";
    m_Folder = "Images\\Tiles";
    if (IsValid(name))
    {
        RegisterProperty("Name", "Details", "The name of the tile");
        ExtractSize(extra);
        AddFrame();
        AddLayer("blocktype", "0");
    }
}
//---------------------------------------------------------------------------
void __fastcall TileDocument::SetType(const String& type)
{
    const String BlockTypes[] = { "EMPTYBLOCK", "PLATFORMBLOCK", "WALLBLOCK", "LADDERBLOCK", "FODDERBLOCK", "DEADLYBLOCK", "CUSTOMBLOCK" };
    for (int i = 0; i < 7; i++) {
        if (type.UpperCase() == BlockTypes[i]) {
            SetLayer("blocktype", IntToStr(i));
            break;
        }
    }
}
//---------------------------------------------------------------------------

