// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 17:05)

#ifndef GAME_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
#define GAME_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H

#include "GameServer/GameServerMiddleLayer/GameServerMiddleLayerDll.h"

#include "GameServer/GameServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/InputManager.h"
#include "Framework/Application/Flags/ApplicationTrait.h"

namespace GameServerMiddleLayer
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

#endif // GAME_SERVER_MIDDLE_LAYER_INPUT_ENGINE_MIDDLE_LAYER_INPUT_H
