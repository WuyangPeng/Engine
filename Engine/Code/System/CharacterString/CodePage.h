//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:17)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "Using/CodePageUsing.h"

namespace System
{
    // 获取代码页的相关信息。

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE IsCodePageValid(CodePage codePage) noexcept;
    [[nodiscard]] CodePage SYSTEM_DEFAULT_DECLARE GetANSICodePage() noexcept;
    [[nodiscard]] CodePage SYSTEM_DEFAULT_DECLARE GetOEMCodePage() noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCodePageInfo(CodePage codePage, CodePageInfoPtr codePageInfo) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE GetCodePageInfo(CodePage codePage, CodePageInfoExPtr codePageInfo) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_H
