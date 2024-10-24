//---------------------------------------------------------------------------
#ifndef TiledMapDocumentH
#define TiledMapDocumentH
//---------------------------------------------------------------------------
#include "Document.h"
#include "MapEntity.h"
#include "ObjectDocument.h"
#include "Messaging/Event.h"
//---------------------------------------------------------------------------
namespace Project
{
//---------------------------------------------------------------------------
enum        MapEntityType { meMap, meRoom, meScratchPad };
const int   g_MaxMapRoomsAcross = 16;
const int   g_MaxMapRoomsDown   = 16;
//---------------------------------------------------------------------------
class TiledMapDocument : public Document
{
protected:
           MapEntityList m_Map;
           MapEntityList m_Room;
           MapEntityList m_ScratchPad;

            int          m_StartRoomIndex;
            TPoint       m_StartRoomCoords;
            int          m_ScreenCount;
            MapEntity    m_EntityLoader;
            TSize        m_ActiveRoom;
        std::vector<int> m_RoomMapping; // a mapping from Studio to .AGD screen indexes
            int          m_RoomMappingWidth;
            int          m_RoomMappingHeight;
            int          m_RoomMappingIndex;

            void         OnEndObject(const String& object);
            void         OnDocumentChanged(const DocumentChange<String>& message);
            void         OnSetStartRoom(const SetStartRoom& event);
            void         DoSave();
            void         UpdateEntityRooms();
            void         UpdateScreenCoords();
            void         OnLoading();
            void         OnLoaded();
__fastcall  int          GetStartRoomCoords(int index) const;
            void         SetStartRoomCoords(const TPoint& coords);
            const TRect& GetWindow() const;
__fastcall  int          GetNumberOfRooms();
__fastcall  int          GetMaxRooms(int index);

__property  const TRect& Window   = { read = GetWindow                       };

public:
                         TiledMapDocument(const String& name);
                        ~TiledMapDocument();
    static  Document*    Create(const String& name, const String& extra) { return new TiledMapDocument(name); };

          MapEntityList  Get(Visuals::ImageTypes type) const;
    const MapEntityList& Get(MapEntityType type, TSize room = TSize(0,0));
                void     Set(MapEntityType type, const MapEntityList& entities);

                TRect    GetMinimalMapSize();
                int      GetRoomIndex(const TPoint& room, bool newIdForUndefinedRoom = false);
                bool     IsRoomEmpty(int x, int y);
                bool     IsRoomIndexUsed(const int roomIndex) const;

    __property  int      ScreenCount     = { read = m_ScreenCount                    };

__published:
    __property  int      StartRoomIndex  = { read = m_StartRoomIndex                 };
    __property  int      StartRoomX      = { read = GetStartRoomCoords, index = 0    };
    __property  int      StartRoomY      = { read = GetStartRoomCoords, index = 1    };
    __property  int      NumberOfRooms   = { read = GetNumberOfRooms                 };
    __property  int      MaxRoomsAcross  = { read = GetMaxRooms       , index = 0    };
    __property  int      MaxRoomsDown    = { read = GetMaxRooms       , index = 1    };
};
//---------------------------------------------------------------------------
} // Project namespace
//---------------------------------------------------------------------------
#endif
