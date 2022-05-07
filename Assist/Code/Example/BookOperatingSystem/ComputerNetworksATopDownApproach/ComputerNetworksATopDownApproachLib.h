///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#ifndef COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_LIB_H
#define COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ComputerNetworksATopDownApproachD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputerNetworksATopDownApproach.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ComputerNetworksATopDownApproachStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ComputerNetworksATopDownApproachStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_STATIC

#endif  // TCRE_USE_MSVC

#endif  // COMPUTER_NETWORKS_A_TOP_DOWN_APPROACH_LIB_H