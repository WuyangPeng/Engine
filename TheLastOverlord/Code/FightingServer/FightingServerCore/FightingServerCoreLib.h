///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���İ����汾��0.8.0.12 (2022/07/25 15:42)

#ifndef FIGHTING_SERVER_CORE_LIB_H
#define FIGHTING_SERVER_CORE_LIB_H

#include "Macro/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FIGHTING_SERVER_CORE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "FightingServerCoreD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "FightingServerCore.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_FIGHTING_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "FightingServerCoreStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "FightingServerCoreStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_FIGHTING_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FIGHTING_SERVER_CORE_LIB_H
