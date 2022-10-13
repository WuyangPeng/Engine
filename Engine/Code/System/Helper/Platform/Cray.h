///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/11 23:18)

#ifndef SYSTEM_HELPER_CLOUD_CRAY_H
#define SYSTEM_HELPER_CLOUD_CRAY_H

#if defined(_CRAYC)

    //  SGI Irix 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "Cray"
    #define SYSTEM_PLATFORM_CRAY static_cast<void>(0)

#endif  // _CRAYC

#endif  // SYSTEM_HELPER_CLOUD_CRAY_H
