///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/31 14:58)

#ifndef MODEL_EDITOR_LIB_H
#define MODEL_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MODEL_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "ModelEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ModelEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_MODEL_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "ModelEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "ModelEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_MODEL_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MODEL_EDITOR_LIB_H
