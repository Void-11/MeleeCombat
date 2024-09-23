// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerActionsComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MELEECOMBAT_API UPlayerActionsComponent : public UActorComponent
{
	GENERATED_BODY()

	ACharacter* CharacterRef;

	class IMainPlayer* IPlayerRef;

	class UCharacterMovementComponent* MovementComp;

	UPROPERTY(EditAnywhere)
	float SprintingAmount{ 0.1f };

	UPROPERTY(EditAnywhere)
	float SprintingSpeed{ 1000.0f };

	UPROPERTY(EditAnywhere)
	float WalkingSpeed{ 500.0f };


public:	
	// Sets default values for this component's properties
	UPlayerActionsComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Sprinting();

	UFUNCTION(BlueprintCallable)
	void Walking();
};
