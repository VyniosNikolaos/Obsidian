// Copyright 2024 out of sCope team - Michał Ogiński


#include "AbilitySystem/Abilities/ObsidianGameplayAbility_Aura.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/ObsidianAbilitySystemComponent.h"

UObsidianGameplayAbility_Aura::UObsidianGameplayAbility_Aura()
{
	InstancingPolicy = EGameplayAbilityInstancingPolicy::InstancedPerActor;
	
	ActivationPolicy = EObsidianGameplayAbility_ActivationPolicy::EAP_OnInputTriggered;
}

void UObsidianGameplayAbility_Aura::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	if(AuraEffectClass)
	{
		if(AuraEffectHandle.IsValid())
		{
			ObsidianASC = ObsidianASC == nullptr ? Cast<UObsidianAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo()) : ObsidianASC;
			
			BP_RemoveGameplayEffectFromOwnerWithHandle(AuraEffectHandle);
			AuraEffectHandle.Invalidate();
			ObsidianASC->OnAuraDisabledDelegate.ExecuteIfBound(EffectUIInfoTag);
		}
		else
		{
			AuraEffectHandle = ApplyGameplayEffectToOwner(Handle, ActorInfo, ActivationInfo, AuraEffectClass.GetDefaultObject(),
				GetAbilityLevel(), 1);
		}
	}
}


