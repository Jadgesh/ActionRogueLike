// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ARLCharacter.generated.h"

// Forward declare our components
class UCameraComponent;
class USpringArmComponent;
UCLASS()
class ACTIONROGUELIKE_API AARLCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AARLCharacter();

protected:
	// Components
	UPROPERTY(VisibleAnywhere) // Allows us to see this protected component in the editor
	UCameraComponent* CameraComponent; // Empty pointer called CameraComponent
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent; // Empty pointer called SpringArmComponent
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Movement Functions
	void MoveForward(float value);
	void MoveRight(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
