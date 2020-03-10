// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:38)

#ifndef FRAMEWORK_NETWORK_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_NETWORK_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class NetworkMiddleLayer : uint32_t 
	{
		Input,
		ObjectLogic,

		Count,
	};
	
}
 

#endif // FRAMEWORK_NETWORK_MANAGER_INTERFACE_FLAGS_H