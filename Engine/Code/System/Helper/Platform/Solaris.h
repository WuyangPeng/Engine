///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:20)

#ifndef SYSTEM_HELPER_SOLARIS_H
#define SYSTEM_HELPER_SOLARIS_H

#if defined(sun) || defined(__sun)

    //  sun 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Sun Solaris"
    #define SYSTEM_PLATFORM_SOLARIS static_cast<void>(0)

#endif  // defined(sun) || defined(__sun)

#endif  // SYSTEM_HELPER_SOLARIS_H
