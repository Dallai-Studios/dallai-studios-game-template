// Copyright (c) 2025 Dallai Studios. All Rights Reserved.

#include "Components/DSSimpleFootstepSoundPlayer.h"
#include "Kismet/GameplayStatics.h"

UDSSimpleFootstepSoundPlayer::UDSSimpleFootstepSoundPlayer() {
	PrimaryComponentTick.bCanEverTick = false;
}

void UDSSimpleFootstepSoundPlayer::BeginPlay() {
	Super::BeginPlay();
}

void UDSSimpleFootstepSoundPlayer::PlayWalkFootstepSound() {
	if (this->runningSoundTimeHandler.IsValid()) this->GetWorld()->GetTimerManager().ClearTimer(this->runningSoundTimeHandler);
	
	this->GetWorld()->GetTimerManager().SetTimer(
		this->walkSoundTimeHandler,
		this,
		&UDSSimpleFootstepSoundPlayer::DetectAndPlayWalkSoundBasedOnSurface,
		this->walkTimerRate,
		true
	);
}

void UDSSimpleFootstepSoundPlayer::PlayRunningFootstepSound() {
	if (this->walkSoundTimeHandler.IsValid()) this->GetWorld()->GetTimerManager().ClearTimer(this->walkSoundTimeHandler);
	
	this->GetWorld()->GetTimerManager().SetTimer(
		this->runningSoundTimeHandler,
		this,
		&UDSSimpleFootstepSoundPlayer::DetectAndPlayRunningSoundBasedOnSurface,
		this->runningTimerRate,
		true
	);
}

void UDSSimpleFootstepSoundPlayer::DetectAndPlayWalkSoundBasedOnSurface() {
	FHitResult hitResult;
	auto startLocation = this->GetOwner()->GetActorLocation();
	auto endLocation = startLocation + ((this->GetOwner()->GetActorUpVector() * -1) * this->floorDetectionLineSize);
	FCollisionQueryParams params;
	FCollisionResponseParams responseParams;

	bool hit = this->GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility, params, responseParams);

	if (hit) {
		UPhysicalMaterial* physMaterial = hitResult.PhysMaterial.Get();
		if (physMaterial) {
			EPhysicalSurface surfaceType = physMaterial->SurfaceType;
			switch (surfaceType) {
			case SurfaceType1: // Concrete
				UGameplayStatics::PlaySound2D(this->GetWorld(), this->concreteFootstepSound);
				break;
			case SurfaceType2: // Wood
				UGameplayStatics::PlaySound2D(this->GetWorld(), this->woodFootstepSound);
				break;
			case SurfaceType3: // Grass
				UGameplayStatics::PlaySound2D(this->GetWorld(), this->grassFootstepSound);
				break;
			default:
				UGameplayStatics::PlaySound2D(this->GetWorld(), this->concreteFootstepSound);
				break;
			}
		}
	}
}

void UDSSimpleFootstepSoundPlayer::DetectAndPlayRunningSoundBasedOnSurface() {
	
}

