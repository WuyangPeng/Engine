///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/25 16:11)

#ifndef RELATION_LIB_H
#define RELATION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_RELATION_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "RelationD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Relation.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_RELATION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "RelationStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "RelationStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_RELATION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // RELATION_LIB_H
