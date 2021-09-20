///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/22 11:36)

#include "System/SystemExport.h"

#include "OutputDebugString.h"
#include "System/Helper/Platform.h"

void System::OutputDebugStringWithChar(const char* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::OutputDebugStringA(outputString);
#else  // !SYSTEM_PLATFORM_WIN32
    NullFunction<const char*>(outputString);
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::OutputDebugStringWithWChar(const wchar_t* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::OutputDebugStringW(outputString);
#else  // !SYSTEM_PLATFORM_WIN32
    NullFunction<const wchar_t*>(outputString);
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::OutputDebugStringWithTChar(const TChar* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::OutputDebugString(outputString);
#else  // !SYSTEM_PLATFORM_WIN32
    NullFunction<const TChar*>(outputString);
#endif  // SYSTEM_PLATFORM_WIN32
}
