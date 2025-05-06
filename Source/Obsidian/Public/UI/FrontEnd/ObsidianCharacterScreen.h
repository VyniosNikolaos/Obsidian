// Copyright 2024 out of sCope team - Michał Ogiński

#pragma once

#include "CoreMinimal.h"
#include "UI/ObsidianActivatableWidget.h"
#include "ObsidianCharacterScreen.generated.h"

class UObsidianCharacterEntry;
class AObsidianFrontEndGameMode;
class UCommonHierarchicalScrollBox;
class UCommonTextBlock;
class UObsidianButtonBase;
/**
 * 
 */
UCLASS()
class OBSIDIAN_API UObsidianCharacterScreen : public UObsidianActivatableWidget
{
	GENERATED_BODY()

public:
	virtual UWidget* NativeGetDesiredFocusTarget() const override;

	UFUNCTION(BlueprintCallable, Category = "Obsidian|CharacterScreen")
	void InitializeOnlineCharacterScreen();
	UFUNCTION(BlueprintCallable, Category = "Obsidian|CharacterScreen")
	void InitializeOfflineCharacterScreen();

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeOnActivated() override;

	void OnPlayClicked();

	void PopulateCharacterScreen();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Obsidian")
	TSubclassOf<UCommonActivatableWidget> OnlineLobbyWidgetClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Obsidian")
	TSubclassOf<UObsidianCharacterEntry> CharacterEntryWidgetClass;

	UPROPERTY()
	TObjectPtr<AObsidianFrontEndGameMode> FrontEndGameMode;

	UPROPERTY()
	TArray<TObjectPtr<UObsidianCharacterEntry>> CharacterEntries; 

	UPROPERTY(BlueprintReadOnly)
	bool bIsOnline = false;
	
protected:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonHierarchicalScrollBox> CharacterList_ScrollBox;
	
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UObsidianButtonBase> Play_Button;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UObsidianButtonBase> Create_Button;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UObsidianButtonBase> Delete_Button;

	UPROPERTY(meta=(BindWidget))
	TObjectPtr<UCommonTextBlock> TabName_TextBlock;
};
