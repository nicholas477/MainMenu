// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_Textures.h"

UGameSetting_Textures::UGameSetting_Textures()
{
	GameUserSettingSetterFunctionName = FName("SetTextureQuality");
	GameUserSettingGetterFunctionName = FName("GetTextureQuality");

	DisplayName = NSLOCTEXT("GameSetting", "TextureQuality", "Texture Quality");
}
