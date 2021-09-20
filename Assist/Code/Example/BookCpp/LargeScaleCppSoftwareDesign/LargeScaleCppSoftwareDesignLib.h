///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.1 (2021/03/11 17:51)

#ifndef LARGE_SCALE_CPP_SOFTWARE_DESIGN_LIB_H
#define LARGE_SCALE_CPP_SOFTWARE_DESIGN_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LARGE_SCALE_CPP_SOFTWARE_DESIGN_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "LargeScaleCppSoftwareDesignD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LargeScaleCppSoftwareDesign.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_LARGE_SCALE_CPP_SOFTWARE_DESIGN_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "LargeScaleCppSoftwareDesignStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LargeScaleCppSoftwareDesignStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_LARGE_SCALE_CPP_SOFTWARE_DESIGN_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LARGE_SCALE_CPP_SOFTWARE_DESIGN_LIB_H
