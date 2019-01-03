// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"


/**
 * 
 */
class IPropertyHandle;
class FDetailWidgetRow;

class FDamageTableCustomization : public IPropertyTypeCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance()
	{
		return MakeShared<FDamageTableCustomization>();
	}

	/**
	* Called when the header of the property (the row in the details panel where the property is shown)
	* If nothing is added to the row, the header is not displayed
	*
	* @param PropertyHandle			Handle to the property being customized
	* @param HeaderRow					A row that widgets can be added to
	* @param StructCustomizationUtils	Utilities for customization
	*/
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	/**
	* Called when the children of the property should be customized or extra rows added
	*
	* @param PropertyHandle			Handle to the property being customized
	* @param StructBuilder				A builder for adding children
	* @param StructCustomizationUtils	Utilities for customization
	*/
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

private:
	TSharedPtr<IPropertyHandle> HeadHandle;
	TSharedPtr<IPropertyHandle> NeckHandle;
	TSharedPtr<IPropertyHandle> ChestHandle;
	TSharedPtr<IPropertyHandle> UpperArmHandle;
	TSharedPtr<IPropertyHandle> StomachHandle;
	TSharedPtr<IPropertyHandle> OthersHandle;
};
