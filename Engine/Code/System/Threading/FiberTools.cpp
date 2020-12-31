//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/23 16:12)

#include "System/SystemExport.h"

#include "FiberTools.h"
#include "System/Helper/WindowsMacro.h"

System::WindowDWord System::SystemFlsAlloc([[maybe_unused]] FlsCallbackFunction callback) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FlsAlloc(callback);
#else  // !SYSTEM_PLATFORM_WIN32 
    return 0;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::GetFlsValue([[maybe_unused]] WindowDWord flsIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FlsGetValue(flsIndex);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SetFlsValue([[maybe_unused]] WindowDWord flsIndex, [[maybe_unused]] WindowVoidPtr flsData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FlsSetValue(flsIndex, flsData) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::SystemFlsFree([[maybe_unused]] WindowDWord flsIndex) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::FlsFree(flsIndex) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32 
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::IsSystemThreadAFiber() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::IsThreadAFiber() != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::SwitchToSystemFiber([[maybe_unused]] WindowVoidPtr fiber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::SwitchToFiber(fiber);
#else  // !SYSTEM_PLATFORM_WIN32 

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::ConvertThreadToSystemFiber([[maybe_unused]] WindowVoidPtr parameter) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::ConvertThreadToFiber(parameter);
#else  // !SYSTEM_PLATFORM_WIN32 
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::DeleteSystemFiber([[maybe_unused]] WindowVoidPtr fiber) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::DeleteFiber(fiber);
#else  // !SYSTEM_PLATFORM_WIN32
     
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::CreateSystemFiber([[maybe_unused]] WindowSize stackSize, [[maybe_unused]] FiberStartRoutine startAddress, [[maybe_unused]] WindowVoidPtr parameter) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CreateFiber(stackSize, startAddress, parameter);
#else  // !SYSTEM_PLATFORM_WIN32 

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ConvertSystemFiberToThread() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::ConvertFiberToThread() != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
