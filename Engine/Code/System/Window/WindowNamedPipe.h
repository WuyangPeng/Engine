//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 11:37)

#ifndef SYSTEM_WINDOW_WINDOW_NAMED_PIPE_H
#define SYSTEM_WINDOW_WINDOW_NAMED_PIPE_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h"

namespace System
{
    // 命名管道的创建和关闭。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CreateSystemPipe(WindowHandlePtr readPipe, WindowHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowDWord size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE CloseSystemPipe(WindowHandle pipeHandle) noexcept;
}

#endif  // SYSTEM_WINDOW_WINDOW_NAMED_PIPE_H