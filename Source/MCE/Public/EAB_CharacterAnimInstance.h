// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EAB_CharacterAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MCE_API UEAB_CharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

	public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Speed;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsAccelerating;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FullBody;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Direction;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsStunned;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USoundBase* FootstepSoundBase;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	USoundBase* LandedSoundBase;

	UFUNCTION()
	void AnimNotify_OrionFootstep(UAnimNotify* Notify);

	
};
