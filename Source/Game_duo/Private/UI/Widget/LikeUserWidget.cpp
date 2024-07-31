// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/LikeUserWidget.h"

void ULikeUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
