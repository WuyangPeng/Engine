///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.5 (2022/12/11 20:27)

#ifndef SYSTEM_FILE_MANAGER_C_FILE_USING_H
#define SYSTEM_FILE_MANAGER_C_FILE_USING_H

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
    constexpr auto gCFileError = EOF;

#if defined(TCRE_USE_GCC)

    using CFileString = std::string;
    #define SYSTEM_FILE_TEXT(quote) quote

#else  // !TCRE_USE_GCC

    using CFileString = String;
    #define SYSTEM_FILE_TEXT(quote) SYSTEM_TEXT(quote)

#endif  // TCRE_USE_GCC

#if defined(SYSTEM_PLATFORM_LINUX)

    #define STAT_STRUCT stat
    #define STAT_FUNCTION stat

#else  // !SYSTEM_PLATFORM_LINUX

    #define STAT_STRUCT _stat
    #define STAT_FUNCTION _tstat

#endif  // SYSTEM_PLATFORM_LINUX
}

#endif  // SYSTEM_FILE_MANAGER_C_FILE_USING_H