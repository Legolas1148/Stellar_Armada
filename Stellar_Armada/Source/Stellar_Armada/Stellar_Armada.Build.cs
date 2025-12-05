// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Stellar_Armada : ModuleRules
{
	public Stellar_Armada(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"NavigationSystem",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"Niagara",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"Stellar_Armada",
			"Stellar_Armada/Variant_Strategy",
			"Stellar_Armada/Variant_Strategy/UI",
			"Stellar_Armada/Variant_TwinStick",
			"Stellar_Armada/Variant_TwinStick/AI",
			"Stellar_Armada/Variant_TwinStick/Gameplay",
			"Stellar_Armada/Variant_TwinStick/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
