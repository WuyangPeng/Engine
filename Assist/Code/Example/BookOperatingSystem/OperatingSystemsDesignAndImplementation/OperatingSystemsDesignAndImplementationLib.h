///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.7 (2021/12/06 21:21)

#ifndef OPERATING_SYSTEMS_DESIGN_AND_IMPLEMENTATION_LIB_H
#define OPERATING_SYSTEMS_DESIGN_AND_IMPLEMENTATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_OPERATING_SYSTEMS_DESIGN_AND_IMPLEMENTATION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "OperatingSystemsDesignAndImplementationD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "OperatingSystemsDesignAndImplementation.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_OPERATING_SYSTEMS_DESIGN_AND_IMPLEMENTATION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "OperatingSystemsDesignAndImplementationStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "OperatingSystemsDesignAndImplementationStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_OPERATING_SYSTEMS_DESIGN_AND_IMPLEMENTATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // OPERATING_SYSTEMS_DESIGN_AND_IMPLEMENTATION_LIB_H
