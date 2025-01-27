// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Character/EStats.h"
#include "StatsComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MELEECOMBAT_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	double StaminaRegenRate{ 10.0 };

	UPROPERTY(VisibleAnywhere)
	bool bCanRegen{ true };

	UPROPERTY(EditAnywhere)
	float StaminaDelayDuration{ 2.0f };

public:	
	// Sets default values for this component's properties
	UStatsComponent();

	UPROPERTY(EditAnywhere)
	TMap<TEnumAsByte<EStats>, float> Stats;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void DecreaseHealth(float Amount);

	UFUNCTION(BlueprintCallable)
	void DecreaseStamina(float Amount);

	UFUNCTION(BlueprintCallable)
	void RegenerateStamina();

	UFUNCTION()
	void EnableRegeneration();
	
};
