//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:00)

#ifndef SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
#define SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Window/Using/WindowUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    using DynamicLinkModule = HMODULE;
    using DynamicLinkProcess = FARPROC;
    using DynamicLinkCharType = TCHAR;
    using DynamicLinkString = String;

    #define DYNAMIC_LINK_TEXT(quote) SYSTEM_TEXT(quote)

#else  // !SYSTEM_PLATFORM_WIN32

    using DynamicLinkModule = void*;
    using DynamicLinkProcess = int (*)();
    using DynamicLinkCharType = char;
    using DynamicLinkString = std::string;

    #define DYNAMIC_LINK_TEXT(quote) quote

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_DYNAMIC_LINK_LOAD_LIBRARY_USING_H
