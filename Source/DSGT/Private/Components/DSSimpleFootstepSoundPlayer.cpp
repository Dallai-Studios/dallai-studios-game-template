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

void UDSSimpleFootstepSoundPlayer::StopAllFootstepSounds() {
	if (this->walkSoundTimeHandler.IsValid()) this->GetWorld()->GetTimerManager().ClearTimer(this->walkSoundTimeHandler);
	if (this->runningSoundTimeHandler.IsValid()) this->GetWorld()->GetTimerManager().ClearTimer(this->runningSoundTimeHandler);
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
		if (physMaterial) this->PlayFootstepSound(physMaterial->SurfaceType, false);
	}
}

void UDSSimpleFootstepSoundPlayer::DetectAndPlayRunningSoundBasedOnSurface() {
	FHitResult hitResult;
    	auto startLocation = this->GetOwner()->GetActorLocation();
    	auto endLocation = startLocation + ((this->GetOwner()->GetActorUpVector() * -1) * this->floorDetectionLineSize);
    	FCollisionQueryParams params;
    	FCollisionResponseParams responseParams;
    
    	bool hit = this->GetWorld()->LineTraceSingleByChannel(hitResult, startLocation, endLocation, ECC_Visibility, params, responseParams);
    
    	if (hit) {
    		UPhysicalMaterial* physMaterial = hitResult.PhysMaterial.Get();
    		if (physMaterial) this->PlayFootstepSound(physMaterial->SurfaceType, true);
    	}
}

void UDSSimpleFootstepSoundPlayer::PlayFootstepSound(EPhysicalSurface surface, bool characterIsRunning) {
	float pitch = characterIsRunning ? this->pitchVariationWhenCharacterIsRunning : 1;

	TObjectPtr<USoundBase> soundToPlay = this->concreteFootstepSound;
	
	if (surface == EPhysicalSurface::SurfaceType1) soundToPlay = this->concreteFootstepSound;
	if (surface == EPhysicalSurface::SurfaceType2) soundToPlay = this->woodFootstepSound;
	if (surface == EPhysicalSurface::SurfaceType3) soundToPlay = this->grassFootstepSound;

	UGameplayStatics::PlaySound2D(this->GetWorld(), soundToPlay, 1, pitch);
}	