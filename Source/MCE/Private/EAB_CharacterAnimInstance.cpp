// Fill out your copyright notice in the Description page of Project Settings.


#include "EAB_CharacterAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UEAB_CharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (auto Pawn = TryGetPawnOwner())
	{
		Speed = Pawn -> GetVelocity().Size();
		if (const auto Character = Cast<ACharacter>(Pawn))
		{
			IsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > .0f;
		}
		FullBody = GetCurveValue(L"Fullbody")>.0f;
		Direction = CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
		// todo add stun & slow & dizzy etc...
		
	}
}
