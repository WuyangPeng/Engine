// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:50)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ObjectLogicInterface.h" 

namespace GameMasterServerMiddleLayer
{
	class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ObjectLogicManager : public Framework::ObjectLogicInterface
	{
	public:
		using ClassType = ObjectLogicManager;
		using ParentType = Framework::ObjectLogicInterface;
		
	public:
		ObjectLogicManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ObjectLogicManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GAME_MASTER_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
