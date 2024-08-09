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

	//获取添加GE时的回调，并能够打印对应GE上面添加的Tags
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	//EffectApplied是添加GE后的事件回调，将TagContainer进行委托广播出去
	EffectAssetTags.Broadcast(TagContainer);

}
