/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#ifndef MAIL_SERVER_MIDDLE_LAYER_LIB_H
#define MAIL_SERVER_MIDDLE_LAYER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "MailServerMiddleLayerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "MailServerMiddleLayer.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "MailServerMiddleLayerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "MailServerMiddleLayerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_MAIL_SERVER_MIDDLE_LAYER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MAIL_SERVER_MIDDLE_LAYER_LIB_H