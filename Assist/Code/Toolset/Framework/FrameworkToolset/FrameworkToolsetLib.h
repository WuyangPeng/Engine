///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:21)

#ifndef FRAMEWORK_TOOLSET_LIB_H
#define FRAMEWORK_TOOLSET_LIB_H

#include "Framework/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_FRAMEWORK_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "FrameworkToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FrameworkToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_FRAMEWORK_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "FrameworkToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "FrameworkToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_FRAMEWORK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // FRAMEWORK_TOOLSET_LIB_H
