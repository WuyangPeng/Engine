/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 18:04)

#ifndef SYSTEM_HELPER_MODENA_H
#define SYSTEM_HELPER_MODENA_H

#if defined(MSIPL_COMPILE_H)

    //  Modena C++ ��׼�⣨�Դ� KAI C++)

    #ifndef TCRE_CPPLIB_VERSION

        #define TCRE_CPPLIB_VERSION 1

    #endif  // TCRE_CPPLIB_VERSION

    #ifndef TCRE_STDLIB

        #define TCRE_SYSTEM_STDLIB "Modena C++ ��׼��"

    #endif  // !TCRE_STDLIB

    #define TCRE_USE_MODENA static_cast<void>(0)

#endif  // MSIPL_COMPILE_H

#endif  // SYSTEM_HELPER_MODENA_H
