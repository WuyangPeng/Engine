///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.0 (2021/02/23 22:17)

#ifndef BOOK_EXPERIENCE_TOOLSET_LIB_H
#define BOOK_EXPERIENCE_TOOLSET_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookExperienceToolsetD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookExperienceToolset.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookExperienceToolsetStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookExperienceToolsetStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_EXPERIENCE_TOOLSET_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_EXPERIENCE_TOOLSET_LIB_H
