///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.0 (2021/01/23 16:05)

#ifndef PROFESSIONAL_CPP_LIB_H
#define PROFESSIONAL_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PROFESSIONAL_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PROFESSIONAL_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ProfessionalCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ProfessionalCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PROFESSIONAL_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PROFESSIONAL_CPP_LIB_H
