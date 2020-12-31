//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 18:04)

#ifndef SYSTEM_NETWORK_WINDOWS_INTERNET_H
#define SYSTEM_NETWORK_WINDOWS_INTERNET_H

#include "System/SystemDll.h"

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/WindowsInternetUsing.h"
#include "Using/WindowsSockExUsing.h"
#include "System/Helper/UnicodeUsing.h"

namespace System
{
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsInternetAttemptConnect() noexcept;

    [[nodiscard]] InternetHandle SYSTEM_DEFAULT_DECLARE GetInternetOpenHandle(const TChar* agent, InternetOpenType accessType, const TChar* proxy,
                                                                              const TChar* proxyBypass, InternetType flags) noexcept;

    [[nodiscard]] InternetHandle SYSTEM_DEFAULT_DECLARE GetInternetOpenUrl(InternetHandle internet, const TChar* url, const TChar* headers,
                                                                           WindowDWord headersLength, InternetType flags, WindowPtrDWord context) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetHttpQueryInfo(InternetHandle request, QueryInfo infoLevel, WindowVoidPtr buffer, WindowDWord* bufferLength, WindowDWord* index) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE ReadFileInternet(InternetHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWord* numberOfBytesRead) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE InternetCloseHandle(InternetHandle internet) noexcept;
}

#endif  // SYSTEM_NETWORK_WINDOWS_INTERNET_H
