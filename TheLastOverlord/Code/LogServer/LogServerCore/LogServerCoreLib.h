/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#ifndef LOG_SERVER_CORE_LIB_H
#define LOG_SERVER_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_LOG_SERVER_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "LogServerCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LogServerCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_LOG_SERVER_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "LogServerCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "LogServerCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_LOG_SERVER_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // LOG_SERVER_CORE_LIB_H