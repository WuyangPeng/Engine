///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef ADVANCED_QT_PROGRAMMING_LIB_H
#define ADVANCED_QT_PROGRAMMING_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedQtProgrammingD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedQtProgramming.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedQtProgrammingStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedQtProgrammingStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ADVANCED_QT_PROGRAMMING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ADVANCED_QT_PROGRAMMING_LIB_H
