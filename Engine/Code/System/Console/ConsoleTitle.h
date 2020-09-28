//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:42)

#ifndef SYSTEM_CONSOLE_CONSOLE_TITLE_H
#define SYSTEM_CONSOLE_CONSOLE_TITLE_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ����̨�ı�������úͻ�ȡ��

    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleTitle(TChar* consoleTitle, WindowDWord size) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleOriginalTitle(TChar* consoleTitle, WindowDWord size) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE SetSystemConsoleTitle(const TChar* consoleTitle) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_TITLE_H