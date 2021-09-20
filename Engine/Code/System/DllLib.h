///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.1 (2021/03/03 0:26)

#ifndef SYSTEM_DLL_LIB_H
#define SYSTEM_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "Ws2_32.lib")
    #pragma comment(lib, "Dbghelp.lib")
    #pragma comment(lib, "Wininet.lib")

    #if !defined(SYSTEM_USE_GLUT) || defined(BUILDING_SYSTEM_STATIC)
        #pragma comment(lib, "opengl32.lib")
    #endif  // SYSTEM_USE_GLUT

#endif  // TCRE_USE_MSVC

#endif  // SYSTEM_DLL_LIB_H