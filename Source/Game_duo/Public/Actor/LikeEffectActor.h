#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ability/LikeAttributeSet.h"
#include "LikeEffectActor.generated.h"


class UGameplayEffect;



UCLASS()
class GAME_DUO_API ALikeEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ALikeEffectActor();

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect>GameplayEffectClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;






};
