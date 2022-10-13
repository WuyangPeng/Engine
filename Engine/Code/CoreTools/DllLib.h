///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 14:28)

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