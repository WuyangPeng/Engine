// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 16:37)

#ifndef SYSTEM_WINDOW_WINDOW_NAMED_PIPE_H
#define SYSTEM_WINDOW_WINDOW_NAMED_PIPE_H

#include "System/SystemDll.h"

#include "Using/WindowUsing.h"
#include "System/Security/Using/SecurityBaseUsing.h" 

namespace System
{
	// �����ܵ��Ĵ����͹رա�

	bool SYSTEM_DEFAULT_DECLARE CreateSystemPipe(WindowHandlePtr readPipe, WindowHandlePtr writePipe, WindowSecurityAttributesPtr pipeAttributes, WindowDWord size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE CloseSystemPipe(WindowHandle pipeHandle) noexcept;
}

#endif // SYSTEM_WINDOW_WINDOW_NAMED_PIPE_H