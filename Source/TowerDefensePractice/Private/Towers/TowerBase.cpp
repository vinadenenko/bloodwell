// Fill out your copyright notice in the Description page of Project Settings.


#include "Towers/TowerBase.h"


// Sets default values
ATowerBase::ATowerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    RangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("RangeSphere"));
    RangeSphere->InitSphereRadius(500.f);
    RangeSphere->SetCollisionProfileName(TEXT("Trigger"));
    RootComponent = RangeSphere;
}

// Called when the game starts or when spawned
void ATowerBase::BeginPlay()
{
	Super::BeginPlay();

    RangeSphere->OnComponentBeginOverlap.AddDynamic(this, &ATowerBase::OnRangeBeginOverlap);
    RangeSphere->OnComponentEndOverlap.AddDynamic(this, &ATowerBase::OnRangeEndOverlap);

    GetWorldTimerManager().SetTimer(AttackTimer, this, &ATowerBase::Attack, 1.0f / AttackRate, true);
}
void ATowerBase::Attack()
{
	if (AEnemyBase* Target = FindTarget())
	{
		Target->ApplyDamage(Damage);
	}
}
AEnemyBase* ATowerBase::FindTarget()
{
    /*TArray<AActor*> Enemies;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyBase::StaticClass(), Enemies);

    for (AActor* Actor : Enemies)
    {
        if (FVector::Dist(Actor->GetActorLocation(), GetActorLocation()) <= AttackRange)
        {
            return Cast<AEnemyBase>(Actor);
        }
    }
    return nullptr;*/
    return nullptr;
}
void ATowerBase::OnRangeBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(
        -1,            // Key: -1 for a unique message (or a specific key to update an existing message)
        5.f,           // Duration: How long the message stays on screen (in seconds)
        FColor::Red,   // Color: The color of the text
        TEXT("Overlap") // Message: The string to display, wrapped in TEXT()
    );
}
void ATowerBase::OnRangeEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor != this)
    {
        UE_LOG(LogTemp, Log, TEXT("Enemy left range: %s"), *OtherActor->GetName());
    }
}
#include "Engine.h" 
// Called every frame
void ATowerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

