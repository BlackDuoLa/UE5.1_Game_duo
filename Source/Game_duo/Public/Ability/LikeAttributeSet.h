// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
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



};
