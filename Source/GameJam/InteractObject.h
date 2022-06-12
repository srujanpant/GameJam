// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
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

	UPROPERTY()
		bool bActive;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		USphereComponent* CollectionRange;

	AGameJamCharacter* PlayerCharacter;
public:
	void Interacted();
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		bool isFuse = false;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool bWidgetDisplay = false;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		bool bFuseDisplay = false;
};
