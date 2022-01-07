///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:46)

#ifndef SYSTEM_FILE_MANAGE_C_FILE_USING_H
#define SYSTEM_FILE_MANAGE_C_FILE_USING_H

#include "System/Helper/Platform.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace System
{
#ifdef SYSTEM_PLATFORM_LINUX

    using OffType = off_t;

#else  // !SYSTEM_PLATFORM_LINUX

    using OffType = _off_t;

#endif  // SYSTEM_PLATFORM_LINUX

    using PosType = fpos_t;
    constexpr auto g_CFileError = EOF;

#if defined(TCRE_USE_GCC)

    using CFileString = std::string;
    #define SYSTEM_FILE_TEXT(quote) quote

#else  // !TCRE_USE_GCC

    using CFileString = String;
    #define SYSTEM_FILE_TEXT(quote) SYSTEM_TEXT(quote)

#endif  // TCRE_USE_GCC
}

#endif  // SYSTEM_FILE_MANAGE_C_FILE_USING_H