// Copyright Daniel Orchard 2021. All Rights Reserved.


#include "SubtitleRichTextBlock.h"
#include "SubtitleManager.h"

#define LOCTEXT_NAMESPACE "SubtitleHook"

USubtitleRichTextBlock::USubtitleRichTextBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bAutoSetTextToSubtitle = true;
	FSubtitleManager::GetSubtitleManager()->OnSetSubtitleText().AddUObject(this, &USubtitleRichTextBlock::OnSubtitleReceived);
}

void USubtitleRichTextBlock::OnSubtitleReceived(const FText& InText)
{
	if (bAutoSetTextToSubtitle)
	{
		SetText(InText);
	}
	OnSubtitleReceivedDelegate.Broadcast(InText);
}

#if WITH_EDITOR
const FText USubtitleRichTextBlock::GetPaletteCategory()
{
	return LOCTEXT("Subtitles", "Subtitles");
}

void USubtitleRichTextBlock::OnCreationFromPalette()
{
	Text = LOCTEXT("SubtitleTextBlockDefaultValue", "Subtitle");
}
#endif

#undef LOCTEXT_NAMESPACE