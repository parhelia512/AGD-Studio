//---------------------------------------------------------------------------
#ifndef ProjectManagerH
#define ProjectManagerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <memory>
#include "ElXTree.hpp"
//---------------------------------------------------------------------------
#include <list>
//---------------------------------------------------------------------------
#include "Project/DocumentManager.h"
#include "Project/MostRecentlyUsedList.h"
//---------------------------------------------------------------------------
class ProjectManager
{
public: // singleton
    static ProjectManager& get();
    ProjectManager(ProjectManager const&) = delete;
    void operator=(ProjectManager const&) = delete;

private:

    std::unique_ptr<MostRecentlyUsedList>   m_MostRecentUsedList;

    enum TreeviewIcons { tiProject,
                         tiFolderClosed, tiFolderOpened,
                         tiFolderFile, tiFolderSprites, tiFolderMusic, tiFolderSfx, tiFolderPatterns, tiFolderTileSets, tiFolderMaps, tiFolderImages,
                         tiBuild, tiConfiguration,
                         tiFileC, tiFileH, tiFileAsm,
                         tiAssetSprite, tiAssetMusic, tiAssetSfx, tiAssetPattern, tiAssetTile, tiAssetMap, tiAssetImage,
                         tiWindow, tiKeyboard, tiText, tiFileAgd, tiFileFont
                       };

    std::map<String, TElXTreeItem*> m_TreeLeafNodes;
    Elxtree::TElXTree*              m_TreeView;
    bool                            m_IsOpen;

    void        __fastcall  SetTreeIcon(const String& parent, TElXTreeItem* node) const;

protected:
                  friend    DocumentManager;
    void        __fastcall  OnDocumentChange(Document* doc);
    void        __fastcall  ClearTree(const String& rootName);
    Document*   __fastcall  AddToTreeView(Document* document);

public:

                __fastcall  ProjectManager();

    void        __fastcall  Initialise(Elxtree::TElXTree* treeView);
    void        __fastcall  New(const String& name, const String& machine);
    void        __fastcall  Open(const String& file);
    void        __fastcall  Close();
    void        __fastcall  Save();

    Document*   __fastcall  Add(const String& type, const String& subType, const String& name, const String& extra);
    Document*   __fastcall  Add(const String& type, const String& subType, const String& extra);
    bool        __fastcall  Remove(const String& type, const String& name);

    void        __fastcall  RemoveMostRecentlyUsedItem(const String& name, const String& path);
    cMRUList    __fastcall  GetMostRecentlyUsedList();
};
//---------------------------------------------------------------------------
#define theProjectManager ProjectManager::get()
//---------------------------------------------------------------------------
#endif
