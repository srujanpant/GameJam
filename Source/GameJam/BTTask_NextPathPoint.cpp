// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "BTTask_NextPathPoint.h"
#include "EnemyCharacter.h"


EBTNodeResult::Type UBTTask_NextPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    bool checkPathValidity = Enemy->CheckPathValidity();

    if (checkPathValidity)
    {
        Enemy->Increment();
        return EBTNodeResult::Succeeded;
    }
    else
    {
        Enemy->Restart();
        return EBTNodeResult::Succeeded;
    }

}