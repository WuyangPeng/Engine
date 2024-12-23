/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/26 15:39)

#ifndef SYSTEM_WINDOWS_WINDOW_NAMED_PIPE_H
#define SYSTEM_WINDOWS_WINDOW_NAMED_PIPE_H

#include "System/SystemDll.h"

#include "Using/WindowsUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// �����ܵ��Ĵ����͹رա�
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemPipe(WindowsHandlePtr readPipe,
                                                           WindowsHandlePtr writePipe,
                                                           WindowSecurityAttributesPtr pipeAttributes,
                                                           WindowsDWord size) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemPipe(WindowsHandle pipeHandle) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOW_NAMED_PIPE_H