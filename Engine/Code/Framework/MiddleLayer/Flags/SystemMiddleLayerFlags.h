// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:47)

#ifndef FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class SystemMiddleLayer
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

#endif // FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H