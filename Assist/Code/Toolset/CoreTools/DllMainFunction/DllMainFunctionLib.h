/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 17:45)

#ifndef DLL_MAIN_FUNCTION_LIB_H
#define DLL_MAIN_FUNCTION_LIB_H

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DllMainFunctionD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DllMainFunction.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DllMainFunctionStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DllMainFunctionStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DLL_MAIN_FUNCTION_LIB_H