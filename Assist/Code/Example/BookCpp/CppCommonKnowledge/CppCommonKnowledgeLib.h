///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.0 (2021/02/16 17:45)

#ifndef CPP_COMMON_KNOWLEDGE_LIB_H
#define CPP_COMMON_KNOWLEDGE_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "CppCommonKnowledgeD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppCommonKnowledge.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "CppCommonKnowledgeStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "CppCommonKnowledgeStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_CPP_COMMON_KNOWLEDGE_STATIC

#endif  // TCRE_USE_MSVC

#endif  // CPP_COMMON_KNOWLEDGE_LIB_H
