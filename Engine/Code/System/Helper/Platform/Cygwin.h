//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:15)

#ifndef SYSTEM_HELPER_CYGWIN_H
#define SYSTEM_HELPER_CYGWIN_H

#if defined(__CYGWIN__)

    //  cygwin 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Cygwin"
    #define SYSTEM_PLATFORM_CYGWIN

    #include <unistd.h>
    #include <sys/types.h>

#endif  // defined(__CYGWIN__)

#endif  // SYSTEM_HELPER_CYGWIN_H
