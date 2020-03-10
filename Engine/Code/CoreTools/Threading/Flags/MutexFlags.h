// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_MUTEX_FLAGS_H
#define CORE_TOOLS_THREADING_MUTEX_FLAGS_H

#include "System/Helper/ConfigMacro.h" 

namespace CoreTools
{
	enum class MutexCreate
	{
		UseDefault,
		UseCriticalSection,
		UseStd,
		UseStdRecursive,
		UseBoost,
		UseBoostRecursive,		
		UseNull,			
	};
}

#endif // CORE_TOOLS_THREADING_MUTEX_FLAGS_H
