// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LikeCharacterBase.h"
#include "AbilitySystemComponent.h"

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

void ALikeCharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const
{

	UAbilitySystemComponent* ASC = GetAbilitySystemComponent();
	check(IsValid(ASC));
	check(GameplayEffectClass);
	const FGameplayEffectContextHandle ContextHandle = ASC->MakeEffectContext();
	const FGameplayEffectSpecHandle SpecHandle = ASC->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
	ASC->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), ASC);

}

void ALikeCharacterBase::InitializeDefaultAttributes() const
{

	ApplyEffectToSelf(DefaultPrimaryAttributes, 1.f);
	ApplyEffectToSelf(DefaultSecondaryAttributes, 1.f);
}

