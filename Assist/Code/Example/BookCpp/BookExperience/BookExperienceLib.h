///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.0.1 (2021/02/15 23:51)

#ifndef BOOK_EXPERIENCE_LIB_H
#define BOOK_EXPERIENCE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOK_EXPERIENCE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BookExperienceD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookExperience.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOK_EXPERIENCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "BookExperienceStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BookExperienceStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOK_EXPERIENCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOK_EXPERIENCE_LIB_H
