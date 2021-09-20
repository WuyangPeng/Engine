///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef THE_ART_OF_CPP_LIB_H
#define THE_ART_OF_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_THE_ART_OF_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "TheArtOfCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheArtOfCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_THE_ART_OF_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "TheArtOfCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "TheArtOfCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_THE_ART_OF_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // THE_ART_OF_CPP_LIB_H
