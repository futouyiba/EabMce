//Copyright @Elliot Yun | Release Date: 2018

#include "MCEActorComponent.h"
#include "MultiplayerCombatEditor.h"

//this class is the parent class of most of the actor components MCE uses for its core systems
//for now the class does nothing but do not consider it to be useless!
//creating this class gives me the possibility to add any function to these components without reparenting 'MCEActorComponent' which avoid any quirks when users update the plugin


// Sets default values for this component's properties
UMCEActorComponent::UMCEActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMCEActorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMCEActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}



