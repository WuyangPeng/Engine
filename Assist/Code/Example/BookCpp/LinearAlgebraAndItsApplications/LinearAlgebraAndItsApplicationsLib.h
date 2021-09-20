///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/09 14:56)

#ifndef LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_LIB_H
#define LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "LinearAlgebraAndItsApplicationsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LinearAlgebraAndItsApplications.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "LinearAlgebraAndItsApplicationsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "LinearAlgebraAndItsApplicationsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LINEAR_ALGEBRA_AND_ITS_APPLICATIONS_LIB_H
