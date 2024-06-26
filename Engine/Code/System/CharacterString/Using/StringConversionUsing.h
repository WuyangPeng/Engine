/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:06)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/Helper/Platform.h"

namespace System
{
#ifdef SYSTEM_PLATFORM_WIN32

    static const wchar_t* gLocaleUserDefault{ LOCALE_NAME_USER_DEFAULT };
    static const wchar_t* gLocaleNameInvariant{ LOCALE_NAME_INVARIANT };
    static const wchar_t* gLocaleSystemDefault{ LOCALE_NAME_SYSTEM_DEFAULT };

#else  // !SYSTEM_PLATFORM_WIN32

    static const wchar_t* gLocaleUserDefault{ nullptr };
    static const wchar_t* gLocaleNameInvariant{ L"" };
    static const wchar_t* gLocaleSystemDefault{ L"!x-sys-default-locale" };

#endif  // SYSTEM_PLATFORM_WIN32
}

#endif  // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_USING_H
