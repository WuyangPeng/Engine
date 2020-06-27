// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:03)

#ifndef SYSTEM_THREADING_CONDITION_VARIABLE_USING_H  
#define SYSTEM_THREADING_CONDITION_VARIABLE_USING_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using ConditionVariable = CONDITION_VARIABLE;
	using ConditionVariablePtr = PCONDITION_VARIABLE;

#else // !SYSTEM_PLATFORM_WIN32	

	struct ConditionVariable
	{
		void* Ptr;
	};
	using ConditionVariablePtr = ConditionVariable*;

#endif // SYSTEM_PLATFORM_WIN32
}

#endif // SYSTEM_THREADING_CONDITION_VARIABLE_USING_H