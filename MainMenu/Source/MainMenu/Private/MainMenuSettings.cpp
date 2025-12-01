// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuSettings.h"

#include "MainMenuFunctionLibrary.h"
#include "MainMenuConfigurator.h"
#include "GameSetting/GameSetting.h"

UMainMenuFunctionLibrary* UMainMenuSettings::GetMainMenuFunctionLibrary()
{
    UMainMenuSettings* Settings = GetMainMenuSettings();
    if (ensure(Settings != nullptr))
    {
        if (Settings->MainMenuFunctionLibraryOverride != nullptr)
        {
            return Settings->MainMenuFunctionLibraryOverride->GetDefaultObject<UMainMenuFunctionLibrary>();
        }
        else
        {
            return UMainMenuFunctionLibrary::StaticClass()->GetDefaultObject<UMainMenuFunctionLibrary>();
        }
    }

    return nullptr;
}

UMainMenuConfigurator* UMainMenuSettings::GetMainMenuConfigurator() const
{
    if (!MainMenuConfigurator.GetDefaultObject())
    {
        return GetDefaultMainMenuConfigurator();
    }

    return MainMenuConfigurator.GetDefaultObject();
}

UMainMenuConfigurator* UMainMenuSettings::GetDefaultMainMenuConfigurator()
{
    UBlueprint* BP = Cast<UBlueprint>(FSoftObjectPath(TEXT("/MainMenu/BP_DefaultMainMenuConfigurator.BP_DefaultMainMenuConfigurator")).TryLoad());

    return BP ? Cast<UMainMenuConfigurator>(BP->GeneratedClass->GetDefaultObject()) : nullptr;
}

void UMainMenuSettings::PostInitProperties()
{
    Super::PostInitProperties();

    if (UMainMenuConfigurator* MyMainMenuConfigurator = GetMainMenuConfigurator())
    {
        for (UGameSetting* GameSetting : MyMainMenuConfigurator->GetGameSettings())
        {
            if (GameSetting)
            {
                GameSetting->Initialize();
            }
        }
    }
}

