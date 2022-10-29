///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/12 23:43)

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
