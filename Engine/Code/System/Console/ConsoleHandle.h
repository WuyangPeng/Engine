// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:35)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// ����̨����Ļ�ȡ�����á�

	WindowHandle SYSTEM_DEFAULT_DECLARE GetStandardHandle(StandardHandle standardhandle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE IsHandleValid(WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardhandle, WindowHandle handle) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardhandle, WindowHandle handle, WindowHandlePtr previousHandle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_HANDLE_H