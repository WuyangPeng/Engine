// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/12 18:18)

#ifndef RECHARGE_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
#define RECHARGE_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H

#include "RechargeServer/RechargeServerMiddleLayer/RechargeServerMiddleLayerDll.h"

#include "RechargeServer/RechargeServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/RenderingManagerInterface.h" 

namespace RechargeServerMiddleLayer
{
	class RECHARGE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE RenderingManager : public Framework::RenderingManagerInterface
	{
	public:
		using ClassType = RenderingManager;
		using ParentType = Framework::RenderingManagerInterface;
		
	public:
		RenderingManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~RenderingManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // RECHARGE_SERVER_MIDDLE_LAYER_RENDERING_MIDDLE_LAYER_RENDERING_H
