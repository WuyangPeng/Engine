// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:59)

#ifndef CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_PRIORITY_FLAGS_H
#define CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_PRIORITY_FLAGS_H

#include "System/Helper/EnumMacro.h"

#include <iostream>

namespace CoreTools
{
	enum class EventPriority : uint32_t
	{
		Low,
		Medium,
		High,
	};

	ENUM_LEFT_SHIFTABLE_OPERATOR_DEFINE(EventPriority);
}

#endif // CORE_TOOLS_MESSAGE_EVENT_SUITE_EVENT_PRIORITY_FLAGS_H