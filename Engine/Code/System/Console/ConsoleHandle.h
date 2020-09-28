//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:40)

#ifndef SYSTEM_CONSOLE_CONSOLE_HANDLE_H
#define SYSTEM_CONSOLE_CONSOLE_HANDLE_H

#include "System/SystemDll.h"

#include "Fwd/ConsoleFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����̨����Ļ�ȡ�����á�

    [[nodiscard]] WindowHandle SYSTEM_DEFAULT_DECLARE GetStandardHandle(StandardHandle standardhandle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsHandleValid(WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardhandle, WindowHandle handle) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetStandardHandle(StandardHandle standardhandle, WindowHandle handle, WindowHandlePtr previousHandle) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_HANDLE_H