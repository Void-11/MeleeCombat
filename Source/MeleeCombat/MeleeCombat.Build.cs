// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class MeleeCombat : ModuleRules
{
	public MeleeCombat(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] { "AnimGraphRuntime", "AnimGraphRuntime" });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "AIModule" });
	}
}
