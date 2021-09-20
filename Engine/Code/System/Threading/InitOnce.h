///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.3 (2021/04/25 14:01)

#ifndef SYSTEM_THREADING_INIT_ONCE_H
#define SYSTEM_THREADING_INIT_ONCE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/InitOnceUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE SystemInitOnceInitialize(InitOncePtr initOnce) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowsBoolPtr pending, WindowsVoidPtr* context) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowsVoidPtr context) noexcept;
}

#endif  // SYSTEM_THREADING_INIT_ONCE_H