// Copyright 2025 Dream Seed LLC

#include "SGraphNodeAdvancedComment.h"


#include "AdvancedCommentNodePreferences.h"
#include "EdGraphNode_Comment.h"
#include "SGraphPanel.h"

void SGraphNodeAdvancedComment::Construct(const FArguments& InArgs, UEdGraphNode_Comment* InNode)
{
    SGraphNodeComment::Construct(SGraphNodeComment::FArguments(), InNode);
}

void SGraphNodeAdvancedComment::MoveTo(const FVector2f& NewPosition, FNodeSet& NodeFilter, bool bMarkDirty)
{
	FVector2f PositionDelta = NewPosition - GetPosition2f();
	SGraphNode::MoveTo(NewPosition, NodeFilter, bMarkDirty);

	UEdGraphNode_Comment* CommentNode = Cast<UEdGraphNode_Comment>(GraphNode);

	if (CommentNode && ShouldMoveAsGroup())
	{
		// Now update any nodes which are touching the comment but *not* selected
		// Selected nodes will be moved as part of the normal selection code
		TSharedPtr< SGraphPanel > Panel = GetOwnerPanel();

		for (FCommentNodeSet::TConstIterator NodeIt(CommentNode->GetNodesUnderComment()); NodeIt; ++NodeIt)
		{
			if (UEdGraphNode* Node = Cast<UEdGraphNode>(*NodeIt))
			{
				if (!Panel->SelectionManager.IsNodeSelected(Node) && !NodeFilter.Find(Node->DEPRECATED_NodeWidget.Pin()))
				{
					NodeFilter.Add(Node->DEPRECATED_NodeWidget.Pin());
					Node->Modify(bMarkDirty);
					Node->SetPosition(Node->GetPosition() + PositionDelta);
				}
			}
		}
	}
}

bool SGraphNodeAdvancedComment::ShouldMoveAsGroup()
{
	const UEdGraphNode_Comment* CommentNode = Cast<UEdGraphNode_Comment>(GraphNode);
	const UAdvancedCommentNodePreferences* Preferences = UAdvancedCommentNodePreferences::Get();
	const bool bShift = FSlateApplication::Get().GetModifierKeys().IsShiftDown();

	switch (Preferences->CommentNodesMoveBehavior)
	{
	case ECommentNodeMoveBehavior::AlwaysMoveContents:  return !bShift;
	case ECommentNodeMoveBehavior::NeverMoveContents: return bShift;
	case ECommentNodeMoveBehavior::UseNodeMoveMode: 
		return bShift
			? (Preferences->CommentNodesMoveShiftModifier == ECommentNodeMoveShiftModifier::ForceMoveGroup)
			: (CommentNode && CommentNode->MoveMode == ECommentBoxMode::GroupMovement);
	default: return !bShift; // Shouldn't happen
	}
}
