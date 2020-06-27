// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 11:34)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H

#include "System/SystemDll.h"

#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 线程局部存储

	WindowDWord SYSTEM_DEFAULT_DECLARE ThreadLocalStorageAlloc() noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsThreadLocalStorageValid(WindowDWord threadLocalStorageIndex) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex, WindowVoidPtr threadLocalStorageValue) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ThreadLocalStorageFree(WindowDWord threadLocalStorageIndex) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_H