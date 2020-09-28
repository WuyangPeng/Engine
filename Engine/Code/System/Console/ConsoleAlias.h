//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/23 0:38)

#ifndef SYSTEM_CONSOLE_CONSOLE_ALIAS_H
#define SYSTEM_CONSOLE_CONSOLE_ALIAS_H

#include "System/SystemDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ���Ӻͻ�ȡ����̨������

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE AddSystemConsoleAlias(TChar* source, TChar* target, TChar* exeName) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAlias(TChar* source, TChar* targetBuffer, WindowDWord targetBufferLength, TChar* exeName) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliasesLength(TChar* exeName) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliasExesLength() noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliases(TChar* aliasBuffer, WindowDWord aliasBufferLength, TChar* exeName) noexcept;
    [[nodiscard]] WindowDWord SYSTEM_DEFAULT_DECLARE GetSystemConsoleAliasExes(TChar* exeNameBuffer, WindowDWord exeNameBufferLength) noexcept;
}

#endif  // SYSTEM_CONSOLE_CONSOLE_ALIAS_H