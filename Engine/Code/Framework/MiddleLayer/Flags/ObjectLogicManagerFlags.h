// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:38)

#ifndef FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H
#define FRAMEWORK_OBJECT_LOGIC_MANAGER_INTERFACE_FLAGS_H

#include "System/Helper/ConfigMacro.h"

namespace Framework
{
	enum class ObjectLogicMiddleLayer : uint32_t 
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