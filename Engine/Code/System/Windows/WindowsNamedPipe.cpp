/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 15:31)

#include "System/SystemExport.h"

#include "WindowsNamedPipe.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

bool System::CreateSystemPipe(WindowsHandlePtr readPipe, WindowsHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowsDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CreatePipe(readPipe, writePipe, pipeAttributes, size) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(readPipe, writePipe, pipeAttributes, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemPipe(WindowsHandle pipeHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::CloseHandle(pipeHandle) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(pipeHandle);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
