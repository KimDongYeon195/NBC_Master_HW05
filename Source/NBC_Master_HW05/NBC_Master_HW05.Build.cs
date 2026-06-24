// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class NBC_Master_HW05 : ModuleRules
{
	public NBC_Master_HW05(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", "CoreUObject", "Engine", 
			"InputCore", "EnhancedInput",
			"UMG"
		}
		);

       
    }
}
