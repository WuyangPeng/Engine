// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 09:55)

#ifndef CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H
#define CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H

#include "System/Helper/ConfigMacro.h"

namespace CoreTools
{
	enum class UniqueIDSelect
	{
		Default = 0,
		MemoryInformation = 1,
		Object = 2,
		ResourceHandle = 3,
		Resource = 4,
		Entity = 5,
		Network = 6,
		Max,
	};
}

#endif // CORE_TOOLS_BASE_UNIQUE_ID_SELECT_H