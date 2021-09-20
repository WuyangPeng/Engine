///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef DESIGNING_AND_CODING_REUSABLE_CPP_LIB_H
#define DESIGNING_AND_CODING_REUSABLE_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DESIGNING_AND_CODING_REUSABLE_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "DesigningAndCodingReusableCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DesigningAndCodingReusableCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_DESIGNING_AND_CODING_REUSABLE_CPP_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "DesigningAndCodingReusableCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "DesigningAndCodingReusableCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_DESIGNING_AND_CODING_REUSABLE_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DESIGNING_AND_CODING_REUSABLE_CPP_LIB_H
