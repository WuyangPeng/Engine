///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/01/28 13:39)

#ifndef MATHEMATICS_LIB_H
#define MATHEMATICS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MATHEMATICS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MathematicsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Mathematics.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MATHEMATICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MathematicsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MathematicsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MATHEMATICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MATHEMATICS_LIB_H