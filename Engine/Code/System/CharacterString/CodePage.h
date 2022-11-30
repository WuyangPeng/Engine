///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/12 21:21)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"

/// 获取代码页的相关信息。
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE IsCodePageValid(CodePage codePage) noexcept;
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetANSICodePage() noexcept;
    NODISCARD CodePage SYSTEM_DEFAULT_DECLARE GetOEMCodePage() noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_H
