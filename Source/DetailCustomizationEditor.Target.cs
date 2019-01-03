// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DetailCustomizationEditorTarget : TargetRules
{
	public DetailCustomizationEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("DetailCustomization");
        ExtraModuleNames.Add("DetailPanelEditor");
    }
}
