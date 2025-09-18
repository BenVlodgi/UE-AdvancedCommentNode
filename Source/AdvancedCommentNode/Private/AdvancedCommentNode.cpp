// Copyright 2025 Dream Seed LLC

#include "AdvancedCommentNode.h"


#include "AdvancedCommentNodeFactory.h"
#include "EdGraphUtilities.h"

#define LOCTEXT_NAMESPACE "FAdvancedCommentNodeModule"

void FAdvancedCommentNodeModule::StartupModule()
{
    AdvancedCommentNodeFactory = MakeShareable(new FAdvancedCommentNodeFactory());
    FEdGraphUtilities::RegisterVisualNodeFactory(AdvancedCommentNodeFactory);
}

void FAdvancedCommentNodeModule::ShutdownModule()
{
    if (AdvancedCommentNodeFactory.IsValid())
    {
        FEdGraphUtilities::UnregisterVisualNodeFactory(AdvancedCommentNodeFactory);
        AdvancedCommentNodeFactory.Reset();
    }
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAdvancedCommentNodeModule, AdvancedCommentNode)
