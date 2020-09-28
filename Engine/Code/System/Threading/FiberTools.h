//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 15:18)

#ifndef SYSTEM_THREADING_FIBER_TOOLS_H
#define SYSTEM_THREADING_FIBER_TOOLS_H

#include "System/SystemDll.h"

#include "Using/FiberToolsUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // �˳̵Ĵ���������

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE SystemFlsAlloc(FlsCallbackFunction callback) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE GetFlsValue(WindowDWord flsIndex) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetFlsValue(WindowDWord flsIndex, WindowVoidPtr flsData) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SystemFlsFree(WindowDWord flsIndex) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsSystemThreadAFiber() noexcept;
    void SYSTEM_DEFAULT_DECLARE SwitchToSystemFiber(WindowVoidPtr fiber) noexcept;
    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE ConvertThreadToSystemFiber(WindowVoidPtr parameter) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ConvertSystemFiberToThread() noexcept;

    [[nodiscard]] WindowVoidPtr SYSTEM_DEFAULT_DECLARE CreateSystemFiber(WindowSize stackSize, FiberStartRoutine startAddress, WindowVoidPtr parameter) noexcept;
    void SYSTEM_DEFAULT_DECLARE DeleteSystemFiber(WindowVoidPtr fiber) noexcept;
}

#endif  // SYSTEM_THREADING_FIBER_TOOLS_H