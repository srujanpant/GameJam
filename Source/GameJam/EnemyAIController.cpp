// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameJamCharacter.h"

AEnemyAIController::AEnemyAIController()
{
    AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception Component"));

    Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));

    Sight->SightRadius = 1500.f;
    Sight->LoseSightRadius = 2000.f;
    Sight->PeripheralVisionAngleDegrees = 40.f;
    Sight->DetectionByAffiliation.bDetectEnemies = true;
    Sight->DetectionByAffiliation.bDetectFriendlies = true;
    Sight->DetectionByAffiliation.bDetectNeutrals = true;

    AIPerceptionComponent->ConfigureSense(*Sight);
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    if (AIBehavior != nullptr)
    {
        RunBehaviorTree(AIBehavior);
    }
}

void AEnemyAIController::PerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
    FString StimulusName = Stimulus.Type.Name.ToString();
    AGameJamCharacter* PlayerCharacter = Cast<AGameJamCharacter>(UpdatedActor);


    if (StimulusName.Contains("sight"))
    {
        UBlackboardComponent* AIBlackboardComponent = AEnemyAIController::GetBlackboardComponent();

        if (Stimulus.WasSuccessfullySensed())
        {
            AIBlackboardComponent->SetValueAsBool("bIsInvestigating", Stimulus.WasSuccessfullySensed());
            AIBlackboardComponent->SetValueAsObject("TargetLocationActor", PlayerCharacter);
        }
        else
        {
            AIBlackboardComponent->SetValueAsVector("TargetLocationVector", Stimulus.StimulusLocation);
            AIBlackboardComponent->ClearValue("TargetLocationActor");
        }
    }
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);
    AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::PerceptionUpdated);
}
