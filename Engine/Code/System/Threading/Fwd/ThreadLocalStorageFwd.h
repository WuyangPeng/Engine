// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:11)

#ifndef SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FWD_H
#define SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FWD_H   

namespace System
{
	WindowDWord ThreadLocalStorageAlloc() noexcept;
	bool IsThreadLocalStorageValid(WindowDWord threadLocalStorageIndex) noexcept;
	WindowVoidPtr GetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex) noexcept;
	bool SetThreadLocalStorageValue(WindowDWord threadLocalStorageIndex, WindowVoidPtr threadLocalStorageValue) noexcept;
	bool ThreadLocalStorageFree(WindowDWord threadLocalStorageIndex) noexcept;
}

#endif // SYSTEM_THREADING_THREAD_LOCAL_STORAGE_FWD_H