///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/19 23:07)

#ifndef IVOR_HORTONS_BEGINNING_VISUAL_CPP_SEVENTH_EDITION_LIB_H
#define IVOR_HORTONS_BEGINNING_VISUAL_CPP_SEVENTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_IVOR_HORTONS_BEGINNING_VISUAL_CPP_SEVENTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppSeventhEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppSeventhEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_IVOR_HORTONS_BEGINNING_VISUAL_CPP_SEVENTH_EDITION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppSeventhEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "IvorHortonsBeginningVisualCppSeventhEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_IVOR_HORTONS_BEGINNING_VISUAL_CPP_SEVENTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // IVOR_HORTONS_BEGINNING_VISUAL_CPP_SEVENTH_EDITION_LIB_H
