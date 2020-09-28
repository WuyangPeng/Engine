//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/21 11:13)

#ifndef SYSTEM_HELPER_AIX_H
#define SYSTEM_HELPER_AIX_H

#if defined(__IBMCPP__) || defined(_AIX)

    //  IBM/Aix 具体配置选项：

    #define TCRE_SYSTEM_PLATFORM "IBM Aix"
    #define SYSTEM_PLATFORM_AIX

#endif  // defined(__IBMCPP__) || defined(_AIX)

#endif  // SYSTEM_HELPER_AIX_H
