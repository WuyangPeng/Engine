///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.1 (2021/03/11 17:51)

#ifndef BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_LIB_H
#define BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "BoostCppApplicationDevelopmentCookbookD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BoostCppApplicationDevelopmentCookbook.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_STATIC

        #include "DllLib.h" 

        #ifdef _DEBUG
            #pragma comment(lib, "BoostCppApplicationDevelopmentCookbookStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "BoostCppApplicationDevelopmentCookbookStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_STATIC

#endif  // TCRE_USE_MSVC

#endif  // BOOST_CPP_APPLICATION_DEVELOPMENT_COOKBOOK_LIB_H
