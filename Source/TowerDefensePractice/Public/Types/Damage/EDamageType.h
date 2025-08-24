#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EDamageType : uint8
{
    Physical UMETA(DisplayName = "Physical"),
    Fire     UMETA(DisplayName = "Fire"),
    Cold     UMETA(DisplayName = "Cold"),
    Lightning UMETA(DisplayName = "Lightning"),
    Poison   UMETA(DisplayName = "Poison"),
};