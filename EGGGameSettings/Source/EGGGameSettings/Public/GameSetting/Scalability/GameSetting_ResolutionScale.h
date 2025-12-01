// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameSetting/GameSettingValueScalar.h"
#include "GameSetting_ResolutionScale.generated.h"

/**
 * 
 */
UCLASS()
class EGGGAMESETTINGS_API UGameSetting_ResolutionScale : public UGameSettingValueScalar
{
	GENERATED_BODY()
	
public:
	UGameSetting_ResolutionScale();

	virtual TOptional<double> GetDefaultValue() const override;
	virtual void SetValue(double Value, EGameSettingChangeReason Reason = EGameSettingChangeReason::Change)	override;
	virtual double GetValue() const override;
	virtual FDoubleRange GetSourceRange() const override;
	virtual double GetSourceStep() const override;
	virtual FText GetFormattedText() const override;

protected:
	virtual void OnApply() override;
};
