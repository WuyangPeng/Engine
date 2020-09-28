//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/27 14:14)

#include "System/SystemExport.h"

#include "ComObjectBase.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::ComRegisterClassObject([[maybe_unused]] const SystemCLSID& rclsid, [[maybe_unused]] SystemIUnknown* unknown, [[maybe_unused]] ClsContext clsContext, [[maybe_unused]] RegCls flags, [[maybe_unused]] WindowDWord* registration) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::CoRegisterClassObject(rclsid, unknown, EnumCastUnderlying(clsContext), EnumCastUnderlying(flags), registration)))
        return false;
    else
        return true;
    ;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ComRevokeClassObject([[maybe_unused]] WindowDWord registerMagicCookie) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::CoRevokeClassObject(registerMagicCookie)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ConversionStringFromCLSID([[maybe_unused]] const SystemCLSID& rclsid, [[maybe_unused]] TChar** result) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (IsFailed(::StringFromCLSID(rclsid, result)))
        return false;
    else
        return true;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

void System::ComTaskMemFree([[maybe_unused]] WindowVoidPtr pv) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::CoTaskMemFree(pv);
#else  // !SYSTEM_PLATFORM_WIN32

#endif  // SYSTEM_PLATFORM_WIN32
}
