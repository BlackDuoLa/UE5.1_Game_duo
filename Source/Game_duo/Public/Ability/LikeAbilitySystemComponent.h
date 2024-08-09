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

	//�������ڹ���Tag��̬�ಥ�ĺ���
	FEffectAssetTags EffectAssetTags;



protected:

	//ASC���Դ��ļ���Tag�ĺ�������
	//ί�д����Ļص�����EffectApplied()�����������GE����ӵ�ʱ�򴥷�
	//��ȡ���GEʱ�Ļص������ܹ���ӡ��ӦGE������ӵ�Tags
	void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle);



};
