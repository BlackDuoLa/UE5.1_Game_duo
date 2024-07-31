// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability/LikeAttributeSet.h"
#include "Net/UnrealNetwork.h"

ULikeAttributeSet::ULikeAttributeSet()
{
	//���ý�ɫ��������
	//���ý�ɫ��������
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(40.f);
	InitMaxMana(100.f);



}

void ULikeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

	//���ý�ɫ���Ե�ͬ��ģʽ
	DOREPLIFETIME_CONDITION_NOTIFY(ULikeAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULikeAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(ULikeAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULikeAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);


}

void ULikeAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULikeAttributeSet, Health, OldHealth);

}

void ULikeAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULikeAttributeSet, MaxHealth, OldMaxHealth);

}

void ULikeAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULikeAttributeSet, Mana, OldMana);

}

void ULikeAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULikeAttributeSet, MaxMana, OldMaxMana);

}
