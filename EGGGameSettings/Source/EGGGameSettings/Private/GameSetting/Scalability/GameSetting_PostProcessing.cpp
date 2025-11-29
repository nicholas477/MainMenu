// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSetting/Scalability/GameSetting_PostProcessing.h"

UGameSetting_PostProcessing::UGameSetting_PostProcessing()
{
	GameUserSettingSetterFunctionName = FName("SetPostProcessingQuality");
	GameUserSettingGetterFunctionName = FName("GetPostProcessingQuality");

	DisplayName = NSLOCTEXT("GameSetting", "PostProcessingQuality", "Post Processing Quality");
}
