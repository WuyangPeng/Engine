// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:13)

#ifndef SYSTEM_THREADING_HANLDE_TOOLS_H
#define SYSTEM_THREADING_HANLDE_TOOLS_H

#include "System/SystemDll.h" 

#include "Using/ThreadUsing.h"
#include "Fwd/ThreadingFlagsFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// �߳̾������

	bool SYSTEM_DEFAULT_DECLARE SetThreadHandleInformation(ThreadHandle object, HandleInformation mask, HandleInformation flags) noexcept;
	bool SYSTEM_DEFAULT_DECLARE	GetThreadHandleInformation(ThreadHandle object, HandleInformation* flags) noexcept;
	bool SYSTEM_DEFAULT_DECLARE DuplicateThreadHandle(WindowHandle sourceProcessHandle, ThreadHandle sourceHandle, WindowHandle targetProcessHandle, ThreadHandlePtr targetHandle,
													  WindowDWord desiredAccess, bool inheritHandle, DuplicateOptions options) noexcept;
}

#endif // SYSTEM_THREADING_HANLDE_TOOLS_H