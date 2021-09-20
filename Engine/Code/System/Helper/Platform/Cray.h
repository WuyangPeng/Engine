///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/08 11:53)

#ifndef SYSTEM_HELPER_CLOUD_CRAY_H
#define SYSTEM_HELPER_CLOUD_CRAY_H

#if defined(_CRAYC)

    //  SGI Irix 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Cray"
    #define SYSTEM_PLATFORM_CRAY static_cast<void>(0)

#endif  // _CRAYC

#endif  // SYSTEM_HELPER_CLOUD_CRAY_H
