// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Console/GameSetting_AntiAliasingMethod.h"

#define LOCTEXT_NAMESPACE "GameSetting"

UGameSetting_AntiAliasingMethod::UGameSetting_AntiAliasingMethod()
{
	DisplayName = LOCTEXT("AntiAliasingMethod", "Anti Aliasing Method");

	AntiAliasingMethod = -1;
}

void UGameSetting_AntiAliasingMethod::SetDiscreteOptionByIndex(int32 Index)
{
    AntiAliasingMethod = Index;
    NotifySettingChanged(EGameSettingChangeReason::Change);
}

int32 UGameSetting_AntiAliasingMethod::GetDiscreteOptionIndex() const
{
    if (AntiAliasingMethod == -1)
    {
        const int32 AACVar = IConsoleManager::Get().FindTConsoleVariableDataInt(TEXT("r.AntiAliasingMethod"))->GetValueOnGameThread();
        switch (AACVar)
        {
        case 4:
            return 3;
        default:
            return AACVar;
        }
    }
    else
    {
        return AntiAliasingMethod;
    }
}

TArray<FText> UGameSetting_AntiAliasingMethod::GetDiscreteOptions() const
{
    return {
        LOCTEXT("AntiAliasing0",    "None")
    ,   LOCTEXT("AntiAliasing1",    "FXAA")
    ,   LOCTEXT("AntiAliasing2",    "TAA")
    ,   LOCTEXT("AntiAliasing4",    "TSR")
    };
}

void UGameSetting_AntiAliasingMethod::Startup()
{
    LoadConfig(nullptr, *GGameUserSettingsIni);
    Apply();
}

void UGameSetting_AntiAliasingMethod::OnApply()
{
    if (AntiAliasingMethod < 0)
    {
        return;
    }

    switch (AntiAliasingMethod)
    {
    case 3:
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.AntiAliasingMethod"))->Set(4);
        break;

    default:
        IConsoleManager::Get().FindConsoleVariable(TEXT("r.AntiAliasingMethod"))->Set(AntiAliasingMethod);
        break;
    }

    Save();
}

void UGameSetting_AntiAliasingMethod::OnSave()
{
    SaveConfig(CPF_Config, *GGameUserSettingsIni);
}

#undef LOCTEXT_NAMESPACE
