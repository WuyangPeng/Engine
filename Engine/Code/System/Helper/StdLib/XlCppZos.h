/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/04 21:43)

#ifndef SYSTEM_HELPER_XL_CPP_ZOS_H
#define SYSTEM_HELPER_XL_CPP_ZOS_H

#if defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

    ///  IBM z/OS XL C/C++

    /// ��ǰ֧�ֵ���ɵĿ�汾��2.1��V2R1��
    #if __TARGET_LIB__ < 0x42010000

        #error "��֧�ֻ�δ���ÿ�汾��������������"

    #endif  // __TARGET_LIB__ < 0x42010000

    #if 0x42010000 < __TARGET_LIB__

        #error "δ֪�Ŀ�汾"

    #endif  // 0x42010000 < __TARGET_LIB__

    #ifndef TCRE_CPP_LIB_VERSION

        #define TCRE_CPP_LIB_VERSION __TARGET_LIB__

    #endif  // TCRE_CPP_LIB_VERSION

    #ifndef TCRE_SYSTEM_STD_LIB

        #define TCRE_SYSTEM_STD_LIB "IBM z/OS XL C/C++ ��׼��汾 " SYSTEM_STRINGIZE(TCRE_CPP_LIB_VERSION)

    #endif  // !TCRE_SYSTEM_STD_LIB

    #define TCRE_USE_XL_CPP_ZOS static_cast<void>(0)

#endif  // defined(__IBMCPP__) && defined(__COMPILER_VER__) && defined(__MVS__)

#endif  // SYSTEM_HELPER_XL_CPP_ZOS_H
