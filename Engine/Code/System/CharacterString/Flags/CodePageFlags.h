//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:15)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H

#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    enum class CodePage
    {
        ACP = CP_ACP,
        OEMCP = CP_OEMCP,
        MACCP = CP_MACCP,
        ThreadACP = CP_THREAD_ACP,
        Symbol = CP_SYMBOL,
        UTF7 = CP_UTF7,
        UTF8 = CP_UTF8,
    };

#else  // !SYSTEM_PLATFORM_WIN32

    enum class CodePage
    {
        ACP = 0,
        OEMCP = 1,
        MACCP = 2,
        ThreadACP = 3,
        Symbol = 42,
        UTF7 = 65000,
        UTF8 = 65001,
    };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_FLAGS_H
