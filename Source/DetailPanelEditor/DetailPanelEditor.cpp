// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DetailPanelEditor.h"
#include "Modules/ModuleManager.h"
#include "private/DamageTableCustomization.h"
#include "PropertyEditorModule.h"
#include "SlateDynamicImageBrush.h"

IMPLEMENT_MODULE(FDetailPanelEditor, DetailPanelEditor);

FSlateDynamicImageBrush* FDetailPanelEditor::DamageTableImage = nullptr;

void FDetailPanelEditor::StartupModule()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyEditorModule.RegisterCustomPropertyTypeLayout("DamagetTable", FOnGetPropertyTypeCustomizationInstance::CreateStatic(&FDamageTableCustomization::MakeInstance));

	FString ImagePath = FPaths::GameSourceDir() / TEXT("DetailPanelEditor/Resource/DamageTableImage.png");
	DamageTableImage = new FSlateDynamicImageBrush(*ImagePath, FVector2D( 350.0f, 450.0f));
}

void FDetailPanelEditor::ShutdownModule()
{
	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	PropertyEditorModule.UnregisterCustomPropertyTypeLayout("DamagetTable");
}