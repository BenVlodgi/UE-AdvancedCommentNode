// Copyright 2025 Dream Seed LLC

#pragma once

#include "Modules/ModuleManager.h"

class FAdvancedCommentNodeModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
protected:
	TSharedPtr<class FAdvancedCommentNodeFactory> AdvancedCommentNodeFactory;
};
