// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:37)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
#define GATEWAY_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerDll.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/MessageManagerInterface.h" 

namespace GatewayServerMiddleLayer
{
	class GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE MessageManager : public Framework::MessageManagerInterface
	{
	public:
		using ClassType = MessageManager;
		using ParentType = Framework::MessageManagerInterface;
		
	public:
		MessageManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~MessageManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GATEWAY_SERVER_MIDDLE_LAYER_MESSAGE_MIDDLE_LAYER_MESSAGE_H
