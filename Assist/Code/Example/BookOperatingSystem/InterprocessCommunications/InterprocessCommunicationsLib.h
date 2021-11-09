///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.2.3 (2021/09/08 21:14)

#ifndef INTERPROCESS_COMMUNICATIONS_LIB_H
#define INTERPROCESS_COMMUNICATIONS_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "InterprocessCommunicationsD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "InterprocessCommunications.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "InterprocessCommunicationsStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "InterprocessCommunicationsStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_INTERPROCESS_COMMUNICATIONS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INTERPROCESS_COMMUNICATIONS_LIB_H
