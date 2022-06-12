// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_NextPathPoint.h"
#include "Enemy.h"
#include "AIController.h"

EBTNodeResult::Type UBTTask_NextPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    AEnemy* Enemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());

    bool checkPathValidity = Enemy->CheckValidity(Enemy, OwnerComp, Enemy->CurrentPathIndex, Enemy->PathDirection);

    if (checkPathValidity)
    {
        Enemy->CurrentPathIndex = Enemy->CurrentPathIndex + Enemy->PathDirection;
        return EBTNodeResult::Succeeded;
    }
    else
    {
        Enemy->PathDirection = Enemy->PathDirection * -1;
        return EBTNodeResult::Succeeded;
    }

}