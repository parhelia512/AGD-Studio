//---------------------------------------------------------------------------
#ifndef fEditorMapH
#define fEditorMapH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Actions.hpp>
#include <System.ImageList.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.ActnList.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.ToolWin.hpp>
#include <Vcl.Menus.hpp>
#include "LMDDckSite.hpp"
#include "LMDButtonPanel.hpp"
#include "LMDControl.hpp"
#include "LMDCustomBevelPanel.hpp"
#include "LMDCustomControl.hpp"
#include "LMDCustomPanel.hpp"
#include "LMDCustomPanelFill.hpp"
#include "LMDCustomParentPanel.hpp"
#include "LMDCustomToolBar.hpp"
#include "LMDToolBar.hpp"
#include "Frames/MapEditor/TileEditor.h"
#include "Project/Document.h"
#include "Project/TiledMapDocument.h"
#include "Messaging/Messaging.h"
#include "Frames/WndProcHandlers.h"
#include "AssetSelection.h"
//---------------------------------------------------------------------------
class TfrmEditorMap : public TFrame
{
__published:    // IDE-managed Components
    TImageList *tbrImagesEnabled;
    TImageList *tbrImagesDisabled;
    TActionList *tbrActions;
    TAction *actSelect;
    TAction *actPencil;
    TAction *actLine;
    TAction *actRect;
    TAction *actZoomIn;
    TAction *actZoomOut;
    TAction *actZoomReset;
    TAction *actUndo;
    TAction *actRedo;
    TPopupMenu *popWorkspace;
    TPopupMenu *popScratchPad;
    TLMDDockSite *dpTileMap;
    TLMDDockPanel *dpScratchPad;
    TLMDDockPanel *dpWorkspace;
    TLMDDockPanel *dpAssets;
    TPanel *panScratchPadView;
    TImage *imgScratchPad;
    TPageControl *pgcAssets;
    TTabSheet *tabTiles;
    TfrmAssetSelection *assetsTiles;
    TTabSheet *tabSprites;
    TfrmAssetSelection *assetsSprites;
    TTabSheet *tabObjects;
    TfrmAssetSelection *assetsObjects;
    TPanel *panWorkspaceView;
    TImage *imgWorkspace;
    TPanel *panToolbars;
    TLabel *lblTools;
    TToolBar *tbrGrids;
    TToolBar *tbrTools;
    TToolButton *btnSelect;
    TToolButton *btnPencil;
    TToolButton *btnLine;
    TToolButton *btnRect;
    TMenuItem *mnuWSCopytoScratchPad;
    TMenuItem *mnuWSMoveToScratchPad;
    TMenuItem *mnuSPCopytoWorkspace;
    TMenuItem *mnuSPDuplicate;
    TMenuItem *mnuWSDuplicate;
    TMenuItem *Delete1;
    TMenuItem *Delete2;
    TMenuItem *N1;
    TMenuItem *N2;
    TActionList *actSmallActions;
    TImageList *imgSmallIcons;
    TAction *actDelete;
    TAction *actDuplicate;
    TAction *actCopyToScratchPad;
    TAction *actMoveToScratchPad;
    TAction *actCopyToWorkspace;
    TToolBar *tbrScratchPad;
    TToolButton *btnScratchCopyFrom;
    TToolButton *btnSep2;
    TToolButton *btnScratchDuplicate;
    TToolButton *btnSep3;
    TToolButton *btnScratchDelete;
    TToolBar *tbrWorkspace;
    TToolButton *btnScratchCopyTo;
    TToolButton *btnScratchMoveTo;
    TToolButton *ToolButton8;
    TToolButton *btnViewDuplicate;
    TToolButton *ToolButton10;
    TToolButton *btnViewDelete;
    TMenuItem *N3;
    TMenuItem *mnuWSToggleToolbar;
    TMenuItem *N4;
    TMenuItem *mnuSPToggleToolbar;
    TToolButton *btnSep1;
    TToolButton *btnSPGridTile;
    TMenuItem *mnuSPToggleGrid;
    TPanel *panSplitter4;
    TAction *actGridTile;
    TAction *actGridRoom;
    TToolButton *btnWSGridTile;
    TToolButton *btnWSGridRoom;
    TToolBar *tbrModes;
    TAction *actToggleStartRoom;
    TToolButton *btnEditModeMultiple;
    TAction *actEditModeFullMap;
    TPanel *panGrids;
    TPanel *panModes;
    TAction *actEntityNext;
    TAction *actEntityPrev;
    TLMDDockPanel *dpRoomSelector;
    TImage *imgRoomSelector;
    TScrollBox *sbxWorkspace;
    TAction *actCopy;
    TAction *actCut;
    TAction *actPaste;
    TStatusBar *sbrWorkspace;
    TStatusBar *sbrRoomSelection;
    TStatusBar *StatusBar1;
    TImage *imgLock;
    TToolButton *ToolButton1;
    TToolButton *btnEntityPrev;
    TToolButton *btnEntityNext;
    TPanel *panVisuals;
    TToolBar *ToolBar1;
    TToolButton *btnToggleDisplayStart;
    TToolButton *btnToggleDisplayRoomNumbers;
    TAction *actToggleRoomNumbers;
    TToolButton *btnToggleDisplayLocks;
    TAction *actToggleShowLocks;
    TToolButton *btnEditModeSingle;
    TAction *actEditModeSingleScreen;
    TAction *actToggleTileTypes;
    TToolButton *btnToggleTileTypes;
    TPanel *Panel1;
    TToolBar *ToolBar2;
    TToolButton *btnToggleSpriteLocks;
    TToolButton *btnSpriteType0;
    TToolBar *ToolBar3;
    TToolButton *btnSpriteType1;
    TToolButton *btnSpriteType2;
    TToolButton *btnSpriteType3;
    TToolButton *btnSpriteType4;
    TToolButton *btnSpriteType5;
    TToolButton *btnSpriteType6;
    TToolButton *btnSpriteType7;
    TToolButton *btnSpriteType8;
    TAction *actSpriteType0;
    TAction *actShowSpriteTypes;
    TAction *actSpriteType1;
    TAction *actSpriteType2;
    TAction *actSpriteType3;
    TAction *actSpriteType4;
    TAction *actSpriteType5;
    TAction *actSpriteType6;
    TAction *actSpriteType7;
    TAction *actSpriteType8;
    TToolButton *btnToggleSpriteTypes;
    TAction *actToggleSpriteLocks;
    void __fastcall actSelectExecute(TObject *Sender);
    void __fastcall actPencilExecute(TObject *Sender);
    void __fastcall actLineExecute(TObject *Sender);
    void __fastcall actRectExecute(TObject *Sender);
    void __fastcall actZoomInExecute(TObject *Sender);
    void __fastcall actZoomOutExecute(TObject *Sender);
    void __fastcall actZoomResetExecute(TObject *Sender);
    void __fastcall actUndoExecute(TObject *Sender);
    void __fastcall actRedoExecute(TObject *Sender);
    void __fastcall imgScratchPadMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall imgScratchPadMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall imgScratchPadMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall panWorkspaceViewResize(TObject *Sender);
    void __fastcall imgWorkspaceMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall imgWorkspaceMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall imgWorkspaceMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall dpToolsCloseQuery(TObject *Sender, bool &CanClose);
    void __fastcall panScratchPadViewResize(TObject *Sender);
    void __fastcall pgcAssetsResize(TObject *Sender);
    void __fastcall imgWorkspaceMouseActivate(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y, int HitTest, TMouseActivate &MouseActivate);
    void __fastcall imgWorkspaceMouseEnter(TObject *Sender);
    void __fastcall actCopyToScratchPadExecute(TObject *Sender);
    void __fastcall actMoveToScratchPadExecute(TObject *Sender);
    void __fastcall actCopyToWorkspaceExecute(TObject *Sender);
    void __fastcall actDuplicateExecute(TObject *Sender);
    void __fastcall actDeleteExecute(TObject *Sender);
    void __fastcall mnuWSToggleToolbarClick(TObject *Sender);
    void __fastcall mnuSPToggleToolbarClick(TObject *Sender);
    void __fastcall pgcAssetsChange(TObject *Sender);
    void __fastcall imgRoomSelectorMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall imgRoomSelectorMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
    void __fastcall imgRoomSelectorMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall btnWSGridRoomClick(TObject *Sender);
    void __fastcall btnWSGridTileClick(TObject *Sender);
    void __fastcall btnSPGridTileClick(TObject *Sender);
    void __fastcall actGridTileExecute(TObject *Sender);
    void __fastcall actGridRoomExecute(TObject *Sender);
    void __fastcall actEditModeFullMapExecute(TObject *Sender);
    void __fastcall actToggleStartRoomExecute(TObject *Sender);
    void __fastcall actEntityNextExecute(TObject *Sender);
    void __fastcall actEntityPrevExecute(TObject *Sender);
    void __fastcall sbxWorkspaceMouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta, TPoint &MousePos, bool &Handled);
    void __fastcall actCopyExecute(TObject *Sender);
    void __fastcall actCutExecute(TObject *Sender);
    void __fastcall actPasteExecute(TObject *Sender);
    void __fastcall actEntityToggleLocksExecute(TObject *Sender);
    void __fastcall actToggleRoomNumbersExecute(TObject *Sender);
    void __fastcall actToggleShowLocksExecute(TObject *Sender);
    void __fastcall actToggleTileTypesExecute(TObject *Sender);
    void __fastcall actSpriteType0Execute(TObject *Sender);
    void __fastcall actShowSpriteTypesExecute(TObject *Sender);

