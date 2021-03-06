// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Enemy.h"
#include "BTTask_FindPathPoint.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API UBTTask_FindPathPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

private:
	AEnemy* CurrentEnemy;
};
