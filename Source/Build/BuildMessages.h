//---------------------------------------------------------------------------
#ifndef BuildMessagesH
#define BuildMessagesH
//---------------------------------------------------------------------------
#include <ElXTree.hpp>
//---------------------------------------------------------------------------
namespace Build
{
//---------------------------------------------------------------------------
enum BuildMessageType { bmOk = 0, bmFailed, bmChecking, bmBuild, bmRun, bmProgress, bmTiming, bmCopy, bmInfo, bmOutput, bmWarning };
//---------------------------------------------------------------------------
class BuildMessages
{
private:
    TElXTree*                   m_TreeView;
    TElXTreeItem*               m_GroupNode;
    TElXTreeItem*               m_MsgNode;
    BuildMessageType            m_GroupType;

public:
                     BuildMessages();
    virtual         ~BuildMessages();

                                // clear the tree view
        void         Clear();
                                // push a new group/folder node
        void         Push(BuildMessageType type, const String& group);
                                // pop the last node
        void         Pop(bool result);
                                // post a message in the current group node
        void         Message(BuildMessageType type, const String& message);
                                // post a message in the current group node
        void         Message(const String& message);
                                // update the last message with a success/fail icon
        void         Message(BuildMessageType type);
                                // log a build time
        void         Time(int time);

    __property  TElXTree*       TreeView = { write = m_TreeView };
};
//---------------------------------------------------------------------------
#define BUILD_MSG_CLEAR m_BuildMessages.Clear()
#define BUILD_MSG_PUSH(type, group) m_BuildMessages.Push(type, group)
#define BUILD_MSG(a) m_BuildMessages.Message(a)
#define BUILD_LINE(a, b) m_BuildMessages.Message(a, b)
#define BUILD_MSG_POP(result) m_BuildMessages.Pop(result)
#define BUILD_TIME(time) m_BuildMessages.Time(time)
//---------------------------------------------------------------------------
} // Build namespace
//---------------------------------------------------------------------------
#endif
