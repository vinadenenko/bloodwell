// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy/EnemyBase.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void AEnemyBase::ApplyDamage(const FDamageInfo& Damage)
{
	float Resistance = 0;//Resistances.Contains(Damage.DamageType) ? Resistances[Damage.DamageType] : 0.0f;
	float EffectiveDamage = Damage.Amount * (1.0f - Resistance);

	CurrentHealth -= EffectiveDamage;

	if (CurrentHealth <= 0.0f)
	{
		Die();
	}
}

void AEnemyBase::Die()
{
	Destroy();
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

