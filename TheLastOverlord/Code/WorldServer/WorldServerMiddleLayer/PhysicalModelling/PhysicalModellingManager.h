// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 13:12)

#ifndef WORLD_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
#define WORLD_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H

#include "WorldServer/WorldServerMiddleLayer/WorldServerMiddleLayerDll.h"

#include "WorldServer/WorldServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h" 

namespace WorldServerMiddleLayer
{
	class WORLD_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE PhysicalModellingManager : public Framework::PhysicalModellingManagerInterface
	{
	public:
		using ClassType = PhysicalModellingManager;
		using ParentType = Framework::PhysicalModellingManagerInterface;
		
	public:
		PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~PhysicalModellingManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // WORLD_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
