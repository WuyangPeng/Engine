// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.1 (2019/10/11 11:37)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define GATEWAY_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerDll.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/NetworkManagerInterface.h" 

namespace GatewayServerMiddleLayer
{
	class GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager : public Framework::NetworkManagerInterface
	{
	public:
		using ClassType = NetworkManager;
		using ParentType = Framework::NetworkManagerInterface;
		
	public:
		NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~NetworkManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GATEWAY_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
