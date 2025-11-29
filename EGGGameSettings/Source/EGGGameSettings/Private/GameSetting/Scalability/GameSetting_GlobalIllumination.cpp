// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_GlobalIllumination.h"

UGameSetting_GlobalIllumination::UGameSetting_GlobalIllumination()
{
	GameUserSettingSetterFunctionName = FName("SetGlobalIlluminationQuality");
	GameUserSettingGetterFunctionName = FName("GetGlobalIlluminationQuality");

	DisplayName = NSLOCTEXT("GameSetting", "GlobalIlluminationQuality", "Global Illumination Quality");
}
