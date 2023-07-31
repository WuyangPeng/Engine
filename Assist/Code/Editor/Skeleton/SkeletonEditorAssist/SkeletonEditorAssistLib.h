///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/31 14:30)

#ifndef SKELETON_EDITOR_LIB_H
#define SKELETON_EDITOR_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_SKELETON_EDITOR_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "SkeletonEditorAssistD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SkeletonEditorAssist.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_SKELETON_EDITOR_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "SkeletonEditorAssistStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "SkeletonEditorAssistStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_SKELETON_EDITOR_STATIC

#endif  // TCRE_USE_MSVC

#endif  // SKELETON_EDITOR_LIB_H
