///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 23:16)

#include "Example/BookCpp/EssentialCpp/EssentialCppExport.h"

#include "EssentialCpp.h" 

#ifndef BUILDING_ESSENTIAL_CPP_STATIC

    #include "DllLib.h"

#else  // !BUILDING_ESSENTIAL_CPP_STATIC

namespace EssentialCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_ESSENTIAL_CPP_STATIC
