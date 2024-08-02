// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "LikeAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
 	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


UCLASS()
class GAME_DUO_API ULikeAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	

public:
	ULikeAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray < FLifetimeProperty>& OutLifetimeProps) const override;


	//������ɫ���������ԣ������˺���
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Vital Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Strength);

	//������ɫ���ǻ����ԣ����ӷ�����
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Vital Attributes")
	FGameplayAttributeData Intelligence;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Intelligence);

	//������ɫ���������ԣ����ӻ��ܣ�
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resilience, Category = "Vital Attributes")
	FGameplayAttributeData Resilience;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Resilience);


	//������ɫ�Ļ������ԣ�����������
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vigor, Category = "Vital Attributes")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Vigor);

	//������ɫ�Ļ�������
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Armor, Category = "Secondary Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Armor);

	//������ɫ�Ĵ�������
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ArmorPenetration, Category = "Secondary Attributes")
	FGameplayAttributeData ArmorPenetration;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, ArmorPenetration);

	//������ɫ�Ļ��ܻ�������
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BlockChance, Category = "Secondary Attributes")
	FGameplayAttributeData BlockChance;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, BlockChance);

	//������ɫ������������
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitChance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitChance;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, CriticalHitChance);

	//������ɫ�����˺�����
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitDamage, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitDamage;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, CriticalHitDamage);

	//������ɫ������������
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalHitResistance, Category = "Secondary Attributes")
	FGameplayAttributeData CriticalHitResistance;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, CriticalHitResistance);

	//������ɫѪ���ظ�����
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HealthRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData HealthRegeneration;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, HealthRegeneration);

	//������ɫ�����ظ�����
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ManaRegeneration, Category = "Secondary Attributes")
	FGameplayAttributeData ManaRegeneration;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, ManaRegeneration);



	UPROPERTY(BlueprintReadOnly,Category = "Ability")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Ability")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Ability")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, Category = "Ability")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(ULikeAttributeSet, MaxMana);




	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;


	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	UFUNCTION()
	void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

	UFUNCTION()
	void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;
	UFUNCTION()
	void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;
	UFUNCTION()
	void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;
	UFUNCTION()
	void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;
	UFUNCTION()
	void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;
	UFUNCTION()
	void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;
	UFUNCTION()
	void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;
	UFUNCTION()
	void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;




};
