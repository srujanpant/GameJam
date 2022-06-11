// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "BTTask_FindPathPoint.h"

EBTNodeResult::Type UBTTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    CurrentEnemy = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
    FVector EnemyLocation = CurrentEnemy->GetPathpointLocation();
    OwnerComp.GetBlackboardComponent()->SetValueAsVector(BB_TargetVector.SelectedKeyName, EnemyLocation);

    return EBTNodeResult::Succeeded;
}