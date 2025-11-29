// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSetting/GameSetting.h"
#include "GameSettingCollection.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class EGGGAMESETTINGS_API UGameSettingCollection : public UGameSetting
{
	GENERATED_BODY()
	
public:
	virtual TArray<UGameSetting*> GetChildSettings() override { return Settings; }
	TArray<UGameSettingCollection*> GetChildCollections() const;

	void AddSetting(UGameSetting* Setting);
	//virtual void GetSettingsForFilter(const FGameSettingFilterState& FilterState, TArray<UGameSetting*>& InOutSettings) const;

	//virtual bool IsSelectable() const { return false; }

protected:
	/** The settings owned by this collection. */
	UPROPERTY(EditAnywhere, Instanced)
	TArray<UGameSetting*> Settings;
};
