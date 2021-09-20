///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/16 17:45)

#ifndef CPP_CODING_STANDARDS_LIB_H
#define CPP_CODING_STANDARDS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_CODING_STANDARDS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppCodingStandardsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppCodingStandards.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_CODING_STANDARDS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppCodingStandardsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppCodingStandardsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_CODING_STANDARDS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_CODING_STANDARDS_LIB_H
