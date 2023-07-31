///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:21)

#ifndef SHOP_LIB_H
#define SHOP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SHOP_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ShopD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Shop.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SHOP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ShopStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ShopStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SHOP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SHOP_LIB_H
