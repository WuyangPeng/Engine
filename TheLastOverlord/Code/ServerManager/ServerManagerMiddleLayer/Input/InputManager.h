// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 16:49)

#ifndef SERVER_MANAGER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
#define SERVER_MANAGER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H

#include "ServerManager/ServerManagerMiddleLayer/ServerManagerMiddleLayerDll.h"

#include "ServerManager/ServerManagerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/InputManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

namespace ServerManagerMiddleLayer
{
	template <typename ApplicationTrait>
	class InputManager : public Framework::InputManager<ApplicationTrait>
	{
	public:
		using ClassType = InputManager<ApplicationTrait>;
		using ParentType = Framework::InputManager<ApplicationTrait>;
		
	public:
		InputManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~InputManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // SERVER_MANAGER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
