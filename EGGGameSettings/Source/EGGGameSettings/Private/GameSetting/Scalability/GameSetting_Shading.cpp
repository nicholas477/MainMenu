// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Shading.h"

UGameSetting_Shading::UGameSetting_Shading()
{
	GameUserSettingSetterFunctionName = FName("SetShadingQuality");
	GameUserSettingGetterFunctionName = FName("GetShadingQuality");

	DisplayName = NSLOCTEXT("GameSetting", "ShadingQuality", "Shading Quality");
}
