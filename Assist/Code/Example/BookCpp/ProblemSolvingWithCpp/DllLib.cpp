///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.6.0.0 (2020/12/26 21:29)

#include "Example/BookCpp/ProblemSolvingWithCpp/ProblemSolvingWithCppExport.h"

#include "ProblemSolvingWithCpp.h"

#ifndef BUILDING_PROBLEM_SOLVING_WITH_CPP_STATIC

    #include "DllLib.h"

#else  // BUILDING_PROBLEM_SOLVING_WITH_CPP_STATIC

namespace ProblemSolvingWithCpp
{
    void StaticDllLib() noexcept
    {
    }
}

#endif  // !BUILDING_PROBLEM_SOLVING_WITH_CPP_STATIC
