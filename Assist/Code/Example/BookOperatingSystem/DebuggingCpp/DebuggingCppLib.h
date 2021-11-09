///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.4 (2021/10/07 23:22)

#ifndef DEBUGGING_CPP_LIB_H
#define DEBUGGING_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DEBUGGING_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DebuggingCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DebuggingCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DEBUGGING_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "DebuggingCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DebuggingCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DEBUGGING_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DEBUGGING_CPP_LIB_H
