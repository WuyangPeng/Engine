///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 11:21)

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