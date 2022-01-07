///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:38)

#ifndef SYSTEM_HELPER_AMIGAOS_H
#define SYSTEM_HELPER_AMIGAOS_H

#if defined(__amigaos__)

    #define TCRE_SYSTEM_PLATFORM "AmigaOS"
    #define SYSTEM_PLATFORM_AMIGAOS static_cast<void>(0)

#endif  // __amigaos__

#endif  // SYSTEM_HELPER_AMIGAOS_H
