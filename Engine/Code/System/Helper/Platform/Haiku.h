///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/16 22:06)

#ifndef SYSTEM_HELPER_HAIKU_H
#define SYSTEM_HELPER_HAIKU_H

#if defined(__HAIKU__)

    //  Haiku 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Haiku"
    #define SYSTEM_PLATFORM_HAIKU static_cast<void>(0)

#endif  // __HAIKU__

#endif  // SYSTEM_HELPER_HAIKU_H
