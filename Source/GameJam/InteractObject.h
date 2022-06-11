// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TimelineComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameJamCharacter.h"
#include "InteractObject.generated.h"

UCLASS()
class GAMEJAM_API AInteractObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* Mesh = nullptr;
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root = nullptr;
	UPROPERTY(VisibleAnywhere)
	UBoxComponent* CollisionMesh = nullptr;

	AGameJamCharacter* PlayerCharacter;

	UFUNCTION()
		void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	bool bCanInteract = false;
};