private:    // User declarations
    ::Messaging::Registrar      m_Registrar;        // the messaging registrar
    Project::TiledMapDocument*  m_Document;         // the map document we are editiing
    std::unique_ptr<TileEditor> m_Workspace;        // the main workspace editor
    std::unique_ptr<TileEditor> m_ScratchPad;       // the scratch pad editor
    std::unique_ptr<TileEditor> m_RoomSelector;     // the room selection editor
    std::map<String, TAction*>  m_ActionMap;        // a map of actions; used by generic messaging to handle zoom in/out/reset, undo/redo
    std::list<EraseHandler>     m_EraseHandlers;    // stops flicking
    TLMDDockPanel*              m_ActivePanel;      // the active dock panel
    Visuals::ImageMap           m_ImageMap;         // a rendering of each tile, object, sprite that is shared with all the editors
    int                         m_LastSelectedId;   // last selected document id
    int                         m_Scale;

            void                Initialise();
            void                RefreshAssets();
            bool                IsActive() const;
            void                OnEvent(const ::Messaging::Event& event);
            void                OnRoomSelected(const ::Messaging::RoomSelected& event);
            void                OnStartRoomChanged(const ::Messaging::StartRoomChanged& event);
            void                OnDocumentChanged(const ::Messaging::DocumentChange<String>& message);
            void                OnEntityClick(Project::ImageDocument* document);
            void                OnWorkspaceEntitySelected(const Project::MapEntity& entity);
            int                 OnRetrieveRoomIndex(const TPoint& pt, bool newIndex = false);
            void                ShowKeysHelp();

public:        // User declarations
                    __fastcall  TfrmEditorMap(TComponent* Owner);
                    __fastcall ~TfrmEditorMap();

    static  TFrame* __fastcall  Create(Project::Document* document, TComponent* owner)
                                {
                                    auto editor = new TfrmEditorMap(owner);
                                    editor->Document = dynamic_cast<Project::TiledMapDocument*>(document);
                                    document->DockPanel = dynamic_cast<TLMDDockPanel*>(owner);
                                    editor->Initialise();
                                    return editor;
                                }

  __property Project::Document* Document = { read = m_Document, write = m_Document };
};
//---------------------------------------------------------------------------
#endif
