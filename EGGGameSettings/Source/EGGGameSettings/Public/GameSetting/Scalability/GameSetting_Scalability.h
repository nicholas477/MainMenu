// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSetting/GameSettingValueDiscrete.h"
#include "GameSetting_Scalability.generated.h"

/**
 * One of the scalability settings
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class EGGGAMESETTINGS_API UGameSetting_Scalability : public UGameSettingValueDiscrete
{ 
	GENERATED_BODY()
	
public:
	UGameSetting_Scalability();

	/** Begin UGameSettingValue interface */
	/** Stores an initial value for the setting.  This will be called on initialize, but should also be called if you 'apply' the setting. */
	virtual void StoreInitial() {}
	/** Resets the property to the default. */
	virtual void ResetToDefault() {}
	/** Restores the setting to the initial value, this is the value when you open the settings before making any tweaks. */
	virtual void RestoreToInitial() {}
	/** End UGameSettingValue interface */

	/** Begin UGameSettingValueDiscrete interface */
	virtual void SetDiscreteOptionByIndex(int32 Index) override;
	virtual int32 GetDiscreteOptionIndex() const override;
	virtual TArray<FText> GetDiscreteOptions() const override;
	/** End UGameSettingValueDiscrete interface */

	/** Begin UGameSetting interface */
	virtual void OnApply() override;
	/** End UGameSetting interface */

protected:
	// This function is called on UGameUserSetting by SetDiscreteOptionByIndex
	// The function has to have the signature "void SetOption(int32 Option)"
	UPROPERTY(EditAnywhere)
	FName GameUserSettingSetterFunctionName;

	// This function is called on UGameUserSetting by GetDiscreteOptionIndex
	// The function has to have the signature "int32 GetOption()"
	UPROPERTY(EditAnywhere)
	FName GameUserSettingGetterFunctionName;
};
