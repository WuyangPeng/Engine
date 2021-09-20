///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.0 (2020/12/26 21:31)

#ifndef CPP_FOR_THE_IMPATIENT_LIB_H
#define CPP_FOR_THE_IMPATIENT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppForTheImpatientD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppForTheImpatient.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CppForTheImpatientStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppForTheImpatientStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_FOR_THE_IMPATIENT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_FOR_THE_IMPATIENT_LIB_H
