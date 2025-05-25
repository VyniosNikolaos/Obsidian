// Copyright 2024 out of sCope team - Michał Ogiński

#pragma once

// ~ Core
#include "CoreMinimal.h"

// ~ Project


#include "GameplayCueManager.h"
#include "ObsidianGameplayCueManager.generated.h"

/**
 * 
 */
UCLASS()
class OBSIDIAN_API UObsidianGameplayCueManager : public UGameplayCueManager
{
	GENERATED_BODY()

protected:
	virtual bool ShouldAsyncLoadRuntimeObjectLibraries() const override;
};
