// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "GameSetting/GameSettingValue.h"
#include "GameSettingValueScalar.generated.h"

/**
 * 
 */
UCLASS()
class EGGGAMESETTINGS_API UGameSettingValueScalar : public UGameSettingValue
{
	GENERATED_BODY()
	
public:
	UGameSettingValueScalar();

	UFUNCTION(BlueprintCallable)
	void SetValueNormalized(double NormalizedValue);

	UFUNCTION(BlueprintPure)
	double GetValueNormalized() const;

	UFUNCTION(BlueprintPure)
	TOptional<double> GetDefaultValueNormalized() const
	{
		TOptional<double> DefaultValue = GetDefaultValue();
		if (DefaultValue.IsSet())
		{
			return FMath::GetMappedRangeValueClamped(GetSourceRange(), TRange<double>(0, 1), DefaultValue.GetValue());
		}
		return TOptional<double>();
	}

	UFUNCTION(BlueprintPure)
	virtual TOptional<double> GetDefaultValue() const						PURE_VIRTUAL(, return TOptional<double>(););

	UFUNCTION(BlueprintCallable)
	virtual void SetValue(double Value, EGameSettingChangeReason Reason = EGameSettingChangeReason::Change)	PURE_VIRTUAL(, );

	UFUNCTION(BlueprintPure)
	virtual double GetValue() const											PURE_VIRTUAL(, return 0;);

	UFUNCTION(BlueprintPure)
	virtual FDoubleRange GetSourceRange() const							PURE_VIRTUAL(, return FDoubleRange(););

	UFUNCTION(BlueprintPure)
	virtual double GetSourceStep() const									PURE_VIRTUAL(, return 0.01;);

	UFUNCTION(BlueprintPure)
	double GetNormalizedStepSize() const
	{
		FDoubleRange SourceRange = GetSourceRange();
		return GetSourceStep() / FMath::Abs(SourceRange.GetUpperBoundValue() - SourceRange.GetLowerBoundValue());
	}

	UFUNCTION(BlueprintPure)
	virtual FText GetFormattedText() const									PURE_VIRTUAL(, return FText::GetEmpty(););
};
