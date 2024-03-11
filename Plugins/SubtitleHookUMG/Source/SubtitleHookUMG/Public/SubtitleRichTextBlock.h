// Copyright Daniel Orchard 2021. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/RichTextBlock.h"
#include "SubtitleRichTextBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSubtitleReceivedSignature, const FText&, InSubtitle);

UCLASS()
class SUBTITLEHOOKUMG_API USubtitleRichTextBlock : public URichTextBlock
{
	GENERATED_BODY()

public:

	USubtitleRichTextBlock(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	void OnSubtitleReceived(const FText& InText);

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Subtitles")
	bool bAutoSetTextToSubtitle;


#if WITH_EDITOR
	//~ Begin UWidget Interface
	virtual const FText GetPaletteCategory() override;
	virtual void OnCreationFromPalette() override;
	//~ End UWidget Interface
#endif

	UPROPERTY(BlueprintAssignable, Category = "Subtitles")
	FOnSubtitleReceivedSignature OnSubtitleReceivedDelegate;
	
};
