// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Foliage.h"

UGameSetting_Foliage::UGameSetting_Foliage()
{
	GameUserSettingSetterFunctionName = FName("SetFoliageQuality");
	GameUserSettingGetterFunctionName = FName("GetFoliageQuality");

	DisplayName = NSLOCTEXT("GameSetting", "FoliageQuality", "Foliage Quality");
}
