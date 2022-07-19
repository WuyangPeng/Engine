///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/15 13:49)

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
