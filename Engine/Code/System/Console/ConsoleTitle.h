// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.0 (2020/01/02 13:36)

#ifndef SYSTEM_CONSOLE_CONSOLE_TITLE_H
#define SYSTEM_CONSOLE_CONSOLE_TITLE_H

#include "System/SystemDll.h"   

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
	// ����̨�ı�������úͻ�ȡ��

	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleTitle(TChar* consoleTitle, WindowDWord size) noexcept;
	WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleOriginalTitle(TChar* consoleTitle, WindowDWord size) noexcept;
	bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTitle(const TChar* consoleTitle) noexcept;
}

#endif // SYSTEM_CONSOLE_CONSOLE_TITLE_H