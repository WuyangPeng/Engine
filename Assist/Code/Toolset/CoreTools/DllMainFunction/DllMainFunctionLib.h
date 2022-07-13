///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 17:17)

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