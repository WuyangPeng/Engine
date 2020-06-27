// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.2.0.0 (2020/05/10 0:08)

#ifndef SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
#define SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/MemoryToolsFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"
#include "System/CharacterString/Using/CodePageUsing.h"

namespace System
{
	// Local�������и���Ŀ��������ṩ�������洢�����������ٵ�������

	bool SYSTEM_DEFAULT_DECLARE LocalMemoryFree(WindowHLocal& memory) noexcept;
	WindowHLocal SYSTEM_DEFAULT_DECLARE LocalMemoryAlloc(LocalMemory flags, WindowSize bytes) noexcept;
	WindowVoidPtr SYSTEM_DEFAULT_DECLARE LocalMemoryLock(WindowHLocal& memory) noexcept;
	bool SYSTEM_DEFAULT_DECLARE LocalMemoryUnlock(WindowHLocal& memory) noexcept;
	WindowHLocal SYSTEM_DEFAULT_DECLARE GetLocalMemoryHandle(WindowConstVoidPtr memory) noexcept;
	WindowSize SYSTEM_DEFAULT_DECLARE GetLocalMemorySize(WindowHLocal& memory) noexcept;

	// ����ֵ�ĵ�λ�ֽڰ������������������Ҫ�ӷ���ֵ����������������ʹ��&�������LockCount���롣
	// ��Fixed������ڴ�����������������Ϊ�㡣����ֵ�ĸ�λ�ֽ�ָʾ�洢������ķ���ֵ��������Ϊ���Discardable��
	WindowUInt SYSTEM_DEFAULT_DECLARE GetLocalMemoryFlags(WindowHLocal& memory) noexcept;
}

#endif // SYSTEM_MEMORY_TOOLS_LOCAL_TOOLS_H
