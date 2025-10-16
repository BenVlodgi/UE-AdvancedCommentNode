// Copyright 2025 Dream Seed LLC

#pragma once

#include "Modules/ModuleManager.h"

class FAdvancedCommentNodeModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// Enables or disables the module functionality based on whether the module is running and user preferences.
	void UpdateEnabledStatus();
	
protected:
	// Registers or unregisters the node factory.
	void SetEnabled(bool bEnabled);

protected:
	// True once the module has begun startup. False once shutdown starts.
	bool bModuleIsRunning = false;

	// True once the module functionality has been enabled.
	bool bModuleIsEnabled = false;
	
	// Node factory for custom comment nodes.
	TSharedPtr<class FAdvancedCommentNodeFactory> AdvancedCommentNodeFactory;

};
