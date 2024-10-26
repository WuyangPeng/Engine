/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.1.2 (2024/10/25 17:13)

#ifndef SYSTEM_DLL_LIB_H
#define SYSTEM_DLL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #pragma comment(lib, "Ws2_32.lib")

    #if !defined(SYSTEM_USE_GLUT) || defined(BUILDING_SYSTEM_STATIC)

        #pragma comment(lib, "opengl32.lib")

    #endif  // !defined(SYSTEM_USE_GLUT) || defined(BUILDING_SYSTEM_STATIC)

#endif  // TCRE_USE_MSVC

#endif  // SYSTEM_DLL_LIB_H