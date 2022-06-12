// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractObject.h"

// Sets default values
AInteractObject::AInteractObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bActive = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	CollectionRange = CreateDefaultSubobject<USphereComponent>(TEXT("CollectionRange"));
	CollectionRange->SetupAttachment(RootComponent);
	CollectionRange->SetSphereRadius(100.f);
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
	Interacted();
}

void AInteractObject::Interacted()
{
	if (CollectionRange != nullptr)
	{
		TArray<AActor*> inRangeItems;
		CollectionRange->GetOverlappingActors(inRangeItems);

		for (int i = 0; i < inRangeItems.Num(); i++)
		{
			PlayerCharacter = Cast<AGameJamCharacter>(inRangeItems[i]);
		}

		if (PlayerCharacter != nullptr && !isFuse)
		{
			bWidgetDisplay = true;
		}

		if (PlayerCharacter != nullptr && isFuse)
		{
			bFuseDisplay = true;

			if (PlayerCharacter->SwitchesLeft < 1)
			{
				bInteractFuse = true;
			}
		}

		if (PlayerCharacter == nullptr )
		{
			bWidgetDisplay = false;
			bFuseDisplay = false;
			bInteractFuse = false;
		}

		if (PlayerCharacter != nullptr && PlayerCharacter->bIsInteractCalled)
		{
			if (!isFuse)
			{
				PlayerCharacter->SwitchesLeft = PlayerCharacter->SwitchesLeft - 1;
				bWidgetDisplay = false;
				CollectionRange->DestroyComponent();
				PlayerCharacter->bIsInteractCalled = false;
				CollectionRange = nullptr;
				UE_LOG(LogTemp, Warning, TEXT("des"));
			}
			else if(isFuse && PlayerCharacter->SwitchesLeft < 1)
			{
				PlayerCharacter->FuseLeft = PlayerCharacter->FuseLeft - 1;
				bFuseDisplay = false;
				bInteractFuse = false;
				CollectionRange->DestroyComponent();
				PlayerCharacter->bIsInteractCalled = false;
				CollectionRange = nullptr;
				UE_LOG(LogTemp, Warning, TEXT("des fuz"));
			}

		}
	}
}
