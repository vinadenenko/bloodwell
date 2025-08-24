// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Enemy/EnemyBase.h"

#include "TowerBase.generated.h"

UCLASS()
class TOWERDEFENSEPRACTICE_API ATowerBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATowerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Attack();
	virtual AEnemyBase* FindTarget();

	// Collision range
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Tower")
	class USphereComponent* RangeSphere;
	
	UFUNCTION()
	void OnRangeBeginOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION()
	void OnRangeEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	float AttackRange = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	float AttackRate = 1.0f; // attacks per second

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Tower Stats")
	FDamageInfo Damage;

	FTimerHandle AttackTimer;
};
