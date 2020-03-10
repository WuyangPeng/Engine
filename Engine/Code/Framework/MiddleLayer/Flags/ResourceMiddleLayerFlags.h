// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:38)

#ifndef FRAMEWORK_RESOURCE_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_RESOURCE_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class ResourceMiddleLayer : uint32_t 
	{ 
		System,
		Audio, 
		Rendering,
		GUI,

		Count,
	};
	
} 	 

#endif // FRAMEWORK_RESOURCE_MANAGER_INTERFACE_FLAGS_H