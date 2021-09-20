///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.1 (2021/03/06 17:43)

#ifndef SYSTEM_HELPER_MPW_H
#define SYSTEM_HELPER_MPW_H

#if defined(__MRC__) || defined(__SC__)

    // MPW C++ 编译器设置：

    #if MPW_CPLUS < 0x890
        #error "编译器未配置"
    #endif  // MPW_CPLUS < 0x890

    #if (0x890 < MPW_CPLUS)
        #error "未知编译器"
    #endif  // 0x890 < MPW_CPLUS

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_MPW
        #define TCRE_USE_MPW 1
    #endif  // TCRE_USE_MPW

    #if defined(__SC__)
        #define TCRE_COMPILER_VERSION __SC__
        #define TCRE_SYSTEM_COMPILER "MPW SCpp 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #elif defined(__MRC__)
        #define TCRE_COMPILER_VERSION __MRC__
        #define TCRE_SYSTEM_COMPILER "MPW MrCpp 版本 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #else  // !defined(__SC__) && !defined(__MRC__)
        #error "使用MPW编译器配置错误。"
    #endif  // defined(__SC__)

#endif  // defined(__MRC__) || defined(__SC__)

#endif  // SYSTEM_HELPER_MPW_H
