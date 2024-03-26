/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 20:18)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_DETAIL_H

#include "LinearComplementarityProblemSolver.h"
#include "LinearComplementarityProblemSolverVariableDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real, int... Dimensions>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolver<Real, Dimensions...>::LinearComplementarityProblemSolver() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int... Dimensions>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolver<Real, Dimensions...>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolver<Real, N>::LinearComplementarityProblemSolver() noexcept
    : ParentType{ N },
      arrayVarBasic{},
      arrayVarNonbasic{},
      arrayAugmented{},
      arrayQMin{},
      arrayMinRatio{},
      arrayRatio{},
      arrayPoly{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real, int N>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolver<Real, N>::LinearComplementarityProblemSolver(const Real& zero, const Real& one) noexcept
    : ParentType{ N, zero, one },
      arrayVarBasic{},
      arrayVarNonbasic{},
      arrayAugmented{},
      arrayQMin{},
      arrayMinRatio{},
      arrayRatio{},
      arrayPoly{}
{
    this->SetVariableData(arrayVarBasic.data(),
                          arrayVarNonbasic.data(),
                          2 * (N + 1),
                          arrayAugmented.data(),
                          arrayQMin.data(),
                          arrayMinRatio.data(),
                          arrayRatio.data(),
                          arrayPoly.data());

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolver<Real, N>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolver<Real, N>::Solve(const std::array<Real, N>& q, const std::array<std::array<Real, N>, N>& m, std::array<Real, N>& w, std::array<Real, N>& z, LinearComplementarityProblemSolverType* result)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return ParentType::Solve(q.data(), m.front().data(), w.data(), z.data(), result);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolver<Real>::LinearComplementarityProblemSolver(int n)
    : ParentType{ n },
      vectorVarBasic(n > 0 ? n + 1 : 0),
      vectorVarNonbasic(n > 0 ? n + 1 : 0),
      vectorAugmented(n > 0 ? 2 * (n + 1) * n : 0),
      vectorQMin(n > 0 ? n + 1 : 0),
      vectorMinRatio(n > 0 ? n + 1 : 0),
      vectorRatio(n > 0 ? n + 1 : 0),
      vectorPoly(n)
{
    if (n > 0)
    {
        this->SetVariableData(vectorVarBasic.data(),
                              vectorVarNonbasic.data(),
                              2 * (n + 1),
                              vectorAugmented.data(),
                              vectorQMin.data(),
                              vectorMinRatio.data(),
                              vectorRatio.data(),
                              vectorPoly.data());
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolver<Real>::IsValid() const noexcept
{
    return ParentType::IsValid();
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolver<Real>::Solve(const std::vector<Real>& q, const std::vector<Real>& m, std::vector<Real>& w, std::vector<Real>& z, LinearComplementarityProblemSolverType* result)
{
    if (this->GetDimension() > boost::numeric_cast<int>(q.size()) || this->GetDimension() * this->GetDimension() > boost::numeric_cast<int>(m.size()))
    {
        if (result)
        {
            *result = LinearComplementarityProblemSolverType::InvalidInput;
        }
        return false;
    }

    if (this->GetDimension() > boost::numeric_cast<int>(w.size()))
    {
        w.resize(this->GetDimension());
    }

    if (this->GetDimension() > boost::numeric_cast<int>(z.size()))
    {
        z.resize(this->GetDimension());
    }

    return ParentType::Solve(q.data(), m.data(), w.data(), z.data(), result);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_DETAIL_H
