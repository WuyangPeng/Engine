//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 13:16)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    static const wchar_t* g_LocaleUserDefault{ LOCALE_NAME_USER_DEFAULT };
    static const wchar_t* g_LocaleNameInvariant{ LOCALE_NAME_INVARIANT };
    static const wchar_t* g_LocaleSystemDefault{ LOCALE_NAME_SYSTEM_DEFAULT };

#else  // !SYSTEM_PLATFORM_WIN32

    static const wchar_t* g_LocaleUserDefault{ nullptr };
    static const wchar_t* g_LocaleNameInvariant{ L"" };
    static const wchar_t* g_LocaleSystemDefault{ L"!x-sys-default-locale" };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H
