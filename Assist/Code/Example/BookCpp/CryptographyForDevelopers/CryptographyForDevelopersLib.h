///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/30 11:02)

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
