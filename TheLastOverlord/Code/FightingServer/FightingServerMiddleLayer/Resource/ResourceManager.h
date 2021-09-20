// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 09:51)

#ifndef FIGHTING_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define FIGHTING_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "FightingServer/FightingServerMiddleLayer/FightingServerMiddleLayerDll.h"

#include "FightingServer/FightingServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ResourceManagerInterface.h" 

namespace FightingServerMiddleLayer
{
	class FIGHTING_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
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

#endif // FIGHTING_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
