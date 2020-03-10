// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:28)

#include "System/SystemExport.h"

#include "WindowsInternet.h" 
#include "Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/WindowsMacro.h"
#include "System/EnumOperator/EnumCastDetail.h"

bool System
	::IsInternetAttemptConnect() noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::InternetAttemptConnect(0) == EnumCastUnderlying<WindowDWord>(WinSockLastError::ErrorSuccess))
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::InternetHandle System
	::GetInternetOpenHandle(const TChar* agent, InternetOpenType accessType, const TChar* proxy, const TChar* proxyBypass, InternetType flags) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return InternetOpen(agent, EnumCastUnderlying(accessType), proxy, proxyBypass, EnumCastUnderlying(flags));
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(agent);
	SYSTEM_UNUSED_ARG(accessType);
	SYSTEM_UNUSED_ARG(proxy);
	SYSTEM_UNUSED_ARG(proxyBypass);
	SYSTEM_UNUSED_ARG(flags);

	return nullptr;
#endif // SYSTEM_PLATFORM_WIN32	
}

System::InternetHandle System
	::GetInternetOpenUrl(InternetHandle internet, const TChar* url, const TChar* headers, WindowDWord headersLength, InternetType flags, WindowPtrDWord context) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	return ::InternetOpenUrl(internet, url, headers, headersLength, EnumCastUnderlying(flags), context);
#else // !WIN32
	SYSTEM_UNUSED_ARG(internet);
	SYSTEM_UNUSED_ARG(url);
	SYSTEM_UNUSED_ARG(headers);
	SYSTEM_UNUSED_ARG(headersLength);
	SYSTEM_UNUSED_ARG(flags);
	SYSTEM_UNUSED_ARG(context);

	return nullptr;
#endif // WIN32	
}

bool System
	::GetHttpQueryInfo(InternetHandle request, QueryInfo infoLevel, WindowVoidPtr buffer, WindowDWord* bufferLength, WindowDWord* index) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::HttpQueryInfo(request, EnumCastUnderlying(infoLevel), buffer, bufferLength, index) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(request);
	SYSTEM_UNUSED_ARG(infoLevel);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(bufferLength);
	SYSTEM_UNUSED_ARG(index);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::ReadFileInternet(InternetHandle file, WindowVoidPtr buffer, WindowDWord numberOfBytesToRead, WindowDWord* numberOfBytesRead) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::InternetReadFile(file, buffer, numberOfBytesToRead, numberOfBytesRead) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(file);
	SYSTEM_UNUSED_ARG(buffer);
	SYSTEM_UNUSED_ARG(numberOfBytesToRead);
	SYSTEM_UNUSED_ARG(numberOfBytesRead);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}

bool System
	::InternetCloseHandle(InternetHandle internet) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32	
	if (::InternetCloseHandle(internet) != g_False)
		return true;
	else
		return false;
#else // !SYSTEM_PLATFORM_WIN32
	SYSTEM_UNUSED_ARG(internet);

	return false;
#endif // SYSTEM_PLATFORM_WIN32	
}
