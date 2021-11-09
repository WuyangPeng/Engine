///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef SAFE_CPP_LIB_H
#define SAFE_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SAFE_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "SafeCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SafeCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SAFE_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "SafeCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "SafeCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SAFE_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SAFE_CPP_LIB_H
