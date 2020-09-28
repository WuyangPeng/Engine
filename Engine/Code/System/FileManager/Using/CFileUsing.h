//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/24 12:56)

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