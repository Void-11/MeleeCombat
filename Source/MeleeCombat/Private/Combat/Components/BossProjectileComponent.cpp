// Fill out your copyright notice in the Description page of Project Settings.


#include "Combat/Components/BossProjectileComponent.h"

#include "Kismet/KismetMathLibrary.h"


// Sets default values for this component's properties
UBossProjectileComponent::UBossProjectileComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UBossProjectileComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UBossProjectileComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UBossProjectileComponent::SpawnProjectile(FName ComponentName, TSubclassOf<AActor> ProjectileClass)
{
	USceneComponent* SpawnPointComp{ 
		Cast<USceneComponent>(GetOwner()->GetDefaultSubobjectByName(ComponentName))
	};

	FVector SpawnLocation{ SpawnPointComp->GetComponentLocation() };

	FVector PlayerLocation{ GetWorld()->GetFirstPlayerController()
		->GetPawn()
		->GetActorLocation() 
	};

	FRotator SpawnRotation{ 
		UKismetMathLibrary::FindLookAtRotation(
			SpawnLocation, PlayerLocation
		)
	};

	GetWorld()->SpawnActor(
		ProjectileClass, 
		&SpawnLocation, 
		&SpawnRotation
	);


}

