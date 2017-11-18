// Fill out your copyright notice in the Description page of Project Settings.

#include "Barrack.h"



// Sets default values
ABarrack::ABarrack()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	StartPoint = CreateDefaultSubobject<USceneComponent>("BegPoint");
	FinPoint = CreateDefaultSubobject<USceneComponent>("FigPoint");
	//FinPoint->SetWorldLocation((-10, 180, 119));
	//StaticMesh'/Engine/BasicShapes/Cube.Cube' 
	ConstructorHelpers::FObjectFinder<UStaticMesh>loadedMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (loadedMesh.Object)
	{
		Mesh->SetStaticMesh(loadedMesh.Object);
	}

	RootComponent = Mesh;
	

}

// Called when the game starts or when spawned
void ABarrack::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		auto Instance = GetGameInstance();
		if (Instance)
		{

			UMyGameInstance* GameInstance = Cast<UMyGameInstance>(Instance);
			if (GameInstance)
				GameInstance->OnClickReleased.BindUObject(this, &ABarrack::SetFinPointLocation);
		}
	}

	FTimerHandle TimerH;
	//ABarrack::MySpawnBarrackUnit();
	GetWorldTimerManager().SetTimer(TimerH, this, &ABarrack::MySpawnBarrackUnit, 5, true);

	
}

// Called every frame
void ABarrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ComponentLocation = FinPoint->GetComponentLocation();
	//GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("Location: %f, %f, %f"), ABarrack::ComponentLocation.X,
		//ABarrack::ComponentLocation.Y, ABarrack::ComponentLocation.Z));

}

void ABarrack::MySpawnBarrackUnit()
{
	AActor* MyChar = this->GetWorld()->SpawnActor(ABarrackUnit::StaticClass(), &(StartPoint->GetComponentTransform()));//GetWorld()->SpawnActor(, StartPoint->ComponentToWorld);
	UMoveComponent* MoveComonent_add = NewObject<UMoveComponent>(MyChar, UMoveComponent::StaticClass(), TEXT("MoveComponent"));
	MoveComonent_add->RegisterComponent();
	MoveComonent_add->FinallyPoint = FinPoint->GetComponentLocation();
}

void ABarrack::SetFinPointLocation(FVector V)
{
	FinPoint->SetRelativeLocation(V);
}

