// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BossAnimInstance.generated.h"

UCLASS()
class MELEECOMBAT_API UBossAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadWrite)
	float CurrentSpeed{ 0.0f };
	
};