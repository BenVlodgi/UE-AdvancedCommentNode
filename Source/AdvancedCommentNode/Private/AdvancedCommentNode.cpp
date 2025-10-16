// Copyright 2025 Dream Seed LLC

#include "AdvancedCommentNode.h"


#include "AdvancedCommentNodeFactory.h"
#include "AdvancedCommentNodePreferences.h"
#include "EdGraphUtilities.h"


#define LOCTEXT_NAMESPACE "FAdvancedCommentNodeModule"

void FAdvancedCommentNodeModule::StartupModule()
{
	bModuleIsRunning = true;
    UpdateEnabledStatus();
}

void FAdvancedCommentNodeModule::ShutdownModule()
{
    bModuleIsRunning = false;
    SetEnabled(false);
}

void FAdvancedCommentNodeModule::UpdateEnabledStatus()
{
    SetEnabled(bModuleIsRunning && UAdvancedCommentNodePreferences::Get()->bEnableAdvancedCommentNodes);
}
void FAdvancedCommentNodeModule::SetEnabled(bool bEnabled)
{
    if(bModuleIsEnabled == bEnabled)
	{
		return;
	}

	bModuleIsEnabled = bEnabled;

    if (bEnabled)
    {
        AdvancedCommentNodeFactory = MakeShareable(new FAdvancedCommentNodeFactory());
        FEdGraphUtilities::RegisterVisualNodeFactory(AdvancedCommentNodeFactory);
    }
    else
    {
        if (AdvancedCommentNodeFactory.IsValid())
        {
            FEdGraphUtilities::UnregisterVisualNodeFactory(AdvancedCommentNodeFactory);
            AdvancedCommentNodeFactory.Reset();
        }
    }
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAdvancedCommentNodeModule, AdvancedCommentNode)
