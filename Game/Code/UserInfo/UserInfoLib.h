///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/14 14:08)

#ifndef USER_INFO_LIB_H
#define USER_INFO_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_USER_INFO_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UserInfoD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UserInfo.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_USER_INFO_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "UserInfoStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UserInfoStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_USER_INFO_STATIC

#endif  // TCRE_USE_MSVC

#endif  // USER_INFO_LIB_H
