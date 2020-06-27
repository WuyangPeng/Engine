// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.2.0.0 (2020/05/10 11:27)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_H
#define SYSTEM_THREADING_FIBER_TOOLS_H

#include "System/SystemDll.h" 

#include "Using/FiberToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 纤程的创建和销毁

	WindowDWord SYSTEM_DEFAULT_DECLARE SystemFlsAlloc(FlsCallbackFunction callback) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetFlsValue(WindowDWord flsIndex) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetFlsValue(WindowDWord flsIndex, WindowVoidPtr flsData) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SystemFlsFree(WindowDWord flsIndex) noexcept;

	bool SYSTEM_DEFAULT_DECLARE IsSystemThreadAFiber() noexcept;
	void SYSTEM_DEFAULT_DECLARE SwitchToSystemFiber(WindowVoidPtr fiber) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE ConvertThreadToSystemFiber(WindowVoidPtr parameter) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ConvertSystemFiberToThread()  noexcept;

	WindowVoidPtr SYSTEM_DEFAULT_DECLARE CreateSystemFiber(WindowSize stackSize, FiberStartRoutine startAddress, WindowVoidPtr parameter) noexcept;
	void SYSTEM_DEFAULT_DECLARE DeleteSystemFiber(WindowVoidPtr fiber) noexcept;
}

#endif // SYSTEM_THREADING_FIBER_TOOLS_H