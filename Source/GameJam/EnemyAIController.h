// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
		class UAIPerceptionComponent* AIPerceptionComponent;

private:
	UPROPERTY(EditAnywhere)
		UBehaviorTree* AIBehavior;

	UAISenseConfig_Sight* Sight;

	UFUNCTION()
		void PerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus);

public:
	AEnemyAIController();

	virtual void OnPossess(APawn* InPawn) override;
};
