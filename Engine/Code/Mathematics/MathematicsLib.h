///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 11:10)

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