/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 10:01)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_VARIABLE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_VARIABLE_DETAIL_H

#include "LinearComplementarityProblemSolverVariable.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolverVariable<Real>::LinearComplementarityProblemSolverVariable() noexcept
    : name{ 0 }, index{ 0 }, complementary{ 0 }, tuple{ nullptr }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolverVariable<Real>::LinearComplementarityProblemSolverVariable(char name, int index, int complementary, Real* tuple) noexcept
    : name{ name }, index{ index }, complementary{ complementary }, tuple(tuple)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolverVariable<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
char Mathematics::LinearComplementarityProblemSolverVariable<Real>::GetName() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return name;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverVariable<Real>::SetName(char aName) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    name = aName;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::LinearComplementarityProblemSolverVariable<Real>::GetIndex() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return index;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverVariable<Real>::SetIndex(int aIndex) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    index = aIndex;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::LinearComplementarityProblemSolverVariable<Real>::GetComplementary() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return complementary;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverVariable<Real>::SetComplementary(int aComplementary) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    complementary = aComplementary;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real* Mathematics::LinearComplementarityProblemSolverVariable<Real>::GetTuple() noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return tuple;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverVariable<Real>::SetTuple(Real* aTuple) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    tuple = aTuple;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_VARIABLE_DETAIL_H
