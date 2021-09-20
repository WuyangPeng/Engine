///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef INSIDE_THE_CPP_OBJECT_MODEL_LIB_H
#define INSIDE_THE_CPP_OBJECT_MODEL_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_INSIDE_THE_CPP_OBJECT_MODEL_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "InsideTheCppObjectModelD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "InsideTheCppObjectModel.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_INSIDE_THE_CPP_OBJECT_MODEL_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "InsideTheCppObjectModelStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "InsideTheCppObjectModelStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_INSIDE_THE_CPP_OBJECT_MODEL_STATIC

#endif  // TCRE_USE_MSVC

#endif  // INSIDE_THE_CPP_OBJECT_MODEL_LIB_H