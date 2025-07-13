// Copyright 2024 out of sCope team - Michał Ogiński

#pragma once

// ~ Core
#include "CoreMinimal.h"

// ~ Project


#include "UI/ObsidianWidgetBase.h"
#include "ObsidianSkillPointsNotification.generated.h"

class UButton;
class UCommonTextBlock;

DECLARE_MULTICAST_DELEGATE(FOnSkillPointsNotificationPressedSignature);

/**
 * 
 */
UCLASS()
class OBSIDIAN_API UObsidianSkillPointsNotification : public UObsidianWidgetBase
{
	GENERATED_BODY()

public:
	void SetSkillPointsCount(const float NewPoints) const;

public:
	FOnSkillPointsNotificationPressedSignature OnSkillPointsNotificationPressed;

protected:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnPressed();

protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonTextBlock> SkillPointsCounter_TextBlock;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UButton> OpenTree_Button;
};
