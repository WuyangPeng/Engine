/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 09:58)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_TYPE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_TYPE_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    enum class LinearComplementarityProblemSolverType
    {
        HasTrivialSolution,
        HasNontrivialSolution,
        NoSolution,
        FailedToConverge,
        InvalidInput
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_TYPE_H
