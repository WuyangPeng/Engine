// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 11:48)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
#define GATEWAY_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerDll.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ResourceManagerInterface.h" 

namespace GatewayServerMiddleLayer
{
	class GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ResourceManager : public Framework::ResourceManagerInterface
	{
	public:
		using ClassType = ResourceManager;
		using ParentType = Framework::ResourceManagerInterface;
		
	public:
		ResourceManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ResourceManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GATEWAY_SERVER_MIDDLE_LAYER_RESOURCE_MIDDLE_LAYER_RESOURCE_H
