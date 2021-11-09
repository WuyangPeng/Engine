///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.5 (2021/10/28 22:19)

#ifndef OBJECT_ORIENTED_MULTITHREADING_USING_CPP_LIB_H
#define OBJECT_ORIENTED_MULTITHREADING_USING_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ObjectOrientedMultithreadingUsingCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ObjectOrientedMultithreadingUsingCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ObjectOrientedMultithreadingUsingCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ObjectOrientedMultithreadingUsingCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_OBJECT_ORIENTED_MULTITHREADING_USING_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // OBJECT_ORIENTED_MULTITHREADING_USING_CPP_LIB_H
