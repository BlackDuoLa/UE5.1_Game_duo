// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/LikeAbilitySystemComponent.h"

void ULikeAbilitySystemComponent::AbilityActorInfoSet()
{
	//
	OnGameplayEffectAppliedDelegateToSelf.AddUObject
	(this, &ULikeAbilitySystemComponent::EffectApplied);

}



void ULikeAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* 
	AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, 
	FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{

	//��ȡ���GEʱ�Ļص������ܹ���ӡ��ӦGE������ӵ�Tags
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	//EffectApplied�����GE����¼��ص�����TagContainer����ί�й㲥��ȥ
	EffectAssetTags.Broadcast(TagContainer);

}
