//---------------------------------------------------------------------------
#ifndef TileEditorH
#define TileEditorH
//---------------------------------------------------------------------------
#include "MapPencilTool.h"
#include "MapLineTool.h"
#include "MapRectTool.h"
#include "Project/Documents/TiledMap.h"
#include "Messaging/Messaging.h"
#include "Messaging/Event.h"
#include "Visuals/Image.h"
#include "Visuals/GraphicsMode.h"
//---------------------------------------------------------------------------
class TileEditor
{
public:
    enum TEMode { temSelect, temPencil, temLine, temRect };
private:
    struct TFPoint
    {
        TFPoint() {}
        TFPoint(float x, float y) : x(x), y(y) {}
        float x;
        float y;
    };

    enum MouseModes { mmTool, mmGroupSelect };
    enum EntityDrawFilters { edfDirty = 1, edfSelected = 2, edfFirstTile = 4, edfForce = 8 };

    Registrar                   m_Registrar;        // the messaging registrar
    std::unique_ptr<TBitmap>    m_Content;          // 1:1 content
    std::unique_ptr<TBitmap>    m_Tile0Content;     // 1:1 content with all tile0's used to clear the m_Content quickly
    TSize                       m_ContentSize;      // the size of the content window that we need (content bitmap is always larger for blt reasons)
    TImage* const               m_View;             // the UI image we render to
    TImage*                     m_LockIcon;         // the lock icon
    Project::MapEntityList      m_Entities;         // all the map entities
    Project::MapEntityList      m_ToolEntities;     // the entities for the current tool (select etc)
    Project::MapEntityList      m_ClipboardEntities;// the entities for the clipboard (copy, cut, paste)
    Project::MapEntity          m_ToolEntity;       // the image document selected in the map editor UI
    Project::MapEntity          m_HoverEntity;      // the entity the mouse is hovering over
    TEMode                      m_Mode;             // tool mode (pencil, line etc)
    bool                        m_Dirty;            // flag: tool is dirty - map needs updating
   const Visuals::GraphicsMode& m_GraphicsMode;     // the graphics mode used by the project
    Visuals::ImageMap&          m_ImageMap;         // a map of all images as bitmaps
    float                       m_ScaleFactor;      // the scale factor of the content view on to the overlays view
    TFPoint                     m_Scale;            // the applied scale factor for both x and y axes
    bool                        m_UsesGridTile;     // flag: uses a tile grid
    bool                        m_UsesGridRoom;     // flag: uses a room grid
    bool                        m_ShowGridTile;     // flag: show tile grid
    bool                        m_ShowGridRoom;     // flag: show room grid
    bool                        m_MousePanning;     // flag: panning the window with the mouse
    bool                        m_SelectionMove;    // flag: moving the entity selections
    bool                        m_ForceMapDraw;     // flag: force a full redraw of the map
    TPoint                      m_MapOffsetMS;      // offset into the map to render to the workspace (Coords in Map Space)
    TRect                       m_Window;           // the number of tiles across and down of the window area
    TSize                       m_TileSize;         // the size in pixels of a tile
    TSize                       m_Rooms;            // the number of rooms across and down
    TSize                       m_SelectedRoom;     // the currently selected room
    MouseModes                  m_MouseMode;        // the current state of mouse use (tool use or group select)
    MouseModes                  m_PrevMouseMode;    // tbe previous state of mouse use
    TPoint                      m_LastMouse;        // the last position of the mouse
    TPoint                      m_MoveMouse;        // the current position of the mouse
    TPoint                      m_GroupSelectSrtMS; // start group select pt (Coords in Map Space)
    TPoint                      m_GroupSelectEndMS; // end group select pt (Coords in Map Space)
    TPoint                      m_BorderScaled;     // the view border scaled to map space
    int                         m_Border;           // the size of a border around the tiles
    int                         m_SelectionCount;   // the number of entities selected
    unsigned int                m_Tile0Id;          // tile 0 id
    bool                        m_ReadOnly;         // read only - no changes allowed - room selection only
    bool                        m_ShowSelectedRoom; // show the selected room highlighted
    bool                        m_ShowStartRoom;    // show the start room highlighted
    bool                        m_ShowRoomNumbers;  // show room index numbers
    bool                        m_ShowTileTypes;    // show the tile types using their image editor colours
    bool                        m_ShowSpriteTypes;  // show the sprite type
    TPoint                      m_StartRoom;        // the location of the start room
    MapPencilTool               m_MapPencilTool;    // pencil tool - plot single entites
    MapRectTool                 m_MapRectTool;      // rect tool - draw tiles (only) in a rectangle
    MapLineTool                 m_MapLineTool;      // line tool - draw tiles (only) in a line
    MapTool*                    m_ActiveMapTool;    // the active tool (from 1 of 3 above)

