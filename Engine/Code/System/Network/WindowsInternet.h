// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:26)

#ifndef SYSTEM_NETWORK_WINDOWS_INTERNET_H
#define SYSTEM_NETWORK_WINDOWS_INTERNET_H

#include "System/SystemDll.h"  

#include "Fwd/NetworkFlagsFwd.h"
#include "Using/WindowsInternetUsing.h"
#include "Using/WindowsSockExUsing.h" 
#include "System/Helper/UnicodeUsing.h"

namespace System
{
	bool SYSTEM_DEFAULT_DECLARE IsInternetAttemptConnect() noexcept;

	InternetHandle SYSTEM_DEFAULT_DECLARE GetInternetOpenHandle(const TChar* agent, InternetOpenType accessType, const TChar* proxy,
																const TChar* proxyBypass, InternetType flags) noexcept;

	InternetHandle SYSTEM_DEFAULT_DECLARE  GetInternetOpenUrl(InternetHandle internet, const TChar* url, const TChar* headers,
															  WindowDWord headersLength, InternetType flags, WindowPtrDWord context) noexcept;
	bool SYSTEM_DEFAULT_DECLARE GetHttpQueryInfo(InternetHandle request, QueryInfo infoLevel, WindowVoidPtr buffer, WindowDWord* bufferLength, WindowDWord* index) noexcept;
	bool SYSTEM_DEFAULT_DECLARE ReadFileInternet(InternetHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWord* numberOfBytesRead) noexcept;

	bool SYSTEM_DEFAULT_DECLARE InternetCloseHandle(InternetHandle internet) noexcept;
}

#endif // SYSTEM_NETWORK_WINDOWS_INTERNET_H
