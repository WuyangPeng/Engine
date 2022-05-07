///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#ifndef PROFESSIONAL_MULTICORE_PROGRAMMING_LIB_H
#define PROFESSIONAL_MULTICORE_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalMulticoreProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROFESSIONAL_MULTICORE_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROFESSIONAL_MULTICORE_PROGRAMMING_LIB_H