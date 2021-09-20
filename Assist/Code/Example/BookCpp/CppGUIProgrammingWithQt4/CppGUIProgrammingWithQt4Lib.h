///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef CPP_GUI_PROGRAMMING_WITH_QT4_LIB_H
#define CPP_GUI_PROGRAMMING_WITH_QT4_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_GUI_PROGRAMMING_WITH_QT4_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppGUIProgrammingWithQt4D.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppGUIProgrammingWithQt4.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_GUI_PROGRAMMING_WITH_QT4_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppGUIProgrammingWithQt4StaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppGUIProgrammingWithQt4Static.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_GUI_PROGRAMMING_WITH_QT4_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_GUI_PROGRAMMING_WITH_QT4_LIB_H
