/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/23 22:28)

#ifndef DATABASE_GENERATE_CORE_LIB_H
#define DATABASE_GENERATE_CORE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATABASE_GENERATE_CORE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateCoreD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateCore.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATABASE_GENERATE_CORE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DatabaseGenerateCoreStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DatabaseGenerateCoreStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATABASE_GENERATE_CORE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATABASE_GENERATE_CORE_LIB_H