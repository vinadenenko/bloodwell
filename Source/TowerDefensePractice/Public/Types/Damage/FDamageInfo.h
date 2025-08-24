#pragma once

#include "EDamageType.h"
#include "FDamageInfo.generated.h"

USTRUCT(BlueprintType)

struct FDamageInfo
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Amount = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EDamageType DamageType = EDamageType::Physical;

    FDamageInfo() {}
    FDamageInfo(float InAmount, EDamageType InType)
        : Amount(InAmount), DamageType(InType) {
    }
};

