// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 14:37)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
#define ROBOT_CLIENT_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerDll.h"

#include "RobotClient/RobotClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h" 

namespace RobotClientMiddleLayer
{
	class ROBOT_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE PhysicalModellingManager : public Framework::PhysicalModellingManagerInterface
	{
	public:
		using ClassType = PhysicalModellingManager;
		using ParentType = Framework::PhysicalModellingManagerInterface;
		
	public:
		explicit PhysicalModellingManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~PhysicalModellingManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // ROBOT_CLIENT_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
