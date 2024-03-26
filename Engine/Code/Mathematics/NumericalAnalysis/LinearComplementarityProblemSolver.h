/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 20:17)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_H

#include "Mathematics/MathematicsDll.h"

#include "LinearComplementarityProblemSolverShared.h"
#include "LinearComplementarityProblemSolverVariable.h"
#include "Flags/LinearComplementarityProblemSolverType.h"

#include <array>
#include <vector>

namespace Mathematics
{
    /// 支持编译时已知或仅在运行时已知的维度数的模板。
    template <typename Real, int... Dimensions>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolver
    {
    public:
        using ClassType = LinearComplementarityProblemSolver<Real, Dimensions...>;

    public:
        LinearComplementarityProblemSolver() noexcept;

        CLASS_INVARIANT_DECLARE;
    };

    template <typename Real, int N>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolver<Real, N> final : public LinearComplementarityProblemSolverShared<Real>
    {
    public:
        using ClassType = LinearComplementarityProblemSolver<Real, N>;
        using ParentType = LinearComplementarityProblemSolverShared<Real>;

    public:
        /// 成员maxIterations通过此调用设置为默认值n*n。
        LinearComplementarityProblemSolver() noexcept;

        /// 当您需要在操作基类的多项式时使用零和一的特定表示时，请使用此构造函数。
        /// 特别是，这是为QFNumber对象选择正确的零和正确的一所必需的。
        LinearComplementarityProblemSolver(const Real& zero, const Real& one) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        /// 如果您想知道返回'true'或'false'的具体原因，请将Result变量的地址作为最后一个参数传递。
        NODISCARD bool Solve(const std::array<Real, N>& q,
                             const std::array<std::array<Real, N>, N>& m,
                             std::array<Real, N>& w,
                             std::array<Real, N>& z,
                             LinearComplementarityProblemSolverType* result = nullptr);

    private:
        static constexpr auto arrayAugmentedSize = 2 * (N + 1) * N;
        using Variable = LinearComplementarityProblemSolverVariable<Real>;

    private:
        std::array<Variable, N + 1> arrayVarBasic;
        std::array<Variable, N + 1> arrayVarNonbasic;
        std::array<Real, arrayAugmentedSize> arrayAugmented;
        std::array<Real, N + 1> arrayQMin;
        std::array<Real, N + 1> arrayMinRatio;
        std::array<Real, N + 1> arrayRatio;
        std::array<Real*, N> arrayPoly;
    };

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolver<Real> final : public LinearComplementarityProblemSolverShared<Real>
    {
    public:
        using ClassType = LinearComplementarityProblemSolver<Real>;
        using ParentType = LinearComplementarityProblemSolverShared<Real>;

    public:
        /// 成员maxIterations通过此调用设置为默认值n*n。
        explicit LinearComplementarityProblemSolver(int n);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        /// 输入q必须具有n个元素，并且输入m必须是按行主顺序存储的n乘n矩阵。
        /// 输出w和z具有n个元素。如果您想知道返回“true”或“false”的具体原因，
        /// 请将Result变量的地址作为最后一个参数传递。
        NODISCARD bool Solve(const std::vector<Real>& q,
                             const std::vector<Real>& m,
                             std::vector<Real>& w,
                             std::vector<Real>& z,
                             LinearComplementarityProblemSolverType* result = nullptr);

    private:
        using Variable = LinearComplementarityProblemSolverVariable<Real>;

    private:
        std::vector<Variable> vectorVarBasic;
        std::vector<Variable> vectorVarNonbasic;
        std::vector<Real> vectorAugmented;
        std::vector<Real> vectorQMin;
        std::vector<Real> vectorMinRatio;
        std::vector<Real> vectorRatio;
        std::vector<Real*> vectorPoly;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_H
