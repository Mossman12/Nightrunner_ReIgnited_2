// Copyright Daniel Orchard 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextBlock.h"
#include "SubtitleTextBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSubtitleReceived, const FText&, InSubtitle);

UCLASS()
class SUBTITLEHOOKUMG_API USubtitleTextBlock : public UTextBlock
{
	GENERATED_BODY()

public:

	USubtitleTextBlock();

	UFUNCTION()
	void OnSubtitleReceived(const FText& InText);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Subtitles")
	bool bAutoSetTextToSubtitle;

#if WITH_EDITOR
	//~ Begin UWidget Interface
	virtual const FText GetPaletteCategory() override;
	virtual void OnCreationFromPalette() override;
	//~ End UWidget Interface
#endif

	UPROPERTY(BlueprintAssignable, Category="Subtitles")
	FOnSubtitleReceived OnSubtitleReceivedDelegate;
	
};
