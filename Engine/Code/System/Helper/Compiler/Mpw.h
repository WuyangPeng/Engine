///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/06 17:43)

#ifndef SYSTEM_HELPER_MPW_H
#define SYSTEM_HELPER_MPW_H

#if defined(__MRC__) || defined(__SC__)

    // MPW C++ ���������ã�

    #if MPW_CPLUS < 0x890
        #error "������δ����"
    #endif  // MPW_CPLUS < 0x890

    #if (0x890 < MPW_CPLUS)
        #error "δ֪������"
    #endif  // 0x890 < MPW_CPLUS

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_MPW
        #define TCRE_USE_MPW 1
    #endif  // TCRE_USE_MPW

    #if defined(__SC__)
        #define TCRE_COMPILER_VERSION __SC__
        #define TCRE_SYSTEM_COMPILER "MPW SCpp �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #elif defined(__MRC__)
        #define TCRE_COMPILER_VERSION __MRC__
        #define TCRE_SYSTEM_COMPILER "MPW MrCpp �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #else  // !defined(__SC__) && !defined(__MRC__)
        #error "ʹ��MPW���������ô���"
    #endif  // defined(__SC__)

#endif  // defined(__MRC__) || defined(__SC__)

#endif  // SYSTEM_HELPER_MPW_H
