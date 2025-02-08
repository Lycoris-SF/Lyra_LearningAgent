// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LyraPlayerSpawningManagerComponent.h"
#include "Player/LyraPlayerBotController.h"
#include "Player/LyraPlayerStart.h"
#include "LA_PlayerSpawningManagmentComponent.generated.h"

class AActor;
class AController;
class ALyraPlayerStart;
class UObject;

UCLASS()
class ULA_PlayerSpawningManagmentComponent : public ULyraPlayerSpawningManagerComponent
{
	GENERATED_BODY()

public:

	ULA_PlayerSpawningManagmentComponent(const FObjectInitializer& ObjectInitializer);

	virtual AActor* OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts) override;
	virtual void OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation) override;

protected:

};
