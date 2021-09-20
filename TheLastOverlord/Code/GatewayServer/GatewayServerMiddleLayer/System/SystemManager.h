// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:49)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
#define GATEWAY_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerDll.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/SystemManagerInterface.h" 

namespace GatewayServerMiddleLayer
{
	class GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE SystemManager : public Framework::SystemManagerInterface
	{
	public:
		using ClassType = SystemManager;
		using ParentType = Framework::SystemManagerInterface;
		
	public:
		SystemManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~SystemManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GATEWAY_SERVER_MIDDLE_LAYER_SYSTEM_MIDDLE_LAYER_SYSTEM_H
