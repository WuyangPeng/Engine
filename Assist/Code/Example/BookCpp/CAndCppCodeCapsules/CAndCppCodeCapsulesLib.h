///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.6.0.1 (2021/01/01 14:26)

#ifndef C_AND_CPP_CODE_CAPSULES_LIB_H
#define C_AND_CPP_CODE_CAPSULES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CAndCppCodeCapsulesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CAndCppCodeCapsules.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CAndCppCodeCapsulesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CAndCppCodeCapsulesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_C_AND_CPP_CODE_CAPSULES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // C_AND_CPP_CODE_CAPSULES_LIB_H
