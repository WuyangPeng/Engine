///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/08 11:54)

#ifndef SYSTEM_HELPER_CYGWIN_H
#define SYSTEM_HELPER_CYGWIN_H

#if defined(__CYGWIN__)

    //  cygwin 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Cygwin"
    #define SYSTEM_PLATFORM_CYGWIN static_cast<void>(0)

    #include <sys/types.h>
    #include <unistd.h>

#endif  // defined(__CYGWIN__)

#endif  // SYSTEM_HELPER_CYGWIN_H
