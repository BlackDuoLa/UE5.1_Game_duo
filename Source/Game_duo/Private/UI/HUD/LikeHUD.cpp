// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUD/LikeHUD.h"
#include "UI\Widget\LikeUserWidget.h"
#include "UI\WidgetController\OverlayWidgetController.h"


UOverlayWidgetController* ALikeHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController == nullptr)
	{
		
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
	
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();


		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}

void ALikeHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{

	
	checkf(OverlayWidgetClass, TEXT("Overlay Widget Class uninitalized,Please fill out BBP_AuraHUD"));

	checkf(OverlayWidgetControllerClass, TEXT("Overlay Widget Controller Class uninitalized,Please fill out BBP_AuraHUD"));


	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget = Cast<ULikeUserWidget>(Widget);

	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetWidgetController(WidgetController);

	WidgetController->BroadcastInitialValues();

	
	Widget->AddToViewport();





}
