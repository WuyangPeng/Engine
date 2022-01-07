///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:38)

#ifndef SYSTEM_HELPER_AIX_H
#define SYSTEM_HELPER_AIX_H

#if defined(__IBMCPP__) || defined(_AIX)

    //  IBM/Aix 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "IBM Aix"
    #define SYSTEM_PLATFORM_AIX static_cast<void>(0)

#endif  // defined(__IBMCPP__) || defined(_AIX)

#endif  // SYSTEM_HELPER_AIX_H
