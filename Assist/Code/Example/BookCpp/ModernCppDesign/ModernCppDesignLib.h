///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef MODERN_CPP_DESIGN_LIB_H
#define MODERN_CPP_DESIGN_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MODERN_CPP_DESIGN_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ModernCppDesignD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ModernCppDesign.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MODERN_CPP_DESIGN_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "ModernCppDesignStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ModernCppDesignStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MODERN_CPP_DESIGN_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MODERN_CPP_DESIGN_LIB_H
