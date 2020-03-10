// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 16:10)

#ifndef SYSTEM_THREADING_EVENT_FWD_H
#define SYSTEM_THREADING_EVENT_FWD_H  

#include "ThreadingFlagsFwd.h"

namespace System
{
	WindowHandle CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, const TChar* name, CreateEventType flag,
								   MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess) noexcept;

	WindowHandle CreateSystemEvent(WindowSecurityAttributesPtr securityAttributes, bool manualReset, bool initialState, const TChar* name) noexcept;
	WindowHandle CreateSystemEvent(bool manualReset, bool initialState) noexcept;
	bool CloseSystemEvent(WindowHandle handle) noexcept;
	bool SetSystemEvent(WindowHandle handle) noexcept;
	bool ResetSystemEvent(WindowHandle handle) noexcept;

	bool WaitForSystemEvent(WindowHandle handle) noexcept;
	MutexWaitReturn WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds) noexcept;
	MutexWaitReturn WaitForSystemEvent(WindowHandle handle, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds, bool alertable) noexcept;
	MutexWaitReturn WaitForSystemEvent(WindowDWord count, const WindowHandle* handle, bool waitAll, WindowDWord milliseconds) noexcept;

	WindowHandle OpenSystemEvent(MutexStandardAccess desiredAccess, EventSpecificAccess specificAccess, bool inheritHandle, const TChar* name) noexcept;
	bool IsSystemEventValid(WindowHandle eventHandle) noexcept;
}

#endif // SYSTEM_THREADING_EVENT_FWD_H