//Copyright @Elliot Yun | Release Date: 2018

#pragma once

#include "Modules/ModuleManager.h"
#include "Engine.h"

//General Log
DECLARE_LOG_CATEGORY_EXTERN(YourLog, Log, All);

class FMultiplayerCombatEditorModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};