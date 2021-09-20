// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 14:07)

#ifndef OFFLINE_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
#define OFFLINE_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H

#include "OfflineServer/OfflineServerMiddleLayer/OfflineServerMiddleLayerDll.h"

#include "OfflineServer/OfflineServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h" 

namespace OfflineServerMiddleLayer
{
	class OFFLINE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE PhysicalModellingManager : public Framework::PhysicalModellingManagerInterface
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

#endif // OFFLINE_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
