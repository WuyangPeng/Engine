///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/01 19:02)

#ifndef PROGRAMMING_WINDOWS_FIFTH_EDITION_LIB_H
#define PROGRAMMING_WINDOWS_FIFTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROGRAMMING_WINDOWS_FIFTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingWindowsFifthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingWindowsFifthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROGRAMMING_WINDOWS_FIFTH_EDITION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ProgrammingWindowsFifthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProgrammingWindowsFifthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROGRAMMING_WINDOWS_FIFTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROGRAMMING_WINDOWS_FIFTH_EDITION_LIB_H
