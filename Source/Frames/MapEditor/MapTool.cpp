//---------------------------------------------------------------------------
#include "AgdStudio.pch.h"
//---------------------------------------------------------------------------
#include "MapTool.h"
#include "Project/DocumentManager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
 MapTool::MapTool()
: Tool()
, m_TileSize(theDocumentManager.ProjectConfig()->MachineConfiguration().ImageSizing[Visuals::itTile].Minimum)
{
}
//---------------------------------------------------------------------------
 MapTool::~MapTool()
{
}
//---------------------------------------------------------------------------
int MapTool::Snap(int value, int range) const
{
    return ((int)(value / range)) * range;
}
//---------------------------------------------------------------------------
void MapTool::SnapToTileGrid(TPoint& pt) const
{
    pt.x = Snap(pt.x, m_TileSize.cx);
    pt.y = Snap(pt.y, m_TileSize.cy);
}
//---------------------------------------------------------------------------
void MapTool::SnapToTileGrid(TRect& rect) const
{
    rect.Left   = Snap(rect.Left  , m_TileSize.cx);
    rect.Right  = Snap(rect.Right , m_TileSize.cx);
    rect.Top    = Snap(rect.Top   , m_TileSize.cy);
    rect.Bottom = Snap(rect.Bottom, m_TileSize.cy);
}
//---------------------------------------------------------------------------
void MapTool::Set(Project::MapEntityList& list, const Project::MapEntity& entity)
{
    if (Flags & allowOnlyOne)
    {
        list.clear();
        list.push_back(entity);
    }
    else
    {
        if (IsPointValid(entity.Pt))
        {
            auto it = std::find(list.begin(), list.end(), entity);
            if (it == list.end())
            {
                auto e = entity;
                e.Selected = false;
                list.push_back(e);
            }
        }
    }
}
//---------------------------------------------------------------------------
String MapTool::Begin(Project::MapEntityList& list, Project::MapEntity entity, const TPoint& pt, const TShiftState& buttons)
{
    Tool::Begin(pt, buttons);
    Apply(list, entity);
    return String();
}
//---------------------------------------------------------------------------
void MapTool::Move(Project::MapEntityList& list, Project::MapEntity entity, const TPoint& pt, const TShiftState& buttons)
{
    Tool::Move(pt, buttons);
    if (Flags & resetOnMove)
        list.clear();
    if (entity.Image->SubType != "Tile")
        return;
    if (!IsDrawing) return;
    Apply(list, entity);
}
//---------------------------------------------------------------------------
String MapTool::End(Project::MapEntityList& list, Project::MapEntity entity, const TPoint& pt)
{
    Tool::End(pt);
    if (pt != LastPt)
    {
        Apply(list, entity);
    }
    return String();
}
//---------------------------------------------------------------------------

