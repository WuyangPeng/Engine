///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/30 18:08)

#include "System/SystemExport.h"

#include "OutputDebugString.h"
#include "System/Helper/Platform.h"
#include "System/Helper/Tools.h"

void System::OutputDebugStringWithChar(const char* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::OutputDebugStringA(outputString);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(outputString);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::OutputDebugStringWithWChar(const wchar_t* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::OutputDebugStringW(outputString);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(outputString);

#endif  // SYSTEM_PLATFORM_WIN32
}

void System::OutputDebugStringWithTChar(const TChar* outputString) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::OutputDebugString(outputString);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(outputString);

#endif  // SYSTEM_PLATFORM_WIN32
}
