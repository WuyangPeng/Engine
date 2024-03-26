/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:55)

#ifndef SYSTEM_HELPER_ZOS_H
#define SYSTEM_HELPER_ZOS_H

#if defined(__TOS_MVS__)

    ///  IBM z/OS 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "IBM z/OS"
    #define SYSTEM_PLATFORM_ZOS static_cast<void>(0)

    /// 对 __UU, __C99, __TR1, ...
    #include <features.h>

#endif  // defined(__TOS_MVS__)

#endif  // SYSTEM_HELPER_ZOS_H
