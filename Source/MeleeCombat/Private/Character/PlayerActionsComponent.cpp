// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/PlayerActionsComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interfaces/MainPlayer.h"

// Sets default values for this component's properties
UPlayerActionsComponent::UPlayerActionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerActionsComponent::BeginPlay()
{
	Super::BeginPlay();

	CharacterRef = GetOwner<ACharacter>();
	MovementComp = CharacterRef->GetCharacterMovement();

	if (!CharacterRef->Implements<UMainPlayer>()) { return; }

	IPlayerRef = Cast<IMainPlayer>(CharacterRef);
}


// Called every frame
void UPlayerActionsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerActionsComponent::Sprinting()
{
	if (!IPlayerRef->HasSufficientStamina(SprintingAmount)) 
	{ 
		Walking();
		return; 
	}

	if (MovementComp->Velocity.Equals(FVector::ZeroVector, 1)) { return; }

    
    	MovementComp->MaxWalkSpeed = SprintingSpeed;

	OnSprintDelegate.Broadcast(SprintingAmount);
}

void UPlayerActionsComponent::Walking()
{
	MovementComp->MaxWalkSpeed = WalkingSpeed;
}

