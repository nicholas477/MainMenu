// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_AntiAliasingQuality.h"

UGameSetting_AntiAliasingQuality::UGameSetting_AntiAliasingQuality()
{
    GameUserSettingSetterFunctionName = FName("SetAntiAliasingQuality");
    GameUserSettingGetterFunctionName = FName("GetAntiAliasingQuality");

    DisplayName = NSLOCTEXT("GameSetting", "AntiAliasingQuality", "Anti Aliasing Quality");
}
