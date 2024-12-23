/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 15:39)

#ifndef SYSTEM_WINDOWS_WINDOW_NAMED_PIPE_H
#define SYSTEM_WINDOWS_WINDOW_NAMED_PIPE_H

#include "System/SystemDll.h"

#include "Using/WindowsUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

/// 命名管道的创建和关闭。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CreateSystemPipe(WindowsHandlePtr readPipe,
                                                           WindowsHandlePtr writePipe,
                                                           WindowSecurityAttributesPtr pipeAttributes,
                                                           WindowsDWord size) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE CloseSystemPipe(WindowsHandle pipeHandle) noexcept;
}

#endif  // SYSTEM_WINDOWS_WINDOW_NAMED_PIPE_H