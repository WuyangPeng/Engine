//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:17)

#ifndef SYSTEM_HELPER_SOLARIS_H
#define SYSTEM_HELPER_SOLARIS_H

#if defined(sun) || defined(__sun)

    //  sun 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Sun Solaris"
    #define SYSTEM_PLATFORM_SOLARIS

#endif  // defined(sun) || defined(__sun)

#endif  // SYSTEM_HELPER_SOLARIS_H
