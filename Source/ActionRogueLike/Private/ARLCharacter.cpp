// Fill out your copyright notice in the Description page of Project Settings.


#include "ARLCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AARLCharacter::AARLCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Instantiate (create instance) our components
	// CreateDefaultSubobject<type of object to create>("Object name (for editor only)");
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArmComponent->SetupAttachment(RootComponent); // Attaches our SpringArm to the root component
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent); // Attaches our Camera to our SpringArm
	
}

// Called when the game starts or when spawned
void AARLCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AARLCharacter::MoveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AARLCharacter::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}


// Called every frame
void AARLCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AARLCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Map keys to functions to facilitate movement
	// Two functions to map keys to function
	// BindAxis() & BindAction()
	// BindAxis has a range from -1 to 1
	// Where as BindAction only allows 0 or 1
	PlayerInputComponent->BindAxis("MoveForward", this, &AARLCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AARLCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

