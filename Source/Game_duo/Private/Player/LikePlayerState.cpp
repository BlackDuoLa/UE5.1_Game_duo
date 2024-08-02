// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/LikePlayerState.h"
#include "Ability/LikeAbilitySystemComponent.h"
#include "Ability/LikeAttributeSet.h"
#include <Net\UnrealNetwork.h>


ALikePlayerState::ALikePlayerState()
{
	//创建玩家能力系统组件
	AbilitySystemComponent = CreateDefaultSubobject<ULikeAbilitySystemComponent>("AbilitSystemComponent");
	//开启AbilitySystemComponent的网络同步模式
	AbilitySystemComponent->SetIsReplicated(true);

	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<ULikeAttributeSet>("AttributeSet");
	NetUpdateFrequency = 100.f;

}

void ALikePlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{

	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALikePlayerState, Level);
}

UAbilitySystemComponent* ALikePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ALikePlayerState::OnRep_Level(int32 Oldlevel)
{


}
