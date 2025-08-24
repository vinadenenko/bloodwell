// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Types/Damage/FDamageInfo.h"
#include "EnemyBase.generated.h"


UCLASS()
class TOWERDEFENSEPRACTICE_API AEnemyBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyBase();

	UFUNCTION(BlueprintCallable)
	virtual void ApplyDamage(const FDamageInfo& Damage);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override

	UFUNCTION(BlueprintCallable);
	bool IsDead() const { return CurrentHealth <= 0; }
	virtual void Die();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Stats")
	float MaxHealth = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy Stats")
	float CurrentHealth;
};
