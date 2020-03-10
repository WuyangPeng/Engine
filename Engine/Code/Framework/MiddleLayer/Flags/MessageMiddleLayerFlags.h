// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 11:37)

#ifndef FRAMEWORK_MESSAGE_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_MESSAGE_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class MessageMiddleLayer : uint32_t
	{ 
		ObjectLogic, 
		System,

		Count,
	};
	
} 	

#endif // FRAMEWORK_MESSAGE_MANAGER_INTERFACE_FLAGS_H