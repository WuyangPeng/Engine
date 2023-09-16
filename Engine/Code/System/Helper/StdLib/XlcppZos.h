///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/29 10:08)

#ifndef SYSTEM_HELPER_XLCPP_ZOS_H
#define SYSTEM_HELPER_XLCPP_ZOS_H

#if defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

    //  IBM z/OS XL C/C++

    // ��ǰ֧�ֵ���ɵĿ�汾��2.1��V2R1��
    #if __TARGET_LIB__ < 0x42010000

        #error "��֧�ֻ�δ���ÿ�汾��������������"

    #endif  // __TARGET_LIB__ < 0x42010000

    #if 0x42010000 < __TARGET_LIB__

        #error "δ֪�Ŀ�汾"

    #endif  // 0x42010000 < __TARGET_LIB__

    #ifndef TCRE_CPPLIB_VERSION

        #define TCRE_CPPLIB_VERSION __TARGET_LIB__

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "IBM z/OS XL C/C++ ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPPLIB_VERSION)

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_XLCPP_ZOS static_cast<void>(0)

#endif  // defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

#endif  // SYSTEM_HELPER_XLCPP_ZOS_H
