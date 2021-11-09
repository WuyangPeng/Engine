///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#ifndef ADVANCED_CORBA_PROGRAMMING_WITH_CPP_LIB_H
#define ADVANCED_CORBA_PROGRAMMING_WITH_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedCorbaProgrammingWithCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedCorbaProgrammingWithCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "AdvancedCorbaProgrammingWithCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "AdvancedCorbaProgrammingWithCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_ADVANCED_CORBA_PROGRAMMING_WITH_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // ADVANCED_CORBA_PROGRAMMING_WITH_CPP_LIB_H
