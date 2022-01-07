///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:21)

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_LIB_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ComputerSystemsAProgrammersPerspectiveD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputerSystemsAProgrammersPerspective.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ComputerSystemsAProgrammersPerspectiveStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputerSystemsAProgrammersPerspectiveStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_LIB_H
