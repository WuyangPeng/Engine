// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 10:59)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_FLAGS_H
#define SYSTEM_THREADING_CONDITION_VARIABLE_FLAGS_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	enum class ConditionVariableLockMode
	{
		Exclusive = 0x0,
		Shared = CONDITION_VARIABLE_LOCKMODE_SHARED,
	};

#else // !SYSTEM_PLATFORM_WIN32	

	enum class ConditionVariableLockMode
	{
		Exclusive = 0x0,
		Shared = 0x1,
	};

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_CONDITION_VARIABLE_FLAGS_H