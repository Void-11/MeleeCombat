// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/Enemy.h"
#include "Character/EBossState.h"
#include "Interfaces/Attack.h"
#include "Boss.generated.h"

UCLASS()
class MELEECOMBAT_API ABoss : public ACharacter, public IEnemy, public IAttack
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EBossState> InitialState;

	class UBlackboardComponent* BlackboardComp;


public:
	// Sets default values for this character's properties
	ABoss();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStatsComponent* StatsComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCombatComponent* CombatComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void DetectPawn(APawn* DetectedPawn, APawn* PawnToDetect);

	virtual float GetDamageAmount() override;

	virtual void Attack() override;

	virtual float GetAnimDuration() override;

	virtual float GetMeleeRange() override;
};
