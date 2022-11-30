///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/19 23:03)

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