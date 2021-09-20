// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���İ����汾��0.0.0.1 (2019/10/11 11:37)

#ifndef GATEWAY_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
#define GATEWAY_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H

#include "GatewayServer/GatewayServerMiddleLayer/GatewayServerMiddleLayerDll.h"

#include "GatewayServer/GatewayServerMiddleLayer/Macro/ExportMacro.h" 
#include "Framework/MiddleLayer/ObjectLogicInterface.h" 

namespace GatewayServerMiddleLayer
{
	class GATEWAY_SERVER_MIDDLE_LAYER_DEFAULT_DECLARE ObjectLogicManager : public Framework::ObjectLogicInterface
	{
	public:
		using ClassType = ObjectLogicManager;
		using ParentType = Framework::ObjectLogicInterface;
		
	public:
		ObjectLogicManager(Framework::MiddleLayerPlatform middleLayerPlatform);
		virtual ~ObjectLogicManager();

		CLASS_INVARIANT_OVERRIDE_DECLARE; 
	};
}

#endif // GATEWAY_SERVER_MIDDLE_LAYER_OBJECT_LOGIC_MIDDLE_LAYER_OBJECT_LOGIC_H
