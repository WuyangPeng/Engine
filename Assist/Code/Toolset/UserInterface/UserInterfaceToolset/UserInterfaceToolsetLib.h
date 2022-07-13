///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 18:31)

#ifndef USER_INTERFACE_TOOLSET_LIB_H
#define USER_INTERFACE_TOOLSET_LIB_H

#include "UserInterface/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_USER_INTERFACE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UserInterfaceToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UserInterfaceToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_USER_INTERFACE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "UserInterfaceToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UserInterfaceToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_USER_INTERFACE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // USER_INTERFACE_TOOLSET_LIB_H
