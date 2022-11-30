///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/12 21:16)

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
