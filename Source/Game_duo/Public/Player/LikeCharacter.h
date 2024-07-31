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
	//������Ϸ״̬��ͬ��ģʽ
	virtual void OnRep_PlayerState()override;


private:
	//��ʼ������ͬ��ģʽ(Ѫ������������������������Ч��������ȴ���ȵ�)
		//��AuraAbilitySystemComponent���
	void InitAbilityActorInfo();
	
};