    void                __fastcall  OnWindowChanged(const WindowChangedEvent& event);
    void                __fastcall  CreateViewBitmap();
    void                __fastcall  Clear();
    void                __fastcall  SelectRoom(TSize room);
    void                __fastcall  ValidatePosition();
    TPoint              __fastcall  MapToView(const TPoint& pt) const;
    TPoint              __fastcall  ViewToMap(int X, int Y) const;
    void                __fastcall  ResetToOrigin(Project::MapEntityList& list, const TPoint& originPt) const;
    bool                __fastcall  GetGridTile();
    bool                __fastcall  GetGridRoom();
    unsigned int        __fastcall  GetToolEntity() const;
    void                __fastcall  SetGridTile(bool value);
    void                __fastcall  SetGridRoom(bool value);
    void                __fastcall  SetRooms(TSize rooms);
    void                __fastcall  SetTile0Id(unsigned int id);
    void                __fastcall  SetToolEntity(unsigned int id);
    void                __fastcall  SetReadOnly(bool state);
    void                __fastcall  SetShowSelectedRoom(bool state);
    void                __fastcall  SetShowStartRoom(bool state);
    void                __fastcall  SetShowRoomNumbers(bool state);
    void                __fastcall  SetShowTileTypes(bool state);
    void                __fastcall  SetShowSpriteTypes(bool state);
    void                __fastcall  SetStartRoomCoords(TPoint location);
    void                __fastcall  SetScale(float scale);
    void                __fastcall  SetMode(TEMode mode);
    void                __fastcall  SetLockIcon(TImage* icon);
    void                __fastcall  DrawEntities(int filters, Visuals::ImageTypes type = Visuals::itInvalid);
    void                __fastcall  DrawToolEntities();
    void                __fastcall  DrawHoverEntity();
    void                __fastcall  DrawMap();
    void                __fastcall  DrawGrids() const;
    void                __fastcall  DrawRoomNumbers() const;
    void                __fastcall  DrawSpriteTypes() const;
    void                __fastcall  DrawEntityLocks() const;
    void                __fastcall  DrawGroupSelect() const;
    void                __fastcall  DrawSelectedRoom() const;
    void                __fastcall  DrawStartRoom() const;
    int                 __fastcall  Snap(int value, int range) const;
    void                __fastcall  Get(const TRect& rect, Project::MapEntityList& entities) const;
    void                __fastcall  ReplaceEntities();
    void                __fastcall  UpdateTile0Content();
    bool                __fastcall  ClearHover();
    void                __fastcall  SelectHover();
    bool                __fastcall  GetEntityUnderMouse(int X, int Y, Project::MapEntity& entity, Visuals::ImageTypes imageType, bool selectIt = false);
    void                __fastcall  AssignRoomIndexes(Project::MapEntityList& entities);

    void                __fastcall  OnMouseDownSelectMode(TMouseButton Button, TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseDownMapToolMode(TMouseButton Button, TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseMoveSelectMode(TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseMoveMapToolMode(TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseUpSelectMode(TMouseButton Button, TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseUpMapToolMode(TMouseButton Button, TShiftState Shift, int X, int Y);

    __property  bool                IsDirty = { read = m_Dirty, write = m_Dirty };

    typedef void __fastcall (__closure *TNotifyOnEntityClick)(const Project::MapEntity& entity);
    TNotifyOnEntityClick            FOnEntitySelected;
    typedef int __fastcall (__closure *TRetrieveRoomIndex)(const TPoint& pt, bool newIndex) const;
    TRetrieveRoomIndex   __fastcall FRetrieveRoomIndex;

public:

                        __fastcall  TileEditor(TImage* const view, Visuals::ImageMap& imageMap, const TSize& rooms, bool usesGridTile, bool usesGridRoom, int border, bool readOnly = false);
                        __fastcall ~TileEditor();

    void                __fastcall  OnMouseDown(TMouseButton Button, TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseMove(TShiftState Shift, int X, int Y);
    void                __fastcall  OnMouseUp(TMouseButton Button, TShiftState Shift, int X, int Y);

    void                __fastcall  Refresh();
    void                __fastcall  UpdateMap();

    void                __fastcall  SetEntities(const Project::MapEntityList& entities);
   const Project::MapEntityList& __fastcall  GetEntities() const;
    void                __fastcall  Add(const Project::MapEntityList& entities);
    void                __fastcall  ToggleEntityLocks();
    void                __fastcall  SetSpriteType(int type);
Project::MapEntityList  __fastcall  GetSelection(bool resetToOrigin = false) const;
    void                __fastcall  DeleteSelection();
    void                __fastcall  UnselectAll(bool update = true);
    void                __fastcall  Copy();
    void                __fastcall  Cut();
    void                __fastcall  Paste();

    // properties
    __property  TEMode          Mode                = { read = m_Mode            , write = SetMode            };
    __property  TSize           Rooms               = { write = SetRooms                                      };
    __property  float           Scale               = { read = m_ScaleFactor     , write = SetScale           };
    __property  bool            GridTile            = { read = m_ShowGridTile    , write = SetGridTile        };
    __property  bool            GridRoom            = { read = m_ShowGridRoom    , write = SetGridRoom        };
    __property  unsigned int    Tile0Id             = { read = m_Tile0Id         , write = SetTile0Id         };
    __property  unsigned int    ToolEntity          = { read = GetToolEntity     , write = SetToolEntity      };
    __property  bool            ReadOnly            = { read = m_ReadOnly        , write = SetReadOnly        };
    __property  TSize           SelectedRoom        = { read = m_SelectedRoom                                 };
    __property  TPoint          StartRoom           = { read = m_StartRoom       , write = SetStartRoomCoords };
    __property  bool            ShowSelectedRoom    = { read = m_ShowSelectedRoom, write = SetShowSelectedRoom};
    __property  bool            ShowStartRoom       = { read = m_ShowStartRoom   , write = SetShowStartRoom   };
    __property  bool            ShowRoomNumbers     = { read = m_ShowRoomNumbers , write = SetShowRoomNumbers };
    __property  bool            ShowTileTypes       = { read = m_ShowTileTypes   , write = SetShowTileTypes   };
    __property  bool            ShowSpriteTypes     = { read = m_ShowSpriteTypes , write = SetShowSpriteTypes };
    __property  TImage*         LockIcon            = { write = SetLockIcon                                   };

    // event handlers
    __property TNotifyOnEntityClick OnEntitySelected= { read = FOnEntitySelected , write = FOnEntitySelected  };
    __property TRetrieveRoomIndex  RetrieveRoomIndex= { read = FRetrieveRoomIndex, write = FRetrieveRoomIndex };
};
//---------------------------------------------------------------------------
#endif
