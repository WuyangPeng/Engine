/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/27 18:03)

#include "System/SystemExport.h"

#include "InitOnce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

void System::SystemInitOnceInitialize(InitOncePtr initOnce) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::InitOnceInitialize(initOnce);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(initOnce);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InitOnceExecuteOnce(initOnce, initFunction, parameter, context) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(initOnce, initFunction, parameter, context);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowsBoolPtr pending, WindowsVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InitOnceBeginInitialize(initOnce, EnumCastUnderlying(flags), pending, context) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(initOnce, flags, pending, context);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowsVoidPtr context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::InitOnceComplete(initOnce, EnumCastUnderlying(flags), context) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(initOnce, flags, context);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
