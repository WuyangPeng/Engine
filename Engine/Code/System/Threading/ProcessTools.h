///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:04)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_H
#define SYSTEM_THREADING_PROCESS_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 进程工具

    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenSysemProcessToken(WindowsHandle process,
                                                                TokenStandardAccess standardAccess,
                                                                TokenSpecificAccess specificAccess,
                                                                WindowsHandlePtr tokenHandle) noexcept;
}

#endif  // SYSTEM_THREADING_PROCESS_TOOLS_H