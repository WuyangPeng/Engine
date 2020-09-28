//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/27 14:43)

#include "System/SystemExport.h"

#include "WindowNamedPipe.h"
#include "System/Helper/WindowsMacro.h"

bool System::CreateSystemPipe([[maybe_unused]] WindowHandlePtr readPipe, [[maybe_unused]] WindowHandlePtr writePipe, [[maybe_unused]] WindowSecurityAttributesPtr pipeAttributes, [[maybe_unused]] WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CreatePipe(readPipe, writePipe, pipeAttributes, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::CloseSystemPipe([[maybe_unused]] WindowHandle pipeHandle) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::CloseHandle(pipeHandle) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
