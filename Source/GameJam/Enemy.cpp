// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "AIController.h"

FVector AEnemy::GetAIDetails(AEnemy* CurrentEnemy, UBehaviorTreeComponent& OwnerComp)
{
	CurrentEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("G1"));
	AActor* CurrentPatrolPathActor = PatrolPaths[CurrentPathIndex];
	FVector EnemyLocation = CurrentPatrolPathActor->GetActorLocation();
	return EnemyLocation;
}


AActor* AEnemy::GetPatrolActor(AEnemy* CurrentEnemy, UBehaviorTreeComponent& OwnerComp)
{
	CurrentEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	AActor* CurrentPatrolPathActor = PatrolPaths[CurrentPathIndex];
	return CurrentPatrolPathActor;
}

bool AEnemy::CheckValidity(AEnemy* CurrentEnemy, UBehaviorTreeComponent& OwnerComp, int currentPathIndex, int pathDirection)
{
	CurrentEnemy = Cast<AEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	bool result = PatrolPaths.IsValidIndex(currentPathIndex + pathDirection);
	return result;
}
