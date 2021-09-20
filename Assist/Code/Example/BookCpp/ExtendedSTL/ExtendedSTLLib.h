///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/02/28 19:36)

#ifndef EXTENDED_STL_LIB_H
#define EXTENDED_STL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_EXTENDED_STL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ExtendedSTLD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ExtendedSTL.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_EXTENDED_STL_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ExtendedSTLStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ExtendedSTLStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_EXTENDED_STL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // EXTENDED_STL_LIB_H
