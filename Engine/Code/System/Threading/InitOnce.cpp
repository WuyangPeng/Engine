//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:17)

#include "System/SystemExport.h"

#include "InitOnce.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

void System::SystemInitOnceInitialize([[maybe_unused]] InitOncePtr initOnce) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    ::InitOnceInitialize(initOnce);
#else  // !SYSTEM_PLATFORM_WIN32
    
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceExecuteOnce([[maybe_unused]] InitOncePtr initOnce, [[maybe_unused]] InitOnceFunction initFunction, [[maybe_unused]] WindowVoidPtr parameter, [[maybe_unused]] WindowVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitOnceExecuteOnce(initOnce, initFunction, parameter, context) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceBeginInitialize([[maybe_unused]] InitOncePtr initOnce, [[maybe_unused]] InitOnceBeginInitialize flags, [[maybe_unused]] WindowBoolPtr pending, [[maybe_unused]] WindowVoidPtr* context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitOnceBeginInitialize(initOnce, EnumCastUnderlying(flags), pending, context) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemInitOnceComplete([[maybe_unused]] InitOncePtr initOnce, [[maybe_unused]] InitOnceBeginInitialize flags, [[maybe_unused]] WindowVoidPtr context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InitOnceComplete(initOnce, EnumCastUnderlying(flags), context) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
