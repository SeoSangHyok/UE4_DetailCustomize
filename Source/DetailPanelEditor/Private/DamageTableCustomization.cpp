// Fill out your copyright notice in the Description page of Project Settings.

#include "DamageTableCustomization.h"
#include "PropertyHandle.h"
#include "DetailWidgetRow.h"
#include "DetailLayoutBuilder.h"
#include "SlateExtras.h"
#include "DetailPanelEditor.h"
#include "SConstraintCanvas.h"

void FDamageTableCustomization::CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)
{
	uint32 NumChildren;
	PropertyHandle->GetNumChildren(NumChildren);
	for (uint32 ChildIndex = 0 ; ChildIndex < NumChildren ; ++ChildIndex)
	{
		const TSharedRef<IPropertyHandle> ChildHandle = PropertyHandle->GetChildHandle(ChildIndex).ToSharedRef();

		const FString PropertyName = ChildHandle->GetProperty()->GetName();
		if (PropertyName == TEXT("Head"))
		{
			HeadHandle = ChildHandle;
		}
		else if (PropertyName == TEXT("Neck"))
		{
			NeckHandle = ChildHandle;
		}
		else if (PropertyName == TEXT("Chest"))
		{
			ChestHandle = ChildHandle;
		}
		else if (PropertyName == TEXT("UpperArm"))
		{
			UpperArmHandle = ChildHandle;
		}
		else if (PropertyName == TEXT("Stomach"))
		{
			StomachHandle = ChildHandle;
		}
		else if (PropertyName == TEXT("Others"))
		{
			OthersHandle = ChildHandle;
		}
	}

	check(HeadHandle.IsValid() && NeckHandle.IsValid() && ChestHandle.IsValid() && UpperArmHandle.IsValid() && StomachHandle.IsValid() && OthersHandle.IsValid());

	HeaderRow.NameContent()
	[
		PropertyHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.MinDesiredWidth(350.0f)
	[
		SNew(SBox)
		.WidthOverride(350.0f)
		.HeightOverride(450.0f)
		[
			SNew(SBorder)
			.BorderImage(FDetailPanelEditor::DamageTableImage)
			.Padding(FMargin(0.0f))
			[
				SNew(SConstraintCanvas)
				+ SConstraintCanvas::Slot()
				.Anchors(FAnchors(260.0f/350.0f, 0.0f, 330.0f/350.0f, 0.0f))
				.Offset(FMargin(0.0f, 30.0f, 0.0f, 205.0f))
				.Alignment(FVector2D(0.f, 0.f))
				[
					SNew(SVerticalBox)
					// Head
					+ SVerticalBox::Slot()
					[
						HeadHandle->CreatePropertyValueWidget()
					].Padding(FMargin(0.0f,0.0f,0.0f,5.0f))
					// Neck
					+ SVerticalBox::Slot()
					[
						NeckHandle->CreatePropertyValueWidget()
					].Padding(FMargin(0.0f, 0.0f, 0.0f, 5.0f))
					// Chest
					+ SVerticalBox::Slot()
					[
						ChestHandle->CreatePropertyValueWidget()
					].Padding(FMargin(0.0f, 0.0f, 0.0f, 5.0f))
					// UpperArm
					+ SVerticalBox::Slot()
					[
						UpperArmHandle->CreatePropertyValueWidget()
					].Padding(FMargin(0.0f, 0.0f, 0.0f, 5.0f))
					// Stomach
					+ SVerticalBox::Slot()
					[
						StomachHandle->CreatePropertyValueWidget()
					].Padding(FMargin(0.0f, 0.0f, 0.0f, 5.0f))
					// Others
					+ SVerticalBox::Slot()
					[
						OthersHandle->CreatePropertyValueWidget()
					]
				]
			]
		]
	];

}

void FDamageTableCustomization::CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils)
{

}