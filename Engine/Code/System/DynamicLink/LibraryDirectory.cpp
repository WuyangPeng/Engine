///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:58)

#include "System/SystemExport.h"

#include "LibraryDirectory.h"
#include "System/Helper/WindowsMacro.h"

bool System::SetLibraryDirectory(const DynamicLinkCharType* pathName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetDllDirectory(pathName) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pathName);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetLibraryDirectory(WindowsDWord bufferLength, DynamicLinkCharType* buffer) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetDllDirectory(bufferLength, buffer);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(bufferLength, buffer);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
