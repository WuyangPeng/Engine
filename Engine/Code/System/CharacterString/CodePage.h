//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/22 13:17)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "Using/CodePageUsing.h"

namespace System
{
    // ��ȡ����ҳ�������Ϣ��

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsCodePageValid(CodePage codePage) noexcept;
    [[nodiscard]] CodePage SYSTEM_DEFAULT_DECLARE GetANSICodePage() noexcept;
    [[nodiscard]] CodePage SYSTEM_DEFAULT_DECLARE GetOEMCodePage() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCodePageInfo(CodePage codePage, CodePageInfoPtr codePageInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCodePageInfo(CodePage codePage, CodePageInfoExPtr codePageInfo) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_H
