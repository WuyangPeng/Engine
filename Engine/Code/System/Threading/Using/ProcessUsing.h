// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.2.0.0 (2020/05/10 11:18)

#ifndef SYSTEM_THREADING_PROCESS_USING_H
#define SYSTEM_THREADING_PROCESS_USING_H  

#include "System/Helper/Platform.h" 

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using ProcessStartupinfo = STARTUPINFO;
	using ProcessStartupinfoPtr = LPSTARTUPINFO;
	using ProcessInformation = PROCESS_INFORMATION;
	using ProcessInformationPtr = LPPROCESS_INFORMATION;
	using ProcessStartupinfoEx = STARTUPINFOEX;
	using ProcessStartupinfoExPtr = LPSTARTUPINFOEX;

#else // !SYSTEM_PLATFORM_WIN32	 

	struct ProcessStartupinfo
	{
		uint32_t cb;
		TChar* lpReserved;
		TChar* lpDesktop;
		TChar* lpTitle;
		uint32_t dwX;
		uint32_t dwY;
		uint32_t dwXSize;
		uint32_t dwYSize;
		uint32_t dwXCountChars;
		uint32_t dwYCountChars;
		uint32_t dwFillAttribute;
		uint32_t dwFlags;
		int wShowWindow;
		int cbReserved2;
		uint8_t* lpReserved2;
		void* hStdInput;
		void* hStdOutput;
		void* hStdError;
	};

	using ProcessStartupinfoPtr = ProcessStartupinfo*;

	struct ProcessInformation
	{
		void* hProcess;
		void* hThread;
		uint32_t dwProcessId;
		uint32_t dwThreadId;
	};

	using ProcessInformationPtr = ProcessInformation * ;

	struct ProcessStartupinfoEx
	{
		ProcessStartupinfo StartupInfo;
		ProcThreadAttributeListPtr lpAttributeList;
	};
	using ProcessStartupinfoExPtr = ProcessStartupinfoEx*;

#endif // SYSTEM_PLATFORM_WIN32	 
}

#endif // SYSTEM_THREADING_PROCESS_USING_H