///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/08 21:47)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using DynamicLinkModule = HMODULE;
    using DynamicLinkProcess = FARPROC;
    using DynamicLinkCharType = TCHAR;
    using DynamicLinkString = String;
    using DynamicLinkStringView = StringView;

    #define DYNAMIC_LINK_TEXT(quote) SYSTEM_TEXT(quote)

#else  // !SYSTEM_PLATFORM_WIN32

    using DynamicLinkModule = void*;
    using DynamicLinkProcess = int (*)();
    using DynamicLinkCharType = char;
    using DynamicLinkString = std::string;
    using DynamicLinkStringView = std::string_view;

    #define DYNAMIC_LINK_TEXT(quote) quote

#endif  // SYSTEM_PLATFORM_WIN32

    constexpr auto nullDynamicLinkChar = DYNAMIC_LINK_TEXT('\0');
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
