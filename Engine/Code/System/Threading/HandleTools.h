//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:24)

#ifndef SYSTEM_THREADING_HANLDE_TOOLS_H
#define SYSTEM_THREADING_HANLDE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/ThreadUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // �߳̾������

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetThreadHandleInformation(ThreadHandle object, HandleInformation mask, HandleInformation flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetThreadHandleInformation(ThreadHandle object, HandleInformation* flags) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE DuplicateThreadHandle(WindowHandle sourceProcessHandle, ThreadHandle sourceHandle, WindowHandle targetProcessHandle, ThreadHandlePtr targetHandle,
                                                                    WindowDWord desiredAccess, bool inheritHandle, DuplicateOptions options) noexcept;
}

#endif  // SYSTEM_THREADING_HANLDE_TOOLS_H