///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.9.0.12 (2023/06/16 16:59)

#ifndef CHAT_LIB_H
#define CHAT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CHAT_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ChatD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Chat.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CHAT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ChatStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ChatStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CHAT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CHAT_LIB_H
