// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainMenuConfigurator.generated.h"

class UGameSetting;
class UUserWidget;

USTRUCT(BlueprintType)
struct FMainMenuEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ButtonText;

	UPROPERTY(EditAnywhere, meta = (FunctionReference, PrototypeFunction = "/Script/MainMenu.MainMenuConfigurator.Prototype_OnClicked"))
	FMemberReference OnClickCallback;
};

USTRUCT(BlueprintType)
struct FMainMenuEntryButtonCallbackParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* MainMenuWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* CallingWidget;
};

/**
 * 
 */
UCLASS(Blueprintable)
class MAINMENU_API UMainMenuConfigurator : public UObject
{
	GENERATED_BODY()
	
public:
	UMainMenuConfigurator();

	UFUNCTION(BlueprintPure)
	TSubclassOf<UUserWidget> GetButtonWidgetClass() const;

	UFUNCTION(BlueprintPure)
	TSubclassOf<UUserWidget> GetGameSettingWidgetClass(TSubclassOf<UGameSetting> SettingClass) const;

	UFUNCTION(BlueprintPure)
	TArray<FMainMenuEntry> GetMainMenuEntries() const { return MainMenuEntries; }

	UFUNCTION(BlueprintPure)
	TArray<UGameSetting*> GetGameSettings() const { return GameSettings; }

protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> ButtonWidgetClass;

	UPROPERTY(EditAnywhere, meta = (AllowAbstract))
	TMap<TSubclassOf<UGameSetting>, TSubclassOf<UUserWidget>> GameSettingsWidgets;

	UPROPERTY(EditAnywhere)
	TArray<FMainMenuEntry> MainMenuEntries;

	UPROPERTY(EditAnywhere, Instanced)
	TArray<UGameSetting*> GameSettings;

	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

	// Looks up a property from this configurator, if the property is null
	// it returns whatever the property is on BP_DefaultMainMenuConfigurator
	template<typename T>
	T LookupConfigurationWithDefault(FName PropertyName) const;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnNewGameClicked(const FMainMenuEntryButtonCallbackParams& Params);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnOptionsClicked(const FMainMenuEntryButtonCallbackParams& Params);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnQuitGameClicked(const FMainMenuEntryButtonCallbackParams& Params);

	UFUNCTION(BlueprintCallable, meta = (AutoCreateRefTerm = "Params"))
	static void CallOnClickCallback(const FMainMenuEntry& Entry, const FMainMenuEntryButtonCallbackParams& Params);

private:
	UFUNCTION()
	void Prototype_OnClicked(const FMainMenuEntryButtonCallbackParams& Params) {};
};
