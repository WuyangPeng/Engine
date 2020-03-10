// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_HANLDE_TOOLS_H
#define SYSTEM_THREADING_HANLDE_TOOLS_H

#include "System/SystemDll.h" 

#include "Using/ThreadUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// 线程句柄工具

	bool SYSTEM_DEFAULT_DECLARE SetThreadHandleInformation(ThreadHandle object, HandleInformation mask, HandleInformation flags) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	GetThreadHandleInformation(ThreadHandle object, HandleInformation* flags) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DuplicateThreadHandle(WindowHandle sourceProcessHandle, ThreadHandle sourceHandle, WindowHandle targetProcessHandle, ThreadHandlePtr targetHandle,
													  WindowDWord desiredAccess, bool inheritHandle, DuplicateOptions options) noexcept;
}

#endif // SYSTEM_THREADING_HANLDE_TOOLS_H