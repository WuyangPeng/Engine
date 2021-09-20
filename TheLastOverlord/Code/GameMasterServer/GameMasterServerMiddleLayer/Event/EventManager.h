// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:48)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/EventManagerInterface.h" 

namespace GameMasterServerMiddleLayer
{
	class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE EventManager : public Framework::EventManagerInterface
	{
	public:
		using ClassType = EventManager;
		using ParentType = Framework::EventManagerInterface;
		
	public:
		EventManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~EventManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GAME_MASTER_SERVER_MIDDLE_LAYER_EVENT_MIDDLE_LAYER_EVENT_H
