// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSetting/GameSettingValue.h"
#include "GameSettingValueDiscrete.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType)
class EGGGAMESETTINGS_API UGameSettingValueDiscrete : public UGameSettingValue
{
	GENERATED_BODY()
	
public:
	/** UGameSettingValueDiscrete */
	UFUNCTION(BlueprintCallable)
	virtual void SetDiscreteOptionByIndex(int32 Index) PURE_VIRTUAL(, );

	UFUNCTION(BlueprintCallable)
	virtual int32 GetDiscreteOptionIndex() const PURE_VIRTUAL(, return INDEX_NONE;);

	/** Optional */
	UFUNCTION(BlueprintCallable)
	virtual int32 GetDiscreteOptionDefaultIndex() const { return INDEX_NONE; }

	UFUNCTION(BlueprintCallable)
	virtual TArray<FText> GetDiscreteOptions() const PURE_VIRTUAL(, return TArray<FText>(););

};
