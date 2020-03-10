// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:38)

#ifndef FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_SYSTEM_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class SystemMiddleLayer : uint32_t 
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