// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:25)

#ifndef SYSTEM_NETWORK_WINDOWS_INTERNET_FWD_H 
#define SYSTEM_NETWORK_WINDOWS_INTERNET_FWD_H  

#include "NetworkFlagsFwd.h"
#include "System/Network/Using/WindowsInternetUsing.h" 

namespace System
{
	bool IsInternetAttemptConnect() noexcept;
	InternetHandle GetInternetOpenHandle(const TChar* agent, InternetOpenType accessType, const TChar* proxy, const TChar* proxyBypass, InternetType flags) noexcept;

	InternetHandle GetInternetOpenUrl(InternetHandle internet, const TChar* url, const TChar* headers, WindowDWord headersLength, InternetType flags, WindowPtrDWord context) noexcept;

	bool GetHttpQueryInfo(InternetHandle request, QueryInfo infoLevel, WindowVoidPtr buffer, WindowDWord* bufferLength, WindowDWord* index) noexcept;

	bool ReadFileInternet(InternetHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWord* numberOfBytesRead) noexcept;

	bool InternetCloseHandle(InternetHandle internet) noexcept;
}

#endif // SYSTEM_NETWORK_WINDOWS_INTERNET_FWD_H