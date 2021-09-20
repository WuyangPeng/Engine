///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/02/28 19:36)

#ifndef STANDARD_CPP_IO_STREAMS_AND_LOCALES_LIB_H
#define STANDARD_CPP_IO_STREAMS_AND_LOCALES_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STANDARD_CPP_IO_STREAMS_AND_LOCALES_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "StandardCppIOStreamsAndLocalesD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "StandardCppIOStreamsAndLocales.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_STANDARD_CPP_IO_STREAMS_AND_LOCALES_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "StandardCppIOStreamsAndLocalesStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "StandardCppIOStreamsAndLocalesStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_STANDARD_CPP_IO_STREAMS_AND_LOCALES_STATIC

#endif  // TCRE_USE_MSVC

#endif  // STANDARD_CPP_IO_STREAMS_AND_LOCALES_LIB_H
