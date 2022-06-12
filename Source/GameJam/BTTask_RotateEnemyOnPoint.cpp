// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_RotateEnemyOnPoint.h"
#include "AIController.h"
#include "Enemy.h"
#include "Kismet/KismetSystemLibrary.h"

EBTNodeResult::Type UBTTask_RotateEnemyOnPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    AEnemy* Enemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());
    AActor* enemyActor = Enemy->GetPatrolActor(Enemy, OwnerComp);

    FLatentActionInfo LatentInfo;
    LatentInfo.CallbackTarget = this;

    UKismetSystemLibrary::MoveComponentTo(Enemy->GetRootComponent(), Enemy->GetRootComponent()->GetComponentLocation(), enemyActor->GetActorRotation(), true, true, 0.2f, true, EMoveComponentAction::Move, LatentInfo);

    return EBTNodeResult::Succeeded;
}