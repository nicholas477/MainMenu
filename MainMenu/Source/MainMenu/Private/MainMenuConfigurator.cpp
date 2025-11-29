// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuConfigurator.h"

#include "MainMenuSettings.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Blueprint/UserWidget.h"
#include "GameSetting/GameSetting.h"

UE_DISABLE_OPTIMIZATION

#define LOCTEXT_NAMESPACE "MainMenu"

#define LOOKUP_WITH_DEFAULT(PropertyName) \
    LookupConfigurationWithDefault<decltype(PropertyName)>(GET_MEMBER_NAME_CHECKED(ThisClass, PropertyName))

template<typename T>
T UMainMenuConfigurator::LookupConfigurationWithDefault(FName PropertyName) const
{
    FProperty* Property = FindFProperty<FProperty>(UMainMenuConfigurator::StaticClass(), PropertyName);
    check(Property != nullptr);

    if (Property)
    {
        if (const T* WhateverValuePtr = Property->ContainerPtrToValuePtr<T>(this))
        {
            if (*WhateverValuePtr)
            {
                return *WhateverValuePtr;
            }
        }
        
        if (GetClass() != UMainMenuConfigurator::StaticClass())
        {
            const ThisClass* DefaultConfigurator = UMainMenuSettings::GetDefaultMainMenuConfigurator();
            if (const T* ValuePtr = DefaultConfigurator ? Property->ContainerPtrToValuePtr<T>(DefaultConfigurator) : nullptr)
            {
                return *ValuePtr;
            }
        }
    }

    return T();
}

UMainMenuConfigurator::UMainMenuConfigurator()
{
    FMemberReference NewGameFunctionReference;
    NewGameFunctionReference.SetSelfMember("OnNewGameClicked");

    FMemberReference OptionsFunctionReference;
    OptionsFunctionReference.SetSelfMember("OnOptionsClicked");

    FMemberReference QuitFunctionReference;
    QuitFunctionReference.SetSelfMember("OnQuitGameClicked");

    MainMenuEntries = {
        FMainMenuEntry{
            LOCTEXT("NewGameText", "New Game"),
            NewGameFunctionReference
        },
        FMainMenuEntry{
            LOCTEXT("OptionsText", "Options"),
            OptionsFunctionReference
        },
        FMainMenuEntry{
            LOCTEXT("QuitGameText", "Quit"),
            QuitFunctionReference
        }
    };
}

TSubclassOf<UUserWidget> UMainMenuConfigurator::GetButtonWidgetClass() const
{
    return LOOKUP_WITH_DEFAULT(ButtonWidgetClass);
}

TSubclassOf<UUserWidget> UMainMenuConfigurator::GetGameSettingWidgetClass(TSubclassOf<UGameSetting> SettingClass) const
{
    if (!SettingClass)
    {
        return nullptr;
    }

    TPair<TSubclassOf<UGameSetting>, TSubclassOf<UUserWidget>> Pair;

    for (const TPair<TSubclassOf<UGameSetting>, TSubclassOf<UUserWidget>>& KV : GameSettingsWidgets)
    {
        if (SettingClass->IsChildOf(KV.Key))
        {
            Pair = KV;
        }
    }

    return Pair.Value;
}

FPrimaryAssetId UMainMenuConfigurator::GetPrimaryAssetId() const
{
    return FPrimaryAssetId(GetClass()->GetFName(), GetOutermost()->GetFName());
}

void UMainMenuConfigurator::CallOnClickCallback(const FMainMenuEntry& Entry, const FMainMenuEntryButtonCallbackParams& Params)
{
    UMainMenuConfigurator* Configurator = UMainMenuSettings::GetMainMenuSettings()->GetMainMenuConfigurator();
    if (UFunction* Callback = Entry.OnClickCallback.ResolveMember<UFunction>(Configurator->GetClass()))
    {
        FStructOnScope FuncParam(Callback);

        Configurator->ProcessEvent(Callback, &const_cast<FMainMenuEntryButtonCallbackParams&>(Params));
    }
}

void UMainMenuConfigurator::OnNewGameClicked_Implementation(const FMainMenuEntryButtonCallbackParams& Params)
{

}

void UMainMenuConfigurator::OnOptionsClicked_Implementation(const FMainMenuEntryButtonCallbackParams& Params)
{

}

void UMainMenuConfigurator::OnQuitGameClicked_Implementation(const FMainMenuEntryButtonCallbackParams& Params)
{
    UKismetSystemLibrary::QuitGame(Params.CallingWidget, Params.CallingWidget->GetOwningPlayer(), EQuitPreference::Quit, false);
}

#undef LOOKUP_WITH_DEFAULT
UE_ENABLE_OPTIMIZATION

#undef LOCTEXT_NAMESPACE
