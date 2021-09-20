// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 最后的霸王版本：0.0.0.1 (2019/10/13 19:00)

#ifndef UPDATE_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define UPDATE_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "UpdateServer/UpdateServerMiddleLayer/UpdateServerMiddleLayerDll.h"

#include "UpdateServer/UpdateServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/NetworkManagerInterface.h" 

namespace UpdateServerMiddleLayer
{
	class UPDATE_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager : public Framework::NetworkManagerInterface
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

#endif // UPDATE_SERVER_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
