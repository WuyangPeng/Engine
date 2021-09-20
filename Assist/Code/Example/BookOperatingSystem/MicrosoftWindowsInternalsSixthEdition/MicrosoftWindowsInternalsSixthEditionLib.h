///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.3 (2021/05/01 19:02)

#ifndef MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_LIB_H
#define MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "MicrosoftWindowsInternalsSixthEditionD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MicrosoftWindowsInternalsSixthEdition.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "MicrosoftWindowsInternalsSixthEditionStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "MicrosoftWindowsInternalsSixthEditionStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MICROSOFT_WINDOWS_INTERNALS_SIXTH_EDITION_LIB_H
