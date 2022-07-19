///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.8.0.11 (2022/07/18 14:34)

#ifndef STATUSLIB_H
#define STATUSLIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_STATUSSTATIC

        #ifdef _DEBUG
            #pragma comment(lib, "StatusD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "Status.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_STATUSSTATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "StatusStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "StatusStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_STATUSSTATIC

#endif  // TCRE_USE_MSVC

#endif  // STATUSLIB_H
