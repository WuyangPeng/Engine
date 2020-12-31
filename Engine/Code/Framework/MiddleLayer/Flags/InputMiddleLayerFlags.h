// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 14:46)

#ifndef FRAMEWORK_INPUT_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_INPUT_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class InputMiddleLayer
	{
		Network,
		ObjectLogic,
		System,
		CameraSystems,

		Count,
	};
}

#endif // FRAMEWORK_INPUT_MANAGER_INTERFACE_FLAGS_H