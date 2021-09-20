// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 最后的霸王版本：0.0.0.0 (2019/10/10 14:35)

#ifndef ROBOT_CLIENT_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
#define ROBOT_CLIENT_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H

#include "RobotClient/RobotClientMiddleLayer/RobotClientMiddleLayerDll.h"

#include "RobotClient/RobotClientMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/NetworkManagerInterface.h" 

namespace RobotClientMiddleLayer
{
	class ROBOT_CLIENT_MIDDLE_LAYER_DEFAULT_DECLARE NetworkManager : public Framework::NetworkManagerInterface
	{
	public:
		using ClassType = NetworkManager;
		using ParentType = Framework::NetworkManagerInterface;
		
	public:
		explicit NetworkManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~NetworkManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // ROBOT_CLIENT_MIDDLE_LAYER_NETWORK_MIDDLE_LAYER_NETWORK_H
