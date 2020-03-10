// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_LAST_PLATFORM_ERROR_H
#define SYSTEM_WINDOW_LAST_PLATFORM_ERROR_H

#include "System/SystemDll.h"

#include "Fwd/WindowFlagsFwd.h"

namespace System
{
	// 获取和设置系统错误码。

	WindowError SYSTEM_DEFAULT_DECLARE GetPlatformLastError() noexcept;
	void SYSTEM_DEFAULT_DECLARE SetPlatformLastError(WindowError error) noexcept;
	ErrorMode SYSTEM_DEFAULT_DECLARE GetPlatformErrorMode() noexcept;
	ErrorMode SYSTEM_DEFAULT_DECLARE SetPlatformErrorMode(ErrorMode flag) noexcept;
}

#endif // SYSTEM_WINDOW_LAST_PLATFORM_ERROR_H
