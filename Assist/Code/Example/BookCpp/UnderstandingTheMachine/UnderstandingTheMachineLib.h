///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#ifndef UNDERSTANDING_THE_MACHINE_LIB_H
#define UNDERSTANDING_THE_MACHINE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_UNDERSTANDING_THE_MACHINE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "UnderstandingTheMachineD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UnderstandingTheMachine.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_UNDERSTANDING_THE_MACHINE_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "UnderstandingTheMachineStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "UnderstandingTheMachineStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_UNDERSTANDING_THE_MACHINE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // UNDERSTANDING_THE_MACHINE_LIB_H
