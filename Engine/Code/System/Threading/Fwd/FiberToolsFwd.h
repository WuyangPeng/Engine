// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_FWD_H
#define SYSTEM_THREADING_FIBER_TOOLS_FWD_H  

#include "System/Threading/Using/FiberToolsUsing.h"

namespace System
{
	WindowDWord SystemFlsAlloc(FlsCallbackFunction callback) noexcept;
	WindowVoidPtr GetFlsValue(WindowDWord flsIndex) noexcept;
	bool SetFlsValue(WindowDWord flsIndex, WindowVoidPtr flsData) noexcept;
	bool SystemFlsFree(WindowDWord flsIndex) noexcept;

	bool IsSystemThreadAFiber() noexcept;
	void SwitchToSystemFiber(WindowVoidPtr fiber) noexcept;
	WindowVoidPtr ConvertThreadToSystemFiber(WindowVoidPtr parameter) noexcept;
	bool ConvertSystemFiberToThread()  noexcept;

	WindowVoidPtr CreateSystemFiber(WindowSize stackSize, FiberStartRoutine startAddress, WindowVoidPtr parameter) noexcept;
	void DeleteSystemFiber(WindowVoidPtr fiber) noexcept;
}

#endif // SYSTEM_THREADING_FIBER_TOOLS_FWD_H