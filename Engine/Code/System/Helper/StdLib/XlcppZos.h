///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/29 10:08)

#ifndef SYSTEM_HELPER_XLCPP_ZOS_H
#define SYSTEM_HELPER_XLCPP_ZOS_H

#if defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

    //  IBM z/OS XL C/C++

    // 当前支持的最旧的库版本是2.1（V2R1）
    #if __TARGET_LIB__ < 0x42010000

        #error "不支持或未配置库版本——请重新配置"

    #endif  // __TARGET_LIB__ < 0x42010000

    #if 0x42010000 < __TARGET_LIB__

        #error "未知的库版本"

    #endif  // 0x42010000 < __TARGET_LIB__

    #ifndef TCRE_CPPLIB_VERSION

        #define TCRE_CPPLIB_VERSION __TARGET_LIB__

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "IBM z/OS XL C/C++ 标准库版本 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_XLCPP_ZOS static_cast<void>(0)

#endif  // defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

#endif  // SYSTEM_HELPER_XLCPP_ZOS_H
