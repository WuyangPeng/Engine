///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:45)

#ifndef ITEM_MANAGER_LIB_H
#define ITEM_MANAGER_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ITEM_MANAGER_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ItemManagerD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ItemManager.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_ITEM_MANAGER_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ItemManagerStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ItemManagerStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_ITEM_MANAGER_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ITEM_MANAGER_LIB_H
