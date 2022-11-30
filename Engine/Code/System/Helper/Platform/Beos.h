///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/18 23:34)

#ifndef SYSTEM_HELPER_BEOS_H
#define SYSTEM_HELPER_BEOS_H

#if defined(__BEOS__)

    //  BeOS 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "BeOS"
    #define SYSTEM_PLATFORM_BEOS static_cast<void>(0)

#endif  // __BEOS__

#endif  // SYSTEM_HELPER_BEOS_H
