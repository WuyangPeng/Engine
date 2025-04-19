/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 10:01)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_VARIABLE_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_VARIABLE_H

#include "Mathematics/MathematicsDll.h"

#include <type_traits>

namespace Mathematics
{
    /// 求解器迭代过程中的变量记账。名称为'w'或'z'，用于提供可读的调试帮助。
    /// 'index'是原始变量 w[index]或z[index]的索引。
    /// “互补”索引是互补变量在varBasic[]或varNonbasic[]中的位置。
    /// “元组”是指向&w[0] 或 &z[0]的指针，这是基于名称'w' 或 'z'的选择，
    /// 用于填充解决方案值（变量在数据透视算法中进行排列）。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolverVariable
    {
    public:
        using ClassType = LinearComplementarityProblemSolverVariable<Real>;

    public:
        LinearComplementarityProblemSolverVariable() noexcept;

        LinearComplementarityProblemSolverVariable(char name, int index, int complementary, Real* tuple) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD char GetName() const noexcept;
        void SetName(char aName) noexcept;

        NODISCARD int GetIndex() const noexcept;
        void SetIndex(int aIndex) noexcept;

        NODISCARD int GetComplementary() const noexcept;
        void SetComplementary(int aComplementary) noexcept;

        NODISCARD Real* GetTuple() noexcept;
        void SetTuple(Real* aTuple) noexcept;

    private:
        char name;
        int index;
        int complementary;
        Real* tuple;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_VARIABLE_H
