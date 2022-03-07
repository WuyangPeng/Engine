///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/26 14:31)

#ifndef SCRIPT_LIB_H
#define SCRIPT_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SCRIPT_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ScriptD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Script.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_SCRIPT_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ScriptStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ScriptStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_SCRIPT_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SCRIPT_LIB_H