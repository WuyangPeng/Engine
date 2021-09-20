///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/08 11:55)

#ifndef SYSTEM_HELPER_IRIX_H
#define SYSTEM_HELPER_IRIX_H

#if defined(__sgi)

    //  SGI Irix 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "SGI Irix"
    #define SYSTEM_PLATFORM_IRIX static_cast<void>(0)

#endif  // __sgi

#endif  // SYSTEM_HELPER_IRIX_H
