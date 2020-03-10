// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_MUTEX_USING_H
#define SYSTEM_THREADING_MUTEX_USING_H  

#include "System/Helper/Platform.h" 
#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32	

	struct PthreadMutexattrT
	{
	};

	using PthreadMutexT = WindowHandle;

#else // !SYSTEM_PLATFORM_WIN32	

	// Linux/Apple�Ļ��������͡�
	using PthreadMutexattrT = pthread_mutexattr_t;
	using PthreadMutexT = pthread_mutex_t;

#endif // SYSTEM_PLATFORM_WIN32

	struct MutexType
	{
		PthreadMutexattrT m_Attribute;
		PthreadMutexT m_Mutex;
	};
}

#endif // SYSTEM_THREADING_MUTEX_USING_H