///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 15:40)

#ifndef DATA_EDITOR_LIB_H
#define DATA_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_DATA_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "DataEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DataEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_DATA_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "DataEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "DataEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_DATA_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // DATA_EDITOR_LIB_H
