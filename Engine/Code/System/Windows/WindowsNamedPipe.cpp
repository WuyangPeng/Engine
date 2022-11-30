///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:16)

#include "System/SystemExport.h"

#include "WindowsNamedPipe.h"
#include "System/Helper/WindowsMacro.h"

bool System::CreateSystemPipe(WindowsHandlePtr readPipe, WindowsHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowsDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CreatePipe(readPipe, writePipe, pipeAttributes, size) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(readPipe, writePipe, pipeAttributes, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemPipe(WindowsHandle pipeHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::CloseHandle(pipeHandle) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pipeHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
