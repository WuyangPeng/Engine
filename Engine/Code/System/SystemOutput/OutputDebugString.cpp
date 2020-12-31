//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 9:24)

#include "System/SystemExport.h"

#include "OutputDebugString.h"
#include "System/Helper/Platform.h"

void System::OutputDebugStringWithChar([[maybe_unused]] const char* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::OutputDebugStringA(outputString);
#else  // !SYSTEM_PLATFORM_WIN32
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::OutputDebugStringWithWChar([[maybe_unused]] const wchar_t* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::OutputDebugStringW(outputString);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::OutputDebugStringWithTChar([[maybe_unused]] const TChar* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::OutputDebugString(outputString);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}
