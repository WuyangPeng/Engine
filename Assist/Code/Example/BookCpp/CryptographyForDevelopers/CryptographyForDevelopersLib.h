///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef CRYPTOGRAPHY_FOR_DEVELOPERS_LIB_H
#define CRYPTOGRAPHY_FOR_DEVELOPERS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CryptographyForDevelopersD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CryptographyForDevelopers.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CryptographyForDevelopersStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CryptographyForDevelopersStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CRYPTOGRAPHY_FOR_DEVELOPERS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CRYPTOGRAPHY_FOR_DEVELOPERS_LIB_H
