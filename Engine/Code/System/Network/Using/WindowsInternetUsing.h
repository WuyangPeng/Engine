// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.0 (2020/01/02 15:26)

#ifndef SYSTEM_NETWORK_WINDOWS_INTERNET_USING_H
#define SYSTEM_NETWORK_WINDOWS_INTERNET_USING_H

#include "System/Helper/Platform.h"

#ifdef SYSTEM_PLATFORM_WIN32	
	#include <WinInet.h>
#endif // SYSTEM_PLATFORM_WIN32

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

	using InternetHandle = HINTERNET;
	using InternetStatusCallback = INTERNET_STATUS_CALLBACK;
	using Groupid = GROUPID;
	using SystemTime = SYSTEMTIME;
	using InternetScheme = INTERNET_SCHEME;
	using UrlComponents = URL_COMPONENTS;
	using UrlComponentsPtr = LPURL_COMPONENTS;
	using InternetPort = INTERNET_PORT;
	using InternetBuffers = INTERNET_BUFFERS;
	using InternetBuffersPtr = LPINTERNET_BUFFERS;
	using GopherFindData = GOPHER_FIND_DATA;
	using GopherFindDataPtr = LPGOPHER_FIND_DATA;

#else // !SYSTEM_PLATFORM_WIN32	

	using InternetHandle = void*;
	using InternetStatusCallback = void(*)(InternetHandle internet, WindowPtrDWord context, WindowDWord internetStatus,
										   WindowVoidPtr statusInformation, WindowDWord statusInformationLength);
	using Groupid = uint64_t;

	struct SystemTime
	{
		WindowWord wYear;
		WindowWord wMonth;
		WindowWord wDayOfWeek;
		WindowWord wDay;
		WindowWord wHour;
		WindowWord wMinute;
		WindowWord wSecond;
		WindowWord wMilliseconds;
	};

	enum InternetScheme
	{
		INTERNET_SCHEME_PARTIAL = -2,
		INTERNET_SCHEME_UNKNOWN = -1,
		INTERNET_SCHEME_DEFAULT = 0,
		INTERNET_SCHEME_FTP,
		INTERNET_SCHEME_GOPHER,
		INTERNET_SCHEME_HTTP,
		INTERNET_SCHEME_HTTPS,
		INTERNET_SCHEME_FILE,
		INTERNET_SCHEME_NEWS,
		INTERNET_SCHEME_MAILTO,
		INTERNET_SCHEME_SOCKS,
		INTERNET_SCHEME_JAVASCRIPT,
		INTERNET_SCHEME_VBSCRIPT,
		INTERNET_SCHEME_RES,
		INTERNET_SCHEME_FIRST = INTERNET_SCHEME_FTP,
		INTERNET_SCHEME_LAST = INTERNET_SCHEME_RES
	};

	struct UrlComponents
	{
		WindowDWord dwStructSize;
		TChar* lpszScheme;
		WindowDWord dwSchemeLength;
		InternetScheme nScheme;
		TChar* lpszHostName;
		WindowDWord dwHostNameLength;
		uint16_t nPort;
		TChar* lpszUserName;
		WindowDWord dwUserNameLength;
		TChar* lpszPassword;
		WindowDWord dwPasswordLength;
		TChar* lpszUrlPath;
		WindowDWord dwUrlPathLength;
		TChar* lpszExtraInfo;
		WindowDWord dwExtraInfoLength;
	};

	using UrlComponentsPtr = UrlComponents*;
	using InternetPort = uint16_t;

	struct InternetBuffers
	{
		WindowDWord dwStructSize;
		InternetBuffers* Next;
		const TChar*  lpcszHeader;
		WindowDWord dwHeadersLength;
		WindowDWord dwHeadersTotal;
		void* lpvBuffer;
		WindowDWord dwBufferLength;
		WindowDWord dwBufferTotal;
		WindowDWord dwOffsetLow;
		WindowDWord dwOffsetHigh;
	};
	using InternetBuffersPtr = InternetBuffers*;

	constexpr int maxGopherDisplayTest{ 128 };

	struct GopherFindData
	{
		TChar  DisplayString[maxGopherDisplayTest + 1];
		WindowDWord GopherType;
		WindowDWord SizeLow;
		WindowDWord SizeHigh;
		FileTime LastModificationTime;
		TChar  Locator[maxGopherDisplayTest + 1];
	};
	using GopherFindDataPtr = GopherFindData*;

#endif // SYSTEM_PLATFORM_WIN32    		 
}

#endif // SYSTEM_NETWORK_WINDOWS_INTERNET_USING_H