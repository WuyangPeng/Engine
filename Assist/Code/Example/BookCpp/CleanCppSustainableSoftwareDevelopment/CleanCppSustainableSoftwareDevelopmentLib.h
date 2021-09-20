///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_LIB_H
#define CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CleanCppSustainableSoftwareDevelopmentD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CleanCppSustainableSoftwareDevelopment.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "CleanCppSustainableSoftwareDevelopmentStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CleanCppSustainableSoftwareDevelopmentStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CLEAN_CPP_SUSTAINABLE_SOFTWARE_DEVELOPMENT_LIB_H
