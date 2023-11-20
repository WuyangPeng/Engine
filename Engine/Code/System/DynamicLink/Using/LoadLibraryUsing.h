///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:30)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using DynamicLinkModule = HMODULE;
    using ConstDynamicLinkModule = const std::remove_pointer_t<HMODULE>*;
    using DynamicLinkProcess = FARPROC;
    using DynamicLinkCharType = TChar;
    using DynamicLinkString = String;
    using DynamicLinkStringView = StringView;

    #define DYNAMIC_LINK_TEXT(quote) SYSTEM_TEXT(quote)

#else  // !SYSTEM_PLATFORM_WIN32

    using DynamicLinkModule = void*;
    using ConstDynamicLinkModule = const void*;
    using DynamicLinkProcess = void*;
    using DynamicLinkCharType = char;
    using DynamicLinkString = std::string;
    using DynamicLinkStringView = std::string_view;

    #define DYNAMIC_LINK_TEXT(quote) quote

#endif  // SYSTEM_PLATFORM_WIN32

    constexpr auto nullDynamicLinkChar = DYNAMIC_LINK_TEXT('\0');
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
