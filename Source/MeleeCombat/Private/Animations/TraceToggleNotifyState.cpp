// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/TraceToggleNotifyState.h"

#include "Combat/Components/TraceComponent.h"


void UTraceToggleNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	UTraceComponent* TraceComp{
		MeshComp->GetOwner()
			->FindComponentByClass<UTraceComponent>()
	};

	if (!IsValid(TraceComp)) { return; }

	TraceComp->bIsAttacking = true;
}

void UTraceToggleNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	UTraceComponent* TraceComp{
		MeshComp->GetOwner()
			->FindComponentByClass<UTraceComponent>()
	};

	if (!IsValid(TraceComp)) { return; }

	TraceComp->bIsAttacking = false;
}


