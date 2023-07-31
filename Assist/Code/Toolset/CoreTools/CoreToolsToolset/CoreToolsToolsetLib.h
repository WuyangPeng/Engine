///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:50)

#ifndef CORE_TOOLS_TOOLSET_LIB_H
#define CORE_TOOLS_TOOLSET_LIB_H

#include "CoreTools/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CORE_TOOLS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "CoreToolsToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CoreToolsToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_CORE_TOOLS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "CoreToolsToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "CoreToolsToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_CORE_TOOLS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_TOOLSET_LIB_H
