// Copyright 2025 Dream Seed LLC

#include "AdvancedCommentNodeFactory.h"


#include "SGraphNodeAdvancedComment.h"
#include "EdGraphNode_Comment.h"

TSharedPtr<SGraphNode> FAdvancedCommentNodeFactory::CreateNode(UEdGraphNode* Node) const
{
    if (UEdGraphNode_Comment* CommentNode = Cast<UEdGraphNode_Comment>(Node))
    {
        return SNew(SGraphNodeAdvancedComment, CommentNode);
    }
    return nullptr;
}
