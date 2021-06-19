//Copyright @Elliot Yun | Release Date: 2018

#pragma once

#include "Components/ActorComponent.h"
#include "MCEActorComponent.generated.h"

//this class is the parent class of most of the actor components MCE uses for its core systems
//for now the class does nothing but do not consider it to be useless!
//creating this class gives me the possibility to add any function to these components without reparenting 'MCEActorComponent' which avoid any quirks when users update the plugin

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYERCOMBATEDITOR_API UMCEActorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMCEActorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
