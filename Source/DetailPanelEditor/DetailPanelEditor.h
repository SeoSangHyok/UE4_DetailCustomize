// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class FDetailPanelEditor : public IModuleInterface
{
public:
	/**
	* Called right after the module DLL has been loaded and the module object has been created
	* Load dependent modules here, and they will be guaranteed to be available during ShutdownModule. ie:
	*
	* FModuleManager::Get().LoadModuleChecked(TEXT("HTTP"));
	*/
	virtual void StartupModule() override;

	/**
	* Called before the module is unloaded, right before the module object is destroyed.
	* During normal shutdown, this is called in reverse order that modules finish StartupModule().
	* This means that, as long as a module references dependent modules in it's StartupModule(), it
	* can safely reference those dependencies in ShutdownModule() as well.
	*/
	virtual void ShutdownModule() override;

	/**
	* Override this to set whether your module is allowed to be unloaded on the fly
	*
	* @return	Whether the module supports shutdown separate from the rest of the engine.
	*/
	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}

	static	FSlateDynamicImageBrush* DamageTableImage;
};
