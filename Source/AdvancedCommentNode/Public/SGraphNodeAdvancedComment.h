// Copyright 2025 Dream Seed LLC

#pragma once

#include "CoreMinimal.h"
#include "SGraphNodeComment.h"


class SGraphNodeAdvancedComment : public SGraphNodeComment
{
public:
    SLATE_BEGIN_ARGS(SGraphNodeAdvancedComment) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UEdGraphNode_Comment* InNode);

    virtual void MoveTo(const FVector2f& NewPosition, FNodeSet& NodeFilter, bool bMarkDirty) override;

    virtual bool ShouldMoveAsGroup();
};
