/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 18:08)

#ifndef SYSTEM_HELPER_HPUX_H
#define SYSTEM_HELPER_HPUX_H

#if defined(__hpux)

    //  hpux 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "HP-UX"
    #define SYSTEM_PLATFORM_HPUX static_cast<void>(0)

#endif  // __hpux

#endif  // SYSTEM_HELPER_HPUX_H
