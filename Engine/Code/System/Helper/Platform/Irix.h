///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 11:22)

#ifndef SYSTEM_HELPER_IRIX_H
#define SYSTEM_HELPER_IRIX_H

#if defined(__sgi)

    //  SGI Irix 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "SGI Irix"
    #define SYSTEM_PLATFORM_IRIX static_cast<void>(0)

#endif  // __sgi

#endif  // SYSTEM_HELPER_IRIX_H
