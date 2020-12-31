//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/22 9:24)

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
