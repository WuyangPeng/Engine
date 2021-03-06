//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:16)

#ifndef SYSTEM_CHARACTER_STRING_CODE_PAGE_USING_H
#define SYSTEM_CHARACTER_STRING_CODE_PAGE_USING_H

#include "System/Helper/Platform.h"

#include "System/Window/Using/WindowUsing.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using CodePageInfo = CPINFO;
    using CodePageInfoPtr = LPCPINFO;
    using CodePageInfoEx = CPINFOEX;
    using CodePageInfoExPtr = LPCPINFOEX;

#else  // !SYSTEM_PLATFORM_WIN32

    static constexpr auto g_MaxDefaultChar = 2;
    static constexpr auto g_MaxLeadBytes = 12;

    struct CodePageInfo
    {
        uint32_t MaxCharSize;
        uint8_t DefaultChar[g_MaxDefaultChar];
        uint8_t LeadByte[g_MaxLeadBytes];
    };
    using CodePageInfoPtr = CodePageInfo*;

    struct CodePageInfoEx
    {
        uint32_t MaxCharSize;
        uint8_t DefaultChar[g_MaxDefaultChar];
        uint8_t LeadByte[g_MaxLeadBytes];
        TChar UnicodeDefaultChar;
        uint32_t CodePage;
        TChar CodePageName[g_MaxPath];
    };
    using CodePageInfoExPtr = CodePageInfoEx*;

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_CODE_PAGE_USING_H
