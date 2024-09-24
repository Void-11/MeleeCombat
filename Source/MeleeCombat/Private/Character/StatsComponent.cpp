// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/StatsComponent.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UStatsComponent::DecreaseHealth(float Amount)
{
	if (Stats[EStats::Health] <= 0) { return; }

	Stats[EStats::Health] -= Amount;
	Stats[EStats::Health] = UKismetMathLibrary::FClamp(
		Stats[EStats::Health],
		0,
		Stats[EStats::MaxHealth]
	);

}

void UStatsComponent::DecreaseStamina(float Amount)
{
	Stats[EStats::Stamina] -= Amount;

	Stats[EStats::Stamina] = UKismetMathLibrary::FClamp(
		Stats[EStats::Stamina],
		0,
		Stats[EStats::MaxStamina]
	);

	bCanRegen = false;

	FLatentActionInfo FunctionInfo{
		0,
		100,
		TEXT("EnableRegen"),
		this
	};

	UKismetSystemLibrary::RetriggerableDelay(
		GetWorld(),
		StaminaDelayDuration,
		FunctionInfo
	);

}

void UStatsComponent::RegenerateStamina()
{
	if (!bCanRegen) { return; }

	Stats[EStats::Stamina] = UKismetMathLibrary::FInterpTo_Constant(
		Stats[EStats::Stamina],
		Stats[EStats::MaxStamina],
		GetWorld()->DeltaTimeSeconds,
		StaminaRegenRate
	);

}

void UStatsComponent::EnableRegeneration()
{
	bCanRegen = true;
}

