///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.0.0 (2021/01/23 16:05)

#include "Example/BookCpp/HowNotToProgramInCpp/HowNotToProgramInCppExport.h"

#include "HowNotToProgramInCpp.h"

#ifndef BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC

namespace HowNotToProgramInCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_HOW_NOT_TO_PROGRAM_IN_CPP_STATIC
