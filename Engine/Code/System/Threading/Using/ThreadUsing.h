// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:12)

#ifndef SYSTEM_THREADING_THREAD_USING_H
#define SYSTEM_THREADING_THREAD_USING_H  

#include "System/Helper/Platform.h" 
#include "System/Helper/WindowsMacro.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	using ThreadHandle = HANDLE;
	using ThreadHandlePtr = PHANDLE;
	using ThreadStartRoutine = PTHREAD_START_ROUTINE;
	using StartAddress = unsigned(__stdcall*)(void*);

#else // !SYSTEM_PLATFORM_WIN32	

	using ThreadHandle = pthread_t;
	using ThreadHandlePtr = ThreadHandle*;
	using ThreadStartRoutine = WindowDWord(SYSTEM_WINAPI*)(void* threadParameter);

	using StartAddress = unsigned(__stdcall*) (void*);

#endif // SYSTEM_PLATFORM_WIN32	 
}

#endif // SYSTEM_THREADING_THREAD_USING_H