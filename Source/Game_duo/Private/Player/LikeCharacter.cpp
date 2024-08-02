// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LikeCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/LikePlayerController.h" 
#include "UI/HUD/LikeHUD.h"

ALikeCharacter::ALikeCharacter()
{
	

}

void ALikeCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//初始化属性同步模式(血量、蓝量、体力、声音、特效、技能冷却、等等)
	//已经在敌人身上定义完成，这是操作是为了实现在玩家身上定义
	InitAbilityActorInfo();
}

void ALikeCharacter::OnRep_PlayerState()
{

	Super::OnRep_PlayerState();

	//初始化属性同步模式(血量、蓝量、体力、声音、特效、技能冷却、等等)
	//已经在敌人身上定义完成，这是操作是为了实现在玩家身上定义
	InitAbilityActorInfo();
}

void ALikeCharacter::InitAbilityActorInfo()
{
	

	//指认实际拥有者是谁
	ALikePlayerState* LikePlayerState = GetPlayerState<ALikePlayerState>();
	//判断它存不存在
	check(LikePlayerState);
	//从AbilitySystemComponent组件上,获取初始化函数，把定义的实际使用者AuraPlayerState传过去，代理是玩家自己this

	LikePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(LikePlayerState, this);
	//把基类Base初始化的AbilitySystemComponent定义这是可以说是复制为=后面的参数

	AbilitySystemComponent = LikePlayerState->GetAbilitySystemComponent();
	//也把基类Base的AttributeSet，定义为LikePlayerState->GetAttributeSet();
	AttributeSet = LikePlayerState->GetAttributeSet();
	
	if (ALikePlayerController* LikePlayerController = Cast<ALikePlayerController>(GetController()))
	{
		if (ALikeHUD* LikeHUD = Cast<ALikeHUD>(LikePlayerController->GetHUD()))
		{
			LikeHUD->InitOverlay(LikePlayerController, LikePlayerState, AbilitySystemComponent, AttributeSet);
		}

		InitializeDefaultAttributes();
	}

}
