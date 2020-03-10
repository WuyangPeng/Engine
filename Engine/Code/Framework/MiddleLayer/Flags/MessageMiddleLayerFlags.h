// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 11:37)

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