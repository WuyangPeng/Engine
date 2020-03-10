// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:14)

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
