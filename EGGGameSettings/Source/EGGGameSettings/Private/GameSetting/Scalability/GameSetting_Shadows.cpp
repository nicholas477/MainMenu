// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Shadows.h"

UGameSetting_Shadows::UGameSetting_Shadows()
{
	GameUserSettingSetterFunctionName = FName("SetShadowQuality");
	GameUserSettingGetterFunctionName = FName("GetShadowQuality");

	DisplayName = NSLOCTEXT("GameSetting", "ShadowQuality", "Shadow Quality");
}
