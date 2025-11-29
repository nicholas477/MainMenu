// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Scalability.h"

#include "GameFramework/GameUserSettings.h"

#define LOCTEXT_NAMESPACE "GameSetting"

UGameSetting_Scalability::UGameSetting_Scalability()
{
    GameUserSettingSetterFunctionName = FName();
    GameUserSettingGetterFunctionName = FName();
}

void UGameSetting_Scalability::SetDiscreteOptionByIndex(int32 Index)
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        UFunction* SetterFunction = UserSettings->FindFunction(GameUserSettingSetterFunctionName);
        if (SetterFunction)
        {
            ensure(SetterFunction->IsSignatureCompatibleWith(FindFunction("SetDiscreteOptionByIndex")));
            if (!SetterFunction->IsSignatureCompatibleWith(FindFunction("SetDiscreteOptionByIndex")))
            {
                return;
            }

            UserSettings->ProcessEvent(SetterFunction, &Index);
            NotifySettingChanged(EGameSettingChangeReason::Change);
        }
    }
}

int32 UGameSetting_Scalability::GetDiscreteOptionIndex() const
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        UFunction* GetterFunction = UserSettings->FindFunction(GameUserSettingGetterFunctionName);
        if (GetterFunction)
        {
            ensure(GetterFunction->IsSignatureCompatibleWith(FindFunction("GetDiscreteOptionIndex")));
            if (!GetterFunction->IsSignatureCompatibleWith(FindFunction("GetDiscreteOptionIndex")))
            {
                return INDEX_NONE;
            }

            struct FFunctionParams
            {
                int32 ReturnValue;
            } Params;
            UserSettings->ProcessEvent(GetterFunction, &Params);
            return Params.ReturnValue;
        }
    }

    return INDEX_NONE;
}

TArray<FText> UGameSetting_Scalability::GetDiscreteOptions() const
{
    return {
        LOCTEXT("ScalabilityLow",       "Low")
    ,   LOCTEXT("ScalabilityMedium",    "Medium")
    ,   LOCTEXT("ScalabilityHigh",      "High")
    ,   LOCTEXT("ScalabilityEpic",      "Max")
    };
}

void UGameSetting_Scalability::OnApply()
{
    UGameUserSettings* UserSettings = GEngine->GetGameUserSettings();
    if (ensure(UserSettings))
    {
        UserSettings->ApplySettings(false);
    }
}

#undef LOCTEXT_NAMESPACE
