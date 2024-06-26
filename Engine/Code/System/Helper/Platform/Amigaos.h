/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:53)

#ifndef SYSTEM_HELPER_AMIGAOS_H
#define SYSTEM_HELPER_AMIGAOS_H

#if defined(__amigaos__)

    #define TCRE_SYSTEM_PLATFORM "AmigaOS"
    #define SYSTEM_PLATFORM_AMIGAOS static_cast<void>(0)

#endif  // __amigaos__

#endif  // SYSTEM_HELPER_AMIGAOS_H
