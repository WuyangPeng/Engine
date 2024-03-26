/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 17:07)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"

/// ��ȡ����ҳ�������Ϣ��
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsCodePageValid(CodePage codePage) noexcept;
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetAnsiCodePage() noexcept;
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetOemCodePage() noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_H
