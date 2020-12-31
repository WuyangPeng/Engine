//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.1 (2020/09/28 11:51)

#ifndef CORE_TOOLS_DLL_LIB_H
#define CORE_TOOLS_DLL_LIB_H

#include "Helper/UserMacro.h"

#include "System/SystemLib.h"

#if defined(TCRE_USE_MSVC)

    #ifdef _DEBUG
        #pragma comment(lib, "zlibd.lib")
        #pragma comment(lib, "freetyped.lib")
    #else  // !_DEBUG
        #pragma comment(lib, "zlib.lib")
        #pragma comment(lib, "freetype.lib")
    #endif  // _DEBUG

#endif  // TCRE_USE_MSVC

#endif  // CORE_TOOLS_DLL_LIB_H