///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 15:32)

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
