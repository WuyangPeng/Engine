///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:26)

#ifndef CPP_THE_COMPLETE_REFERENCE_LIB_H
#define CPP_THE_COMPLETE_REFERENCE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_THE_COMPLETE_REFERENCE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppTheCompleteReferenceD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTheCompleteReference.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_THE_COMPLETE_REFERENCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppTheCompleteReferenceStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppTheCompleteReferenceStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_THE_COMPLETE_REFERENCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_THE_COMPLETE_REFERENCE_LIB_H
