// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "BTTask_RotateEnemyOnPoint.h"
#include "EnemyCharacter.h"
#include "Kismet/KismetSystemLibrary.h"

EBTNodeResult::Type UBTTask_RotateEnemyOnPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return EBTNodeResult::Failed;
    }

    AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    FLatentActionInfo LatentInfo;
    LatentInfo.CallbackTarget = this;

    UKismetSystemLibrary::MoveComponentTo(Enemy->GetRootComponent(), Enemy->GetRootComponent()->GetComponentLocation(), Enemy->GetPatrolPathActorRotation(), true, true, 0.2f, true, EMoveComponentAction::Move, LatentInfo);

    return EBTNodeResult::Succeeded;
}