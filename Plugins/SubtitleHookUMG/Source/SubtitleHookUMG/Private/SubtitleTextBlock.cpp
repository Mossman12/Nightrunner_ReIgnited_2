// Copyright Daniel Orchard 2022. All Rights Reserved.


#include "SubtitleTextBlock.h"
#include "Widgets/Text/STextBlock.h"
#include "SubtitleManager.h"

#define LOCTEXT_NAMESPACE "SubtitleHook"

USubtitleTextBlock::USubtitleTextBlock()
	: bAutoSetTextToSubtitle(true)
{
	FSubtitleManager::GetSubtitleManager()->OnSetSubtitleText().AddUObject(this, &USubtitleTextBlock::OnSubtitleReceived);
}

void USubtitleTextBlock::OnSubtitleReceived(const FText& InText)
{
	if (bAutoSetTextToSubtitle)
	{
		SetText(InText);
	}
	OnSubtitleReceivedDelegate.Broadcast(InText);
}

#if WITH_EDITOR
const FText USubtitleTextBlock::GetPaletteCategory()
{
	return LOCTEXT("Subtitles", "Subtitles");
}

void USubtitleTextBlock::OnCreationFromPalette()
{
	SetText(LOCTEXT("SubtitleTextBlockDefaultValue", "Subtitle"));
}
#endif

#undef LOCTEXT_NAMESPACE