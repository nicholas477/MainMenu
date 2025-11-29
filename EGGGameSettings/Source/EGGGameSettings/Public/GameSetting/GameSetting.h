// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameSetting.generated.h"

/** Why did the setting change? */
UENUM(BlueprintType)
enum class EGameSettingChangeReason : uint8
{
	Change,
	DependencyChanged,
	ResetToDefault,
	RestoreToInitial,
};

/**
 * 
 */
UCLASS(Abstract, BlueprintType, EditInlineNew)
class EGGGAMESETTINGS_API UGameSetting : public UObject
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSettingChanged, UGameSetting*, InSetting, EGameSettingChangeReason, InChangeReason);

	UPROPERTY(BlueprintAssignable)
	FOnSettingChanged OnSettingChangedEvent;

	UFUNCTION(BlueprintCallable)
	FText GetDisplayName() const { return DisplayName; }
	void SetDisplayName(const FText& Value) { DisplayName = Value; }

	/** Initializes the setting, giving it the owning local player.  Containers automatically initialize settings added to them. */
	void Initialize(ULocalPlayer* InLocalPlayer);

	/**
	 * We expect settings to change the live value immediately, but occasionally there are special settings
	 * that go are immediately stored to a temporary location but we don't actually apply them until later
	 * like selecting a new resolution.
	 */
	UFUNCTION(BlueprintCallable)
	void Apply();

	UFUNCTION(BlueprintPure, meta = (DeterminesOutputType = "GameSettingClass"))
	static UGameSetting* GetGameSetting(TSubclassOf<UGameSetting> GameSettingClass);

	/**
	 * Any setting can have children, this is so we can allow for the possibility of "collections" or "actions" that
	 * are not directly visible to the user, but are set by some means and need to have initial and restored values.
	 * In that case, you would likely have internal settings inside an action subclass that is set on another screen,
	 * but never directly listed on the settings panel.
	 */
	UFUNCTION(BlueprintPure)
	virtual TArray<UGameSetting*> GetChildSettings() { return TArray<UGameSetting*>(); }

	/** The parent object that owns the setting, in most cases the collection, but for top level settings the registry. */
	void SetSettingParent(UGameSetting* InSettingParent);
	UGameSetting* GetSettingParent() const { return SettingParent; }

	/** Gets the current world of the local player that owns these settings. */
	virtual UWorld* GetWorld() const override;

	/** Notify that the setting changed */
	UFUNCTION(BlueprintCallable)
	void NotifySettingChanged(EGameSettingChangeReason Reason);
	virtual void OnSettingChanged(EGameSettingChangeReason Reason);

protected:
	virtual void OnApply();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText DisplayName;

	UPROPERTY(Transient)
	ULocalPlayer* LocalPlayer;

	UPROPERTY(Transient)
	UGameSetting* SettingParent;
};
