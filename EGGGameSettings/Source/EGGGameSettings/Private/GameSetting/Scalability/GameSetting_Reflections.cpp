// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Reflections.h"

UGameSetting_Reflections::UGameSetting_Reflections()
{
	GameUserSettingSetterFunctionName = FName("SetReflectionQuality");
	GameUserSettingGetterFunctionName = FName("GetReflectionQuality");

	DisplayName = NSLOCTEXT("GameSetting", "ReflectionsQuality", "Reflections Quality");
}
