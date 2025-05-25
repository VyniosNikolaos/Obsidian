// Copyright 2024 out of sCope team - Michał Ogiński

#pragma once

// ~ Core
#include "CoreMinimal.h"

// ~ Project


#include "AbilitySystem/Abilities/ObsidianGameplayAbility.h"
#include "ObsidianGameplayAbility_Aura.generated.h"

/**
 * 
 */
UCLASS()
class OBSIDIAN_API UObsidianGameplayAbility_Aura : public UObsidianGameplayAbility
{
	GENERATED_BODY()

public:
	UObsidianGameplayAbility_Aura();
	
protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

protected:
	/** Aura effect that will be applied to user */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Obsidian|AbilitySetup")
	TSubclassOf<UGameplayEffect> AuraEffectClass;

	/** Tag to identify this effect while displaying it on the UI. Should be child of "UI.EffectData.Aura" */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(Categories = "UI.EffectData.Aura"), Category = "Obsidian|AbilitySetup")
	FGameplayTag EffectUIInfoTag;

private:
	FActiveGameplayEffectHandle AuraEffectHandle;

	TObjectPtr<const UObsidianAbilitySystemComponent> ObsidianASC;
};
