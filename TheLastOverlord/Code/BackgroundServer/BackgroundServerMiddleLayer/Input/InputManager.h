// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 18:10)

#ifndef BACKGROUND_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
#define BACKGROUND_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H

#include "BackgroundServer/BackgroundServerMiddleLayer/BackgroundServerMiddleLayerDll.h"

#include "BackgroundServer/BackgroundServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/InputManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

namespace BackgroundServerMiddleLayer
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

#endif // BACKGROUND_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
