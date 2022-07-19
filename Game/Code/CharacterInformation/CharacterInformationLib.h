///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/14 17:21)

#ifndef CHARACTER_INFORMATION_LIB_H
#define CHARACTER_INFORMATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CHARACTER_INFORMATION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CharacterInformationD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CharacterInformation.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CHARACTER_INFORMATION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CharacterInformationStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CharacterInformationStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CHARACTER_INFORMATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CHARACTER_INFORMATION_LIB_H
