///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.2 (2021/03/28 12:57)

#ifndef APPLIED_CRYPTOGRAPHY_LIB_H
#define APPLIED_CRYPTOGRAPHY_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AppliedCryptographyD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AppliedCryptography.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AppliedCryptographyStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AppliedCryptographyStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_APPLIED_CRYPTOGRAPHY_STATIC

#endif  // TCRE_USE_MSVC

#endif  // APPLIED_CRYPTOGRAPHY_LIB_H
