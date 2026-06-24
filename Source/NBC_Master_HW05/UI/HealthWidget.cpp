// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UHealthWidget::SetPercent(float NewHealth, float MaxHealth)
{

    if (IsValid(HPBar))
    {
        HPBar->SetPercent(NewHealth / MaxHealth);
    }

    if (IsValid(CurrentHPText))
    {
        CurrentHPText->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), NewHealth)));
    }

    if (IsValid(MaxHPText))
    {
        MaxHPText->SetText(FText::FromString(FString::Printf(TEXT("%.0f"), MaxHealth)));
    }
}
