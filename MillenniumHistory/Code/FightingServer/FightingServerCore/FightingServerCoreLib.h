/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#ifndef FIGHTING_SERVER_CORE_LIB_H
#define FIGHTING_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

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