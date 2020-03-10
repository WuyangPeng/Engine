// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:36)

#ifndef SYSTEM_WINDOW_LAST_PLATFORM_ERROR_FWD_H
#define SYSTEM_WINDOW_LAST_PLATFORM_ERROR_FWD_H

#include "WindowFlagsFwd.h"

namespace System
{
	WindowError GetPlatformLastError() noexcept;
	void SetPlatformLastError(WindowError error) noexcept;
	ErrorMode GetPlatformErrorMode() noexcept;
	ErrorMode SetPlatformErrorMode(ErrorMode flag) noexcept;
}

#endif // SYSTEM_WINDOW_LAST_PLATFORM_ERROR_FWD_H