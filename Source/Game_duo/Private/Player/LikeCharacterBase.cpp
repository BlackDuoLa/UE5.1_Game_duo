// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LikeCharacterBase.h"

// 这里面什么都没有
ALikeCharacterBase::ALikeCharacterBase()
{
 	
	PrimaryActorTick.bCanEverTick = true;
}

UAbilitySystemComponent* ALikeCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALikeCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

