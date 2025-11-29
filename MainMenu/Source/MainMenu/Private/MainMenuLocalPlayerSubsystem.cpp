// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuLocalPlayerSubsystem.h"

#include "MainMenuSettings.h"
#include "MainMenuConfigurator.h"
#include "GameSetting/GameSetting.h"

void UMainMenuLocalPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InitializeSettings();
}

void UMainMenuLocalPlayerSubsystem::InitializeSettings()
{
	if (UMainMenuConfigurator* Configurator = UMainMenuSettings::GetMainMenuSettings()->GetMainMenuConfigurator())
	{
		for (UGameSetting* Setting : Configurator->GetGameSettings())
		{
			Setting->Initialize(GetLocalPlayer());
		}
	}
}
