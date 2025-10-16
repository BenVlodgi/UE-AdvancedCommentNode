// Copyright 2025 Dream Seed LLC

using UnrealBuildTool;

public class AdvancedCommentNode : ModuleRules
{
    public AdvancedCommentNode(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[]
            {
                "Core",
            });

        PrivateDependencyModuleNames.AddRange(new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UnrealEd",
                "GraphEditor",
                "DeveloperSettings",
                "RigVMDeveloper"
            });
    }
}
