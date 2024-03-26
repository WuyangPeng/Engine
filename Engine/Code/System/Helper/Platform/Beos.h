/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:53)

#ifndef SYSTEM_HELPER_BEOS_H
#define SYSTEM_HELPER_BEOS_H

#if defined(__BEOS__)

    ///  BeOS 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "BeOS"
    #define SYSTEM_PLATFORM_BEOS static_cast<void>(0)

#endif  // __BEOS__

#endif  // SYSTEM_HELPER_BEOS_H
