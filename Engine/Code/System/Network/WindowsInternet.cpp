//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:15)

#include "System/SystemExport.h"

#include "WindowsInternet.h"
#include "Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"

bool System::IsInternetAttemptConnect() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InternetAttemptConnect(0) == EnumCastUnderlying<WindowDWord>(WinSockLastError::ErrorSuccess))
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::InternetHandle System::GetInternetOpenHandle([[maybe_unused]] const TChar* agent, [[maybe_unused]] InternetOpenType accessType, [[maybe_unused]] const TChar* proxy, [[maybe_unused]] const TChar* proxyBypass, [[maybe_unused]] InternetType flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return InternetOpen(agent, EnumCastUnderlying(accessType), proxy, proxyBypass, EnumCastUnderlying(flags));
#else  // !SYSTEM_PLATFORM_WIN32
    return nullptr;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::InternetHandle System::GetInternetOpenUrl([[maybe_unused]] InternetHandle internet, [[maybe_unused]] const TChar* url, [[maybe_unused]] const TChar* headers, [[maybe_unused]] WindowDWord headersLength, [[maybe_unused]] InternetType flags, [[maybe_unused]] WindowPtrDWord context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::InternetOpenUrl(internet, url, headers, headersLength, EnumCastUnderlying(flags), context);
#else  // !WIN32
    return nullptr;
#endif  // WIN32
}

bool System::GetHttpQueryInfo([[maybe_unused]] InternetHandle request, [[maybe_unused]] QueryInfo infoLevel, WindowVoidPtr buffer, [[maybe_unused]] WindowDWord* bufferLength, [[maybe_unused]] WindowDWord* index) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::HttpQueryInfo(request, EnumCastUnderlying(infoLevel), buffer, bufferLength, index) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::ReadFileInternet([[maybe_unused]] InternetHandle file, [[maybe_unused]] WindowVoidPtr buffer, [[maybe_unused]] WindowDWord numberOfBytesToRead, [[maybe_unused]] WindowDWord* numberOfBytesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InternetReadFile(file, buffer, numberOfBytesToRead, numberOfBytesRead) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::InternetCloseHandle([[maybe_unused]] InternetHandle internet) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::InternetCloseHandle(internet) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
