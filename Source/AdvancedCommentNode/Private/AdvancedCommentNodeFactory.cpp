// Copyright 2025 Dream Seed LLC

#include "AdvancedCommentNodeFactory.h"


#include "SGraphNodeAdvancedComment.h"
#include "EdGraphNode_Comment.h"
#include "RigVMModel/RigVMGraph.h"

TSharedPtr<SGraphNode> FAdvancedCommentNodeFactory::CreateNode(UEdGraphNode* Node) const
{
    // TODO: Support RigVM/Control-Rig graphs later
    if (URigVMGraph* RigGraph = Cast<URigVMGraph>(Node->GetGraph()))
    {
        return nullptr;
    }

    // Normal Blueprint/Anim/Material comment nodes
    if (UEdGraphNode_Comment* CommentNode = Cast<UEdGraphNode_Comment>(Node))
    {
        return SNew(SGraphNodeAdvancedComment, CommentNode);
    }

    return nullptr;
}
