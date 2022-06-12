// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FindPathPoint.h"
#include "AIController.h"

EBTNodeResult::Type UBTTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    CurrentEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());
    FVector EnemyLocation = CurrentEnemy->GetAIDetails(CurrentEnemy, OwnerComp);
    OwnerComp.GetBlackboardComponent()->SetValueAsVector("TargetLocationVector", EnemyLocation);
    return EBTNodeResult::Succeeded;
}