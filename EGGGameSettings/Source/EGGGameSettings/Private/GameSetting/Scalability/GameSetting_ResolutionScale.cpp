// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_ResolutionScale.h"

#include "GameFramework/GameUserSettings.h"
#include "Misc/Optional.h"

UGameSetting_ResolutionScale::UGameSetting_ResolutionScale()
{
    DisplayName = NSLOCTEXT("GameSetting", "ResolutionQuality", "Resolution Scale");
}

TOptional<double> UGameSetting_ResolutionScale::GetDefaultValue() const
{
    return TOptional<double>(100.0);
}

void UGameSetting_ResolutionScale::SetValue(double Value, EGameSettingChangeReason Reason)
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        UserSettings->SetResolutionScaleValueEx(Value);
    }
}

double UGameSetting_ResolutionScale::GetValue() const
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        float Normalized, Value, Min, Max;
        UserSettings->GetResolutionScaleInformationEx(Normalized, Value, Min, Max);
        return Value;
    }
    return -1.0;
}

FDoubleRange UGameSetting_ResolutionScale::GetSourceRange() const
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        float Normalized, Value, Min, Max;
        UserSettings->GetResolutionScaleInformationEx(Normalized, Value, Min, Max);
        return FDoubleRange(Min, Max);
    }
    return FDoubleRange();
}

double UGameSetting_ResolutionScale::GetSourceStep() const
{
    return 5.0;
}

FText UGameSetting_ResolutionScale::GetFormattedText() const
{
    FNumberFormattingOptions NumberFormatOptions;
    NumberFormatOptions.AlwaysSign = false;
    NumberFormatOptions.UseGrouping = false;
    NumberFormatOptions.RoundingMode = ERoundingMode::ToPositiveInfinity;
    NumberFormatOptions.MinimumIntegralDigits = 0;
    NumberFormatOptions.MaximumIntegralDigits = 324;
    NumberFormatOptions.MinimumFractionalDigits = 0;
    NumberFormatOptions.MaximumFractionalDigits = 0;

    return FText::AsNumber(GetValue(), &NumberFormatOptions);
}

void UGameSetting_ResolutionScale::OnApply()
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        UserSettings->ApplySettings(false);
    }
}
