// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/GameSetting.h"

void UGameSetting::Initialize(ULocalPlayer* InLocalPlayer)
{
	// If we've already gotten this local player we're already initialized.
	if (LocalPlayer == InLocalPlayer)
	{
		return;
	}

	LocalPlayer = InLocalPlayer;

	//TODO: GameSettings
	//LocalPlayer->OnPlayerLoggedIn().AddUObject(this, &UGameSetting::RefreshEditableState, true);

//#if !UE_BUILD_SHIPPING
//	ensureAlwaysMsgf(DevName != NAME_None, TEXT("You must provide a DevName for the setting."));
//	ensureAlwaysMsgf(!DisplayName.IsEmpty(), TEXT("You must provide a DisplayName for settings."));
//#endif

	//for (const TSharedRef<FGameSettingEditCondition>& EditCondition : EditConditions)
	//{
	//	EditCondition->Initialize(LocalPlayer);
	//}

	// If there are any child settings go ahead and initialize them as well.
	for (UGameSetting* Setting : GetChildSettings())
	{
		Setting->Initialize(LocalPlayer.Get());
	}

	Startup();
}

void UGameSetting::Apply()
{
	OnApply();
}

void UGameSetting::Save()
{
	OnSave();
}

UGameSetting* UGameSetting::GetGameSetting(TSubclassOf<UGameSetting> GameSettingClass)
{
	if (!GameSettingClass)
	{
		return nullptr;
	}

	if (GameSettingClass->HasAnyClassFlags(EClassFlags::CLASS_Abstract))
	{
		return nullptr;
	}

	return GameSettingClass->GetDefaultObject<UGameSetting>();
}

void UGameSetting::SetSettingParent(UGameSetting* InSettingParent)
{
	SettingParent = InSettingParent;
}

UWorld* UGameSetting::GetWorld() const
{
	return LocalPlayer.IsValid() ? LocalPlayer->GetWorld() : nullptr;
}

void UGameSetting::NotifySettingChanged(EGameSettingChangeReason Reason)
{
	OnSettingChanged(Reason);

	// Run through any edit conditions and let them know things changed.
	//for (const TSharedRef<FGameSettingEditCondition>& EditCondition : EditConditions)
	//{
	//	EditCondition->SettingChanged(LocalPlayer, this, Reason);
	//}

	//if (!bOnSettingChangedEventGuard)
	{
		//TGuardValue<bool> Guard(bOnSettingChangedEventGuard, true);
		OnSettingChangedEvent.Broadcast(this, Reason);
	}
}

void UGameSetting::OnSettingChanged(EGameSettingChangeReason Reason)
{

}

void UGameSetting::OnApply()
{

}

void UGameSetting::OnSave()
{

}

void UGameSetting::Startup()
{

}