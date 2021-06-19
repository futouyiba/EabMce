//Copyright @Elliot Yun | Release Date: 2018

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "MCELibrary.generated.h"

//this library makes us able to expose new things to blueprints when needed
//right now it's only about spawning custom actor component classes and bitmasks check but it can be extended in future MCE versions

UCLASS()
class MULTIPLAYERCOMBATEDITOR_API UMCELibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	public:
	UFUNCTION(BlueprintCallable, Category = "MCE | Library")
	static UActorComponent* AddCustomActorComponent(AActor* TargetParent, TSubclassOf<UActorComponent> NewComponent);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "MCE | Library")
	static bool HasFlag(const int32& FlagList, uint8 CheckedFlag);
};
