// Copyright 2025 Dream Seed LLC

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"


#include "AdvancedCommentNodePreferences.generated.h"

UENUM()
enum class ECommentNodeMoveBehavior : uint8
{
    /** Comment node will move how the node is configured (Default). Holding Shift will force content movement as configured. */
    UseNodeMoveMode UMETA(DisplayName = "Use Node's Move Mode"),

    /** Always move contents with the comment. Holding Shift Inverts the behavior. */
    AlwaysMoveContents UMETA(DisplayName = "Always Move Contents"),

    /** Never move contents, comment box only. Holding Shift Inverts the behavior. */
    NeverMoveContents UMETA(DisplayName = "Never Move Contents")
};

UENUM()
enum class ECommentNodeMoveShiftModifier : uint8
{
    /** Holding Shift will force the comment to move by itself, leaving all contained nodes behind. (Default). */
    ForceMoveContents UMETA(DisplayName = "Force Move Contents"),

    /** Holding Shift will force the comment and all its contained nodes to move together as a group. */
    ForceMoveGroup UMETA(DisplayName = "Force Move Group")
};


UCLASS(config = EditorPerProjectUserSettings, meta = (DisplayName = "Graph Editors"))
class ADVANCEDCOMMENTNODE_API UAdvancedCommentNodePreferences : public UDeveloperSettings
{
	GENERATED_BODY()

public:
    // Enable the functionality of this plugin.
    UPROPERTY(config, EditAnywhere, Category = CommentNodes)
    bool bEnableAdvancedCommentNodes = true;

	// How moving comment nodes should affect their contents.
    UPROPERTY(config, EditAnywhere, Category = CommentNodes)
    ECommentNodeMoveBehavior CommentNodesMoveBehavior = ECommentNodeMoveBehavior::UseNodeMoveMode;

    // How moving comment nodes should affect their contents when using NodeMoveMode, otherwise Shift will Invert the current override.
    UPROPERTY(config, EditAnywhere, Category = CommentNodes, meta = (EditConditionHides = "true", EditCondition = "CommentNodesMoveBehavior == ECommentNodeMoveBehavior::UseNodeMoveMode"))
    ECommentNodeMoveShiftModifier CommentNodesMoveShiftModifier = ECommentNodeMoveShiftModifier::ForceMoveContents;

    UAdvancedCommentNodePreferences();

    static FORCEINLINE UAdvancedCommentNodePreferences* Get()
    {
        UAdvancedCommentNodePreferences* Settings = GetMutableDefault<UAdvancedCommentNodePreferences>();
        check(Settings);

        return Settings;
    }

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

};
