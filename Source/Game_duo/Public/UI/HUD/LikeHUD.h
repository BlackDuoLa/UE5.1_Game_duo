// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LikeHUD.generated.h"


class UOverlayWidgetController;
class ULikeUserWidget;

class APlayerController;
class APlayerState;
class UAbilitySystemComponent;
class UAttributeSet;

struct FWidgetControllerParams;


UCLASS()
class GAME_DUO_API ALikeHUD : public AHUD
{
	GENERATED_BODY()
	


public:

	UPROPERTY()
	TObjectPtr<ULikeUserWidget>OverlayWidget;


	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);


	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);






private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<ULikeUserWidget>OverlayWidgetClass;


	UPROPERTY()
	TObjectPtr<UOverlayWidgetController>OverlayWidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController>OverlayWidgetControllerClass;

};
