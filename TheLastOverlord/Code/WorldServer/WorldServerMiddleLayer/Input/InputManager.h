// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:10)

#ifndef WORLD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
#define WORLD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H

#include "WorldServer/WorldServerMiddleLayer/WorldServerMiddleLayerDll.h"

#include "WorldServer/WorldServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/InputManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

namespace WorldServerMiddleLayer
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

#endif // WORLD_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
