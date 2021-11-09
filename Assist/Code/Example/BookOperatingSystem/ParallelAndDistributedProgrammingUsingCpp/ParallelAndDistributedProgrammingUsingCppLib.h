///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.2.5 (2021/10/28 22:19)

#ifndef PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_LIB_H
#define PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_LIB_H

#include "Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_STATIC

        #ifdef _DEBUG
            #pragma comment(lib, "ParallelAndDistributedProgrammingUsingCppD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ParallelAndDistributedProgrammingUsingCpp.lib")
        #endif  // _DEBUG

    #else  // !BUILDING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG
            #pragma comment(lib, "ParallelAndDistributedProgrammingUsingCppStaticD.lib")
        #else  // !_DEBUG
            #pragma comment(lib, "ParallelAndDistributedProgrammingUsingCppStatic.lib")
        #endif  // _DEBUG

    #endif  // BUILDING_PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_STATIC

#endif  // TCRE_USE_MSVC

#endif  // PARALLEL_AND_DISTRIBUTED_PROGRAMMING_USING_CPP_LIB_H
