//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:25)

#ifndef SYSTEM_THREADING_INIT_ONCE_H
#define SYSTEM_THREADING_INIT_ONCE_H

#include "System/SystemDll.h"

#include "Fwd/ThreadingFlagsFwd.h"
#include "Using/InitOnceUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    void SYSTEM_DEFAULT_DECLARE SystemInitOnceInitialize(InitOncePtr initOnce) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowVoidPtr parameter, WindowVoidPtr* context) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowBoolPtr pending, WindowVoidPtr* context) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowVoidPtr context) noexcept;
}

#endif  // SYSTEM_THREADING_INIT_ONCE_H