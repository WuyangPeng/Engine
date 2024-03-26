/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/04 19:55)

#ifndef SYSTEM_HELPER_VMS_H
#define SYSTEM_HELPER_VMS_H

#if defined(__VMS)

    #define TCRE_SYSTEM_PLATFORM "OpenVMS"
    #define SYSTEM_PLATFORM_VMS static_cast<void>(0)

#endif  // defined(__VMS)

#endif  // SYSTEM_HELPER_VMS_H
