///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:36)

#ifndef SYSTEM_HELPER_QNXNTO_H
#define SYSTEM_HELPER_QNXNTO_H

#if defined(__QNXNTO__)

    //  QNX 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "QNX"
    #define SYSTEM_PLATFORM_QNXNTO static_cast<void>(0)

#endif  // __QNXNTO__

#endif  // SYSTEM_HELPER_QNXNTO_H
