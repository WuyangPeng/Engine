/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:22)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class CodePage
    {
        ACodePage = CP_ACP,
        OemCodePage = CP_OEMCP,
        MacCodePage = CP_MACCP,
        ThreadACodePage = CP_THREAD_ACP,
        Symbol = CP_SYMBOL,

        Gb2312 = 936,
        Utf7 = CP_UTF7,
        Utf8 = CP_UTF8,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class CodePage
    {
        ACodePage = 0,
        OemCodePage = 1,
        MacCodePage = 2,
        ThreadACodePage = 3,
        Symbol = 42,

        Gb2312 = 936,
        Utf7 = 65000,
        Utf8 = 65001,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H
