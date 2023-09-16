///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/28 16:22)

#include "System/SystemExport.h"

#include "ConsoleHandle.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

System::WindowsHandle System::GetStandardHandle(StandardHandle standardHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetStdHandle(EnumCastUnderlying(standardHandle));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardHandle);

    return invalidHandleValue;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsHandleValid(WindowsHandle handle) noexcept
{
    if (handle != invalidHandleValue && handle != nullptr)
        return true;
    else
        return false;
}

bool System::SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetStdHandle(EnumCastUnderlying(standardHandle), handle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardHandle, handle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetStandardHandle(StandardHandle standardHandle, WindowsHandle handle, WindowsHandlePtr previousHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::SetStdHandleEx(EnumCastUnderlying(standardHandle), handle, previousHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(standardHandle, handle, previousHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
