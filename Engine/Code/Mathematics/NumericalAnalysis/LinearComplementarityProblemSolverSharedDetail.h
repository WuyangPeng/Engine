/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 20:20)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_SHARED_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_SHARED_DETAIL_H

#include "LinearComplementarityProblemSolverShared.h"
#include "LinearComplementarityProblemSolverVariableDetail.h"
#include "Flags/LinearComplementarityProblemSolverType.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolverShared<Real>::LinearComplementarityProblemSolverShared(int n) noexcept
    : dimension{ n > 0 ? n : 0 },
      maxIterations{ n * n },
      numIterations{ 0 },
      varBasic{ nullptr },
      varNonbasic{ nullptr },
      numCols{ 0 },
      augmented{ nullptr },
      qMin{ nullptr },
      minRatio{ nullptr },
      ratio{ nullptr },
      poly{ nullptr },
      zero{},
      one{ 1 }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::LinearComplementarityProblemSolverShared<Real>::LinearComplementarityProblemSolverShared(int n, const Real& zero, const Real& one) noexcept
    : dimension{ n > 0 ? n : 0 },
      maxIterations{ n * n },
      numIterations{ 0 },
      varBasic{ nullptr },
      varNonbasic{ nullptr },
      numCols{ 0 },
      augmented{ nullptr },
      qMin{ nullptr },
      minRatio{ nullptr },
      ratio{ nullptr },
      poly{ nullptr },
      zero{ zero },
      one{ one }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolverShared<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverShared<Real>::SetMaxIterations(int aMaxIterations) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    maxIterations = (aMaxIterations > 0 ? aMaxIterations : dimension * dimension);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::LinearComplementarityProblemSolverShared<Real>::GetMaxIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxIterations;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::LinearComplementarityProblemSolverShared<Real>::GetNumIterations() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return numIterations;
}

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolverShared<Real>::Solve(const Real* q, const Real* m, Real* w, Real* z, LinearComplementarityProblemSolverType* result)
{
    /// 将q[r]常数扰动为r+1次多项式，表示为n+1个系数的数组。
    /// 具有索引r+1的系数是1，并且具有大于r+1的索引的系数是0。
    for (auto r = 0; r < dimension; ++r)
    {
        poly[r] = &Augmented(r, dimension + 1);
        MakeZero(poly[r]);
        poly[r][0] = q[r];
        poly[r][r + 1] = one;
    }

    /// 确定是否存在平凡解 w = z = 0.
    Copy(poly[0], qMin);
    auto basic = 0;
    for (auto r = 1; r < dimension; ++r)
    {
        if (LessThan(poly[r], qMin))
        {
            Copy(poly[r], qMin);
            basic = r;
        }
    }

    if (!LessThanZero(qMin))
    {
        for (auto r = 0; r < dimension; ++r)
        {
            w[r] = q[r];
            z[r] = zero;
        }

        if (result)
        {
            *result = LinearComplementarityProblemSolverType::HasTrivialSolution;
        }
        return true;
    }

    /// 用m和U初始化增广矩阵的剩余部分。
    for (auto r = 0; r < dimension; ++r)
    {
        for (auto c = 0; c < dimension; ++c)
        {
            Augmented(r, c) = m[c + dimension * r];
        }
        Augmented(r, dimension) = one;
    }

    /// 跟踪变量何时进入和退出字典，包括补充变量的重新定位位置。
    for (auto i = 0; i <= dimension; ++i)
    {
        varBasic[i].SetName('w');
        varBasic[i].SetIndex(i);
        varBasic[i].SetComplementary(i);
        varBasic[i].SetTuple(w);
        varNonbasic[i].SetName('z');
        varNonbasic[i].SetIndex(i);
        varNonbasic[i].SetComplementary(i);
        varNonbasic[i].SetTuple(z);
    }

    /// 增广变量z[n]是用于枢转的初始驱动变量。
    /// 方程“basic”是要求解z[n]和以w为中心的方程。
    /// 对于这个初始步骤，m的最后一列仍然是所有的1-值，
    /// 因此m[r][n]不发生代数计算。
    auto driving = dimension;
    for (auto r = 0; r < dimension; ++r)
    {
        if (r != basic)
        {
            for (auto c = 0; c < numCols; ++c)
            {
                if (c != dimension)
                {
                    Augmented(r, c) -= Augmented(basic, c);
                }
            }
        }
    }

    for (auto c = 0; c < numCols; ++c)
    {
        if (c != dimension)
        {
            Augmented(basic, c) = -Augmented(basic, c);
        }
    }

    numIterations = 0;
    for (auto i = 0; i < maxIterations; ++i, ++numIterations)
    {
        /// 方程“basic”的基本变量已退出字典，
        /// 因此/其互补（非基本）变量必须成为下一个驱动变量才能进入字典。
        auto nextDriving = varBasic[basic].GetComplementary();
        varNonbasic[nextDriving].SetComplementary(driving);
        std::swap(varBasic[basic], varNonbasic[driving]);
        if (varNonbasic[driving].GetIndex() == dimension)
        {
            /// 算法已经收敛。
            for (auto r = 0; r < dimension; ++r)
            {
                varBasic[r].GetTuple()[varBasic[r].GetIndex()] = poly[r][0];
            }
            for (auto c = 0; c <= dimension; ++c)
            {
                auto index = varNonbasic[c].GetIndex();
                if (index < dimension)
                {
                    varNonbasic[c].GetTuple()[index] = zero;
                }
            }
            if (result)
            {
                *result = LinearComplementarityProblemSolverType::HasNontrivialSolution;
            }
            return true;
        }

        /// 在m(r,driving) < 0的所有方程r中，确定比值-q[r]/m(r,driving)最小化的“基本”方程。
        driving = nextDriving;
        basic = -1;
        for (auto r = 0; r < dimension; ++r)
        {
            if (Augmented(r, driving) < zero)
            {
                auto factor = -one / Augmented(r, driving);
                Multiply(poly[r], factor, ratio);
                if (basic == -1 || LessThan(ratio, minRatio))
                {
                    Copy(ratio, minRatio);
                    basic = r;
                }
            }
        }

        if (basic == -1)
        {
            /// 所有方程中的z[driving]的系数都是非负的，
            /// 因此z[driving]变量不能离开字典。
            /// 无导线心脏起搏器没有解决方案。
            for (auto r = 0; r < dimension; ++r)
            {
                w[r] = zero;
                z[r] = zero;
            }

            if (result)
            {
                *result = LinearComplementarityProblemSolverType::NoSolution;
            }
            return false;
        }

        /// 求解基本方程，使z[driving]进入字典，w[basic]退出字典。
        auto invDenominator = one / Augmented(basic, driving);
        for (int r = 0; r < dimension; ++r)
        {
            if (r != basic && Augmented(r, driving) != zero)
            {
                auto multiplier = Augmented(r, driving) * invDenominator;
                for (auto c = 0; c < numCols; ++c)
                {
                    if (c != driving)
                    {
                        Augmented(r, c) -= Augmented(basic, c) * multiplier;
                    }
                    else
                    {
                        Augmented(r, driving) = multiplier;
                    }
                }
            }
        }

        for (auto c = 0; c < numCols; ++c)
        {
            if (c != driving)
            {
                Augmented(basic, c) = -Augmented(basic, c) * invDenominator;
            }
            else
            {
                Augmented(basic, driving) = invDenominator;
            }
        }
    }

    /// 数值舍入误差可能会导致Lemke算法无法收敛。
    /// 特别是，上面的代码有一个测试，
    /// if (augmented[r][driving] < (Real)0) { ... }，
    /// 以确定要旋转的“基本”方程。
    /// 理论上augmented[r][driving]可能为零，但舍入误差会使其略为负值
    /// 。如果理论上所有augmented[r][driving]>=0，则无导线心脏起搏器没有解决方案。
    /// 对于舍入误差，如果算法未能在指定的迭代次数内收敛，则返回NO_SOLUTION，这有望是正确的结果。
    /// 当事实上有解决方案时，舍入误差也可能导致NO_SOLUTION（从循环内部返回）。
    /// 当交叉测试算法使用LCP求解器时，希望只有当两个对象几乎相切接触时才会发生错误分类。
    ///
    /// 为了确定舍入错误是否是问题所在，您可以使用以下类型的精确算术执行查询，
    /// 该类型用于BSRational<UIntegerAP32>的“Real”（替换'float'或'double'）。
    ///
    /// 也就是说，如果算法无法收敛，并且您认为舍入误差不是导致这种情况的原因，
    /// 请提交错误报告并将输入数据提供给求解器。

#if defined(MATHEMATICS_THROW_ON_LCP_SOLVER_ERRORS)

    THROW_EXCEPTION(SYSTEM_TEXT("LinearComplementarityProblemSolverShared::Solve 未能收敛。"))

#else  // !MATHEMATICS_THROW_ON_LCP_SOLVER_ERRORS

    if (result)
    {
        *result = LinearComplementarityProblemSolverType::FailedToConverge;
    }

    return false;

#endif  // MATHEMATICS_THROW_ON_LCP_SOLVER_ERRORS
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real const& Mathematics::LinearComplementarityProblemSolverShared<Real>::Augmented(int row, int col) const noexcept
{
    return augmented[col + numCols * row];
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real& Mathematics::LinearComplementarityProblemSolverShared<Real>::Augmented(int row, int col) noexcept
{
    return augmented[col + numCols * row];
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverShared<Real>::MakeZero(Real* aPoly) noexcept
{
    for (auto i = 0; i <= dimension; ++i)
    {
        aPoly[i] = zero;
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverShared<Real>::Copy(const Real* poly0, Real* poly1) noexcept
{
    for (auto i = 0; i <= dimension; ++i)
    {
        poly1[i] = poly0[i];
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolverShared<Real>::LessThan(const Real* poly0, const Real* poly1) noexcept
{
    for (auto i = 0; i <= dimension; ++i)
    {
        if (poly0[i] < poly1[i])
        {
            return true;
        }

        if (poly0[i] > poly1[i])
        {
            return false;
        }
    }

    return false;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::LinearComplementarityProblemSolverShared<Real>::LessThanZero(const Real* aPoly) noexcept
{
    for (auto i = 0; i <= dimension; ++i)
    {
        if (aPoly[i] < zero)
        {
            return true;
        }

        if (aPoly[i] > zero)
        {
            return false;
        }
    }

    return false;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverShared<Real>::Multiply(const Real* aPoly, Real scalar, Real* product) noexcept
{
    for (auto i = 0; i <= dimension; ++i)
    {
        product[i] = aPoly[i] * scalar;
    }
}

#include SYSTEM_WARNING_POP

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::LinearComplementarityProblemSolverShared<Real>::SetVariableData(Variable* aVarBasic, Variable* aVarNonbasic, int aNumCols, Real* aAugmented, Real* aQMin, Real* aMinRatio, Real* aRatio, Real** aPoly) noexcept
{
    this->varBasic = aVarBasic;
    this->varNonbasic = aVarNonbasic;
    this->numCols = aNumCols;
    this->augmented = aAugmented;
    this->qMin = aQMin;
    this->minRatio = aMinRatio;
    this->ratio = aRatio;
    this->poly = aPoly;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::LinearComplementarityProblemSolverShared<Real>::GetDimension() const noexcept
{
    return dimension;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_SHARED_DETAIL_H
