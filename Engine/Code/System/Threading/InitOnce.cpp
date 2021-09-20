///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.3 (2021/04/26 11:31)

#include "System/SystemExport.h"

#include "InitOnce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

void System::SystemInitOnceInitialize(InitOncePtr initOnce) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    ::InitOnceInitialize(initOnce);

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<InitOncePtr>(initOnce);

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceExecuteOnce(InitOncePtr initOnce, InitOnceFunction initFunction, WindowsVoidPtr parameter, WindowsVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitOnceExecuteOnce(initOnce, initFunction, parameter, context) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<InitOncePtr, InitOnceFunction, WindowsVoidPtr, WindowsVoidPtr*>(initOnce, initFunction, parameter, context);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceBeginInitialize(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowsBoolPtr pending, WindowsVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitOnceBeginInitialize(initOnce, EnumCastUnderlying(flags), pending, context) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<InitOncePtr, InitOnceBeginInitialize, WindowsBoolPtr, WindowsVoidPtr*>(initOnce, flags, pending, context);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceComplete(InitOncePtr initOnce, InitOnceBeginInitialize flags, WindowsVoidPtr context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::InitOnceComplete(initOnce, EnumCastUnderlying(flags), context) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    NullFunction<InitOncePtr, InitOnceBeginInitialize, WindowsVoidPtr>(initOnce, flags, context);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
