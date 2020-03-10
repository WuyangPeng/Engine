// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:12)

#ifndef SYSTEM_THREADING_EVENT_H
#define SYSTEM_THREADING_EVENT_H

#include "System/SystemDll.h" 

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
	// 事件对象

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, const TChar* name, CreateEventType flag,
														  MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess) noexcept;

	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, bool manualReset, bool initialState, const TChar* name) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE CreateSystemEvent(bool manualReset, bool initialState) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemEvent(WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemEvent(WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ResetSystemEvent(WindowHandle handle) noexcept;

	bool SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowHandle handle) noexcept;

	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn SYSTEM_DEFAULT_DECLARE WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;
	WindowHandle SYSTEM_DEFAULT_DECLARE OpenSystemEvent(MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsSystemEventValid(WindowHandle eventHandle) noexcept;
}

#endif // SYSTEM_THREADING_EVENT_H