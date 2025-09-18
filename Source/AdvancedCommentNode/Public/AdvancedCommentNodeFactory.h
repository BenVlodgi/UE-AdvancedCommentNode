// Copyright 2025 Dream Seed LLC

#pragma once

#include "CoreMinimal.h"
#include "EdGraphUtilities.h"


class FAdvancedCommentNodeFactory: public FGraphPanelNodeFactory
{
public:
    virtual TSharedPtr<SGraphNode> CreateNode(UEdGraphNode* Node) const override;
};
