// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LikeCharacterBase.h"
#include "Player/LikePlayerState.h"
#include "AbilitySystemComponent.h"
#include "LikeCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GAME_DUO_API ALikeCharacter : public ALikeCharacterBase
{
	GENERATED_BODY()


public:

	ALikeCharacter();

	virtual void PossessedBy(AController* NewController) override;
	//设置游戏状态的同步模式
	virtual void OnRep_PlayerState()override;


private:
	//初始化属性同步模式(血量、蓝量、体力、声音、特效、技能冷却、等等)
		//与AuraAbilitySystemComponent相关
	void InitAbilityActorInfo();
	
};
