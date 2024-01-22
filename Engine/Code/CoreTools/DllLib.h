/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:03)

#ifndef CORE_TOOLS_DLL_LIB_H
#define CORE_TOOLS_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"

#if defined(TCRE_USE_MSVC)

    #ifdef CORE_TOOLS_USE_OPEN_XLSX

        #ifdef _DEBUG

            #pragma comment(lib, "OpenXLSXd.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "OpenXLSX.lib")

        #endif  // _DEBUG

    #endif  // CORE_TOOLS_USE_OPEN_XLSX

    #pragma comment(lib, "miniz.lib")

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_DLL_LIB_H