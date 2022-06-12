// Fill out your copyright notice in the Description page of Project Settings.

#include "AIController.h"
#include "EnemyCharacter.h"

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

FVector AEnemyCharacter::GetPathpointLocation()
{
	AActor* CurrentPatrolPathActor = PatrolPaths[CurrentPathIndex];
	FVector PathpointLocation = CurrentPatrolPathActor->GetActorLocation();
	return PathpointLocation;
}

bool AEnemyCharacter::CheckPathValidity()
{
	bool bCheckPathValidity = PatrolPaths.IsValidIndex(CurrentPathIndex + PathDirection);
	return bCheckPathValidity;
}

FRotator AEnemyCharacter::GetPatrolPathActorRotation()
{
	AActor* CurrentPatrolPathActor = PatrolPaths[CurrentPathIndex];
	return CurrentPatrolPathActor->GetActorRotation();
}

void AEnemyCharacter::Increment()
{
	CurrentPathIndex = CurrentPathIndex + PathDirection;
}

void AEnemyCharacter::Restart()
{
	PathDirection = PathDirection * -1;
}