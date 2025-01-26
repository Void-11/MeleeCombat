// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/AI/BTT_RangeAttack.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Character/EBossState.h"
#include "Interfaces/Attack.h"


EBTNodeResult::Type UBTT_RangeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ACharacter* CharacterRef{ 
		OwnerComp.GetAIOwner()->GetPawn<ACharacter>() 
	};

	if (!IsValid(CharacterRef)) { return EBTNodeResult::Failed; }

	float Distance{
		OwnerComp.GetBlackboardComponent()
			->GetValueAsFloat(TEXT("Distance"))
	};

	IAttack* FighterRef{ Cast<IAttack>(CharacterRef) };

	if (Distance < FighterRef->GetMeleeRange())
	{
		OwnerComp.GetBlackboardComponent()
			->SetValueAsEnum(TEXT("CurrentState"), EBossState::Melee);

		AbortTask(OwnerComp, NodeMemory);

		return EBTNodeResult::Aborted;
	}

	CharacterRef->PlayAnimMontage(AnimMontage);

	double RandomValue{ UKismetMathLibrary::RandomFloat() };

	if (RandomValue > Threshold)
	{
		Threshold = 0.9;
		
		OwnerComp.GetBlackboardComponent()
			->SetValueAsEnum(
				TEXT("CurrentState"),
				EBossState::Charge
			);

	}
	else
	{
		Threshold -= 0.1;
	}

	return EBTNodeResult::Succeeded;
}
