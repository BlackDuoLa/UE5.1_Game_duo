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

	//��ʼ������ͬ��ģʽ(Ѫ������������������������Ч��������ȴ���ȵ�)
	//�Ѿ��ڵ������϶�����ɣ����ǲ�����Ϊ��ʵ����������϶���
	InitAbilityActorInfo();
}

void ALikeCharacter::OnRep_PlayerState()
{

	Super::OnRep_PlayerState();

	//��ʼ������ͬ��ģʽ(Ѫ������������������������Ч��������ȴ���ȵ�)
	//�Ѿ��ڵ������϶�����ɣ����ǲ�����Ϊ��ʵ����������϶���
	InitAbilityActorInfo();
}

void ALikeCharacter::InitAbilityActorInfo()
{
	

	//ָ��ʵ��ӵ������˭
	ALikePlayerState* LikePlayerState = GetPlayerState<ALikePlayerState>();
	//�ж����治����
	check(LikePlayerState);
	//��AbilitySystemComponent�����,��ȡ��ʼ���������Ѷ����ʵ��ʹ����AuraPlayerState����ȥ������������Լ�this

	LikePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(LikePlayerState, this);
	//�ѻ���Base��ʼ����AbilitySystemComponent�������ǿ���˵�Ǹ���Ϊ=����Ĳ���

	AbilitySystemComponent = LikePlayerState->GetAbilitySystemComponent();
	//Ҳ�ѻ���Base��AttributeSet������ΪLikePlayerState->GetAttributeSet();
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
