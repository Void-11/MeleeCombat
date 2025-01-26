// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss.h"
#include "Character/StatsComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Combat/Components/CombatComponent.h"

// Sets default values
ABoss::ABoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	StatsComp = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("Combat Component"));
}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();

	BlackboardComp = GetController<AAIController>()
		->GetBlackboardComponent();

	BlackboardComp->SetValueAsEnum(
		TEXT("CurrentState"),
		InitialState
	);
}

// Called every frame
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ABoss::DetectPawn(APawn* DetectedPawn, APawn* PawnToDetect)
{
	EBossState CurrentState{
		static_cast<EBossState>(BlackboardComp->GetValueAsEnum(TEXT("CurrentState")))
	};

	if (DetectedPawn != PawnToDetect || CurrentState != EBossState::Idle) { return; }
	
	BlackboardComp->SetValueAsEnum(
		TEXT("CurrentState"),
		EBossState::Range
	);
}

float ABoss::GetDamageAmount()
{
	return StatsComp->Stats[EStats::Strength];
}

void ABoss::Attack()
{
	CombatComp->RandomAttack();
}

float ABoss::GetAnimDuration()
{
	return CombatComp->AnimDuration;
}

float ABoss::GetMeleeRange()
{
	return StatsComp->Stats[EStats::MeleeRange];
}
