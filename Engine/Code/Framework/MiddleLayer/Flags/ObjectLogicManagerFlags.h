// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:47)

#ifndef FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class ObjectLogicMiddleLayer
	{
		Input,
		Network,
		PhysicalModelling,
		Message,
		System,

		Count,
	};
}

#endif // FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H