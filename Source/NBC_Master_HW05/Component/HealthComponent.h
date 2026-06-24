// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

// 오늘 했던 실습을 통해서 만들었던 OnHealthDamaged를 통해 UI를 업데이트 해보기
// 오늘 했던 실습을 통해서 OnHealthDead로 플레이어가 실제 사망하는 모습을 만들어오기

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthDeadSignature, AController*, Instigator);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FHealthDamagedSignature, float, NewHealth, float, MaxHealth, float, HealthChange);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class NBC_MASTER_HW05_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UHealthComponent();

	UPROPERTY(BlueprintAssignable)
	FHealthDeadSignature OnHealthDead;

	UPROPERTY(BlueprintAssignable)
	FHealthDamagedSignature OnHealthDamaged;

protected:
	virtual void BeginPlay() override;

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category ="Health")
	float CurrentHealth;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Health")
	float MaxHealth;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UFUNCTION()
	void DamageTake(AActor* DamagedActor,float Damage,const UDamageType* DamageType,AController* Instigator,AActor* Causer);
};
