///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.2 (2023/02/05 14:43)

#ifndef CORE_TOOLS_DLL_LIB_H
#define CORE_TOOLS_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"

#if defined(TCRE_USE_MSVC)

    #ifdef CORE_TOOLS_USE_OPENXLSX

        #ifdef _DEBUG

            #pragma comment(lib, "OpenXLSXd.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "OpenXLSX.lib")

        #endif  // _DEBUG

    #endif  // CORE_TOOLS_USE_OPENXLSX

    #pragma comment(lib, "miniz.lib")

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_DLL_LIB_H