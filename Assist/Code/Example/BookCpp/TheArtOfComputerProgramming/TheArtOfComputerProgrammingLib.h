///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/30 11:02)

#ifndef THE_ART_OF_COMPUTER_PROGRAMMING_LIB_H
#define THE_ART_OF_COMPUTER_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheArtOfComputerProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheArtOfComputerProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheArtOfComputerProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheArtOfComputerProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_ART_OF_COMPUTER_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_ART_OF_COMPUTER_PROGRAMMING_LIB_H
