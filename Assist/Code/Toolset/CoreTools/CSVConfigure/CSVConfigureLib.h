///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 17:14)

#ifndef CSV_CONFIGURE_LIB_H
#define CSV_CONFIGURE_LIB_H

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CSVConfigureD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CSVConfigure.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CSVConfigureStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CSVConfigureStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CSV_CONFIGURE_LIB_H