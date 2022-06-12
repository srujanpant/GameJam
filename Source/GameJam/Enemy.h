// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/BehaviorTreeComponent.h"
#include "CoreMinimal.h"
#include "GameJamCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API AEnemy : public AGameJamCharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
		TArray<AActor*> PatrolPaths;

public:

	int CurrentPathIndex = 0;
	int PathDirection = 1;
	FVector GetAIDetails(AEnemy* CurrentEnemy, UBehaviorTreeComponent& OwnerComp);
	AActor* GetPatrolActor(AEnemy* CurrentEnemy, UBehaviorTreeComponent& OwnerComp);
	bool CheckValidity(AEnemy* CurrentEnemy, UBehaviorTreeComponent& OwnerComp,int currentPathIndex, int pathDirection);
};
