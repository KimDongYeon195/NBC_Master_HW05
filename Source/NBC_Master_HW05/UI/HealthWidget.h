// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthWidget.generated.h"

class UProgressBar;
class UTextBlock;

/**
 * 
 */
UCLASS()
class NBC_MASTER_HW05_API UHealthWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPercent(float NewHealth, float MaxHealth);

public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<class UProgressBar> HPBar;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> CurrentHPText;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> MaxHPText;
};
