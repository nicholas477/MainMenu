// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/GameSettingValueScalar.h"

UGameSettingValueScalar::UGameSettingValueScalar()
{

}


void UGameSettingValueScalar::SetValueNormalized(double NormalizedValue)
{
	SetValue(FMath::GetMappedRangeValueClamped(TRange<double>(0, 1), GetSourceRange(), NormalizedValue));
}

double UGameSettingValueScalar::GetValueNormalized() const
{
	return FMath::GetMappedRangeValueClamped(GetSourceRange(), TRange<double>(0, 1), GetValue());
}
