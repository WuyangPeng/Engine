///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎游戏版本：0.8.0.11 (2022/07/18 18:17)

#ifndef MAIL_LIB_H
#define MAIL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MAIL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MailD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Mail.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MAIL_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MailStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MailStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MAIL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MAIL_LIB_H
