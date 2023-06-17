///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.12 (2023/06/09 10:33)

#ifndef MATHEMATICS_TOOLSET_LIB_H
#define MATHEMATICS_TOOLSET_LIB_H

#include "Mathematics/Helper/UserMacro.h"

#if defined(TCRE_USE_MSVC)

    #ifndef BUILDING_MATHEMATICS_STATIC

        #ifdef _DEBUG

            #pragma comment(lib, "MathematicsToolsetD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "MathematicsToolset.lib")

        #endif  // _DEBUG

    #else  // !BUILDING_MATHEMATICS_STATIC

        #include "DllLib.h"

        #ifdef _DEBUG

            #pragma comment(lib, "MathematicsToolsetStaticD.lib")

        #else  // !_DEBUG

            #pragma comment(lib, "MathematicsToolsetStatic.lib")

        #endif  // _DEBUG

    #endif  // BUILDING_MATHEMATICS_STATIC

#endif  // TCRE_USE_MSVC

#endif  // MATHEMATICS_TOOLSET_LIB_H
