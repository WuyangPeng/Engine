///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/22 22:48)

#ifndef BACKGROUND_CLIENT_CORE_LIB_H
#define BACKGROUND_CLIENT_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BACKGROUND_CLIENT_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BackgroundClientCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BackgroundClientCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BACKGROUND_CLIENT_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BackgroundClientCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BackgroundClientCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BACKGROUND_CLIENT_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BACKGROUND_CLIENT_CORE_LIB_H
