// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.3.0.1 (2020/05/27 14:14)

#ifndef FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_FLAGS_H
#define FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class ChildHelperMiddleLayer
	{
		Input,
		ObjectLogic,
		Message,
		Event,
		Resource,
		Audio,
		CameraSystems,
		Rendering,
		Engine,

		Count,
	};
}

#endif // FRAMEWORK_HELPER_SUITE_CHILD_HELPER_INTERFACE_FLAGS_H