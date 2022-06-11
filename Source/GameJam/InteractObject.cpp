// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractObject.h"

// Sets default values
AInteractObject::AInteractObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	CollisionMesh = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision Mesh"));

	CollisionMesh->OnComponentBeginOverlap.AddDynamic(this, &AInteractObject::OnBoxBeginOverlap);
}

// Called when the game starts or when spawned
void AInteractObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractObject::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PlayerCharacter = Cast<AGameJamCharacter>(OtherActor);
	if (IsValid(PlayerCharacter))
	{
		bCanInteract = true;
	}
	if (bCanInteract && PlayerCharacter->bIsInteractCalled)
	{
		PlayerCharacter->SwitchesLeft = PlayerCharacter->SwitchesLeft - 1;
	}

}

