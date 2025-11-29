// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSetting/GameSettingValueDiscrete.h"
#include "GameSetting_AntiAliasingMethod.generated.h"

/**
 * 
 */
UCLASS(config = GameUserSettings)
class EGGGAMESETTINGS_API UGameSetting_AntiAliasingMethod : public UGameSettingValueDiscrete
{
	GENERATED_BODY()

public:
	UGameSetting_AntiAliasingMethod();
	
	virtual void SetDiscreteOptionByIndex(int32 Index) override;
	virtual int32 GetDiscreteOptionIndex() const override;
	virtual TArray<FText> GetDiscreteOptions() const override;

	/** Begin UGameSettingValue interface */
	/** Stores an initial value for the setting.  This will be called on initialize, but should also be called if you 'apply' the setting. */
	virtual void StoreInitial() {}
	/** Resets the property to the default. */
	virtual void ResetToDefault() {}
	/** Restores the setting to the initial value, this is the value when you open the settings before making any tweaks. */
	virtual void RestoreToInitial() {}
	/** End UGameSettingValue interface */

	virtual void Startup() override;
	virtual void OnApply() override;
	virtual void OnSave() override;

protected:
	// -1 means unset
	UPROPERTY(Config)
	int32 AntiAliasingMethod;
};
