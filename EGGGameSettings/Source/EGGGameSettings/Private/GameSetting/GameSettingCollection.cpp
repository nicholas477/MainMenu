// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/GameSettingCollection.h"

TArray<UGameSettingCollection*> UGameSettingCollection::GetChildCollections() const
{
	TArray<UGameSettingCollection*> CollectionSettings;

	for (UGameSetting* ChildSetting : Settings)
	{
		if (UGameSettingCollection* ChildCollection = Cast<UGameSettingCollection>(ChildSetting))
		{
			CollectionSettings.Add(ChildCollection);
		}
	}

	return CollectionSettings;
}

void UGameSettingCollection::AddSetting(UGameSetting* Setting)
{
#if !UE_BUILD_SHIPPING
	ensureAlwaysMsgf(Setting->GetSettingParent() == nullptr, TEXT("This setting already has a parent!"));
	ensureAlwaysMsgf(!Settings.Contains(Setting), TEXT("This collection already includes this setting!"));
#endif

	Settings.Add(Setting);
	Setting->SetSettingParent(this);

	if (LocalPlayer)
	{
		Setting->Initialize(LocalPlayer);
	}
}
