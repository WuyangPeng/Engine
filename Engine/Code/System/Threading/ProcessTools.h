///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/19 23:04)

#ifndef SYSTEM_THREADING_PROCESS_TOOLS_H
#define SYSTEM_THREADING_PROCESS_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // ���̹���

    NODISCARD bool SYSTEM_DEFAULT_DECLARE OpenSysemProcessToken(WindowsHandle process,
                                                                TokenStandardAccess standardAccess,
                                                                TokenSpecificAccess specificAccess,
                                                                WindowsHandlePtr tokenHandle) noexcept;
}

#endif  // SYSTEM_THREADING_PROCESS_TOOLS_H