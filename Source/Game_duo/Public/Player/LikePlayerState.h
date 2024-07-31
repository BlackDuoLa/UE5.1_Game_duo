// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "LikePlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class GAME_DUO_API ALikePlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ALikePlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }


protected:

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent>AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet>AttributeSet;



private:



	
};
