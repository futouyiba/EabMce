//Copyright @Elliot Yun | Release Date: 2018

#include "MCELibrary.h"
#include "MultiplayerCombatEditor.h"

//this library makes us able to expose new things to blueprints when needed
//right now it's only about spawning custom actor component classes and bitmasks check but it can be extended in future MCE versions

//adding new custom components to any actor (callable in Blueprint)
UActorComponent* UMCELibrary::AddCustomActorComponent(AActor* TargetParent, TSubclassOf<UActorComponent> NewComponent)
{
	//just making sure the user does not specify a null class / outer
	if (NewComponent && TargetParent)
	{
		//spawning the component
		UActorComponent* TempNewComponent = NewObject<UActorComponent>(TargetParent, NewComponent);
		
		//turning on the component
		TempNewComponent->RegisterComponent();

		//returning the component for the user to do something with it if needed (as it's often the case)
		return TempNewComponent;
	}
	else
	{
		return nullptr;
	}
}

//checking if a bitmask has a specified enum
bool UMCELibrary::HasFlag(const INT32& FlagList, uint8 CheckedFlag)
{
	INT32 bitFlag = static_cast<int32>(1 << (INT32)CheckedFlag);
	return (FlagList & bitFlag) != 0;
}


