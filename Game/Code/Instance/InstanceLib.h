///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������Ϸ�汾��0.9.0.12 (2023/06/16 16:53)

#ifndef INSTANCE_LIB_H
#define INSTANCE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INSTANCE_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "InstanceD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "Instance.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_INSTANCE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "InstanceStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "InstanceStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_INSTANCE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INSTANCE_LIB_H
