// Fill out your copyright notice in the Description page of Project Settings.


#include "LA_PlayerSpawningManagmentComponent.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Player/LyraPlayerController.h"
#include "Teams/LyraTeamSubsystem.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LA_PlayerSpawningManagmentComponent)

class AActor;

ULA_PlayerSpawningManagmentComponent::ULA_PlayerSpawningManagmentComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

AActor* ULA_PlayerSpawningManagmentComponent::OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts)
{
	ULyraTeamSubsystem* TeamSubsystem = GetWorld()->GetSubsystem<ULyraTeamSubsystem>();
	if (!ensure(TeamSubsystem))
	{
		return nullptr;
	}

	const int32 PlayerTeamId = TeamSubsystem->FindTeamFromObject(Player);
	if (!ensure(PlayerTeamId != INDEX_NONE))
	{
		return nullptr;
	}

	if(ALyraPlayerBotController* AIController = Cast<ALyraPlayerBotController>(Player))
	{
		ALyraPlayerStart* PlayerStart = AIController->GetLAPlayerStart();
		if(IsValid(PlayerStart))
		{
			return PlayerStart;
		}
	}
	else if(ALyraPlayerController* PLC = Cast<ALyraPlayerController>(Player))
	{
		for (TActorIterator<APlayerStart> It(GetWorld()); It; ++It)
		{
			if (APlayerStart* PlayerStart = *It)
			{
				if(ALyraPlayerStart* start = Cast<ALyraPlayerStart>(PlayerStart))
				{
					if(start->PlayerStartTag.IsEqual("TeamSelfMain"))
					{
						return start;
					}
				}
			}
		}
	}
	
	return nullptr;
}

void ULA_PlayerSpawningManagmentComponent::OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation)
{
	
}
