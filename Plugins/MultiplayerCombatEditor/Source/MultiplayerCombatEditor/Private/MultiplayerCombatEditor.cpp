//Copyright @Elliot Yun | Release Date: 2018

#include "MultiplayerCombatEditor.h"

#define LOCTEXT_NAMESPACE "FMultiplayerCombatEditorModule"

//General Log
DEFINE_LOG_CATEGORY(YourLog);

void FMultiplayerCombatEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FMultiplayerCombatEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FMultiplayerCombatEditorModule, MultiplayerCombatEditor)