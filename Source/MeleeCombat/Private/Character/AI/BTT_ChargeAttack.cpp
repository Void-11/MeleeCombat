// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AI/BTT_ChargeAttack.h"
#include "AIController.h"
#include "Animations/BossAnimInstance.h"
#include "GameFramework/Character.h"


EBTNodeResult::Type UBTT_ChargeAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ControllerRef = OwnerComp.GetAIOwner();
	CharacterRef = ControllerRef->GetCharacter();
	BossAnim = Cast<UBossAnimInstance>(
		CharacterRef->GetMesh()->GetAnimInstance()
	);

	BossAnim->bIsCharging = true;

	return EBTNodeResult::InProgress;
}
