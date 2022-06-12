// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyCharacter.h"
#include "AIController.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FVector AEnemyCharacter::GetAIDetails(AEnemyCharacter* CurrentEnemy, UBehaviorTreeComponent& OwnerComp)
{
	CurrentEnemy = Cast<AEnemyCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	UE_LOG(LogTemp, Warning, TEXT("G1"));
	AActor* CurrentPatrolPathActor = PatrolPaths[CurrentPathIndex];
	FVector EnemyLocation = CurrentPatrolPathActor->GetActorLocation();
	return EnemyLocation;
}