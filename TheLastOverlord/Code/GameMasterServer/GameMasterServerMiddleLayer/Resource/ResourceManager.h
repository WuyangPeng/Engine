// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 15:51)

#ifndef GAME_MASTER_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define GAME_MASTER_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "GameMasterServer/GameMasterServerMiddleLayer/GameMasterServerMiddleLayerDll.h"

#include "GameMasterServer/GameMasterServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ResourceManagerInterface.h" 

namespace GameMasterServerMiddleLayer
{
	class GAME_MASTER_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
	{
	public:
		using ClassType = ResourceManager;
		using ParentType = Framework::ResourceManagerInterface;
		
	public:
		ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ResourceManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GAME_MASTER_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
