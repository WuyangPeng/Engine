//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/21 11:03)

#ifndef SYSTEM_HELPER_COMEAU_H
#define SYSTEM_HELPER_COMEAU_H

#ifdef __COMO__

    // Comeau C++ ���������ã�

    // �汾��飺���ǲ�֪���汾4245֮ǰ��Comeau��
    #if __COMO_VERSION__ < 4245
        #error "������δ����"
    #endif  // __COMO_VERSION__ < 4245

    // �����֪�İ汾��4245��
    #if (4245 < __COMO_VERSION__)
        #error "δ֪�ı������汾"
    #endif  // 4245 < __COMO_VERSION__

    #ifndef SYSTEM_CPP_STANDARD
        #define SYSTEM_CPP_STANDARD 3
    #endif  // SYSTEM_CPP_STANDARD

    #ifndef TCRE_USE_COMEAU
        #define TCRE_USE_COMEAU 1
    #endif  // TCRE_USE_COMEAU

    #ifndef TCRE_COMPILER_VERSION
        #define TCRE_COMPILER_VERSION __COMO_VERSION__
    #endif  // TCRE_COMPILER_VERSION

    #ifndef TCRE_SYSTEM_COMPILER
        #define TCRE_SYSTEM_COMPILER "Comeau C++ �汾 " SYSTEM_STRINGIZE(TCRE_COMPILER_VERSION)
    #endif  // TCRE_SYSTEM_COMPILER

#endif  // __COMO__

#endif  // SYSTEM_HELPER_COMEAU_H
