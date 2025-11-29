// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Effects.h"

UGameSetting_Effects::UGameSetting_Effects()
{
	GameUserSettingSetterFunctionName = FName("SetVisualEffectQuality");
	GameUserSettingGetterFunctionName = FName("GetVisualEffectQuality");

	DisplayName = NSLOCTEXT("GameSetting", "EffectsQuality", "Effects Quality");
}
