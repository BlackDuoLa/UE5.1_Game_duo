// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "LikeAbilitySystemComponent.generated.h"



DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags,const FGameplayTagContainer&)



UCLASS()
class GAME_DUO_API ULikeAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:

	void AbilityActorInfoSet();

	//创建基于关于Tag动态多播的函数
	FEffectAssetTags EffectAssetTags;



protected:

	//ASC中自带的监听Tag的函数构造
	//委托触发的回调函数EffectApplied()这个函数将在GE被添加的时候触发
	//获取添加GE时的回调，并能够打印对应GE上面添加的Tags
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);



};
