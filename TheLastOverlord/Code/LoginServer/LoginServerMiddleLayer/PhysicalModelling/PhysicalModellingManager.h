// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 14:07)

#ifndef LOGIN_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
#define LOGIN_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H

#include "LoginServer/LoginServerMiddleLayer/LoginServerMiddleLayerDll.h"

#include "LoginServer/LoginServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/PhysicalModellingManagerInterface.h" 

namespace LoginServerMiddleLayer
{
	class LOGIN_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE PhysicalModellingManager : public Framework::PhysicalModellingManagerInterface
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

#endif // LOGIN_SERVER_MIDDLE_LAYER_PHYSICAL_MODELLING_MIDDLE_LAYER_PHYSICAL_MODELLING_H
