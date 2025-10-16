// Copyright 2025 Dream Seed LLC

#include "AdvancedCommentNodePreferences.h"


#include "AdvancedCommentNode.h"

UAdvancedCommentNodePreferences::UAdvancedCommentNodePreferences()
{
    CategoryName = TEXT("ContentEditors");
    SectionName = TEXT("GraphEditors");
}

#if WITH_EDITOR
void UAdvancedCommentNodePreferences::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    if (PropertyChangedEvent.Property &&
        PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UAdvancedCommentNodePreferences, bEnableAdvancedCommentNodes))
    {
        if (FAdvancedCommentNodeModule* Module = FModuleManager::GetModulePtr<FAdvancedCommentNodeModule>("AdvancedCommentNode"))
        {
            Module->UpdateEnabledStatus();
        }
    }
}
#endif // WITH_EDITOR
