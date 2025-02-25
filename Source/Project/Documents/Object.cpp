//---------------------------------------------------------------------------
#include "AGD Studio.pch.h"
//---------------------------------------------------------------------------
#include "Object.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
using namespace Project;
//---------------------------------------------------------------------------
__fastcall ObjectDocument::ObjectDocument(const String& name, const String& extra)
: ImageDocument(name)
, m_RoomIndex(g_RoomIndexDisabled)
, m_Position(0,0)
, m_State(Visuals::osDisabled)
{
    m_ImageType = Visuals::itObject;
    m_CanBeLocked = true;
    m_SubType = "Object";
    m_Folder = "Images\\Objects";

    m_PropertyMap["Image.RoomIndex"] = &m_RoomIndex;
    m_PropertyMap["Image.Position.X"] = &m_Position.X;
    m_PropertyMap["Image.Position.Y"] = &m_Position.Y;
    m_PropertyMap["Image.State"] = &m_State;

    RegisterProperty("Name", "Details", "The name of the object");
    RegisterProperty("Room", "Details", "The Location of the room the Object is in. In Across (X) and Down (Y) coordinates");
    RegisterProperty("Position", "Details", "The pixel position of the object in the room");
    RegisterProperty("State", "Details", "The state the Object is in (Assigned to a Room, the Inventory or Disabled)");
    RegisterProperty("X", "Room", "The X position of the image in screen space relative to the game Window.");
    RegisterProperty("Y", "Room", "The Y position of the image in screen space relative to the game Window.");
    RegisterProperty("RoomIndex", "Room", "The AGD SCREEN number");
    m_File = GetFile();
    ExtractSize(extra);
    AddFrame();
}
//---------------------------------------------------------------------------
int __fastcall ObjectDocument::GetPosition(int index)
{
    return index ? m_Position.Y : m_Position.X;
}
//---------------------------------------------------------------------------
void __fastcall ObjectDocument::SetRoomIndex(int value)
{
    if (value != g_RoomIndexEmpty && 0 <= value && value <= g_RoomIndexMax) {
        State = Visuals::osRoom;
        m_RoomIndex = value;
        if (value ==  g_RoomIndexDisabled) {
            State = Visuals::osDisabled;
        } else if (value == g_RoomIndexInventory) {
            State = Visuals::osInventory;
        }
    }
}
//---------------------------------------------------------------------------
void __fastcall ObjectDocument::SetState(Visuals::ObjectState state)
{
    m_State = state;
    if (state == Visuals::osDisabled) {
        m_RoomIndex = g_RoomIndexDisabled;
    } else if (state == Visuals::osInventory) {
        m_RoomIndex = g_RoomIndexInventory;
    }
}
//---------------------------------------------------------------------------
void __fastcall ObjectDocument::DoSaveExtra()
{
    Write("RoomIndex", m_RoomIndex);
    Write("State", m_State);
    Push("Position");
        Write("X", m_Position.X);
        Write("Y", m_Position.Y);
    Pop();
}
//---------------------------------------------------------------------------

