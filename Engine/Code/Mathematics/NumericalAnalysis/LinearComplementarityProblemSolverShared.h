/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 20:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_SHARED_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_SHARED_H

#include "Mathematics/MathematicsDll.h"

#include "NumericalAnalysisFwd.h"

/// 求解线性互补问题（LCP）的一个类w = q + M * z, w^Real * z = 0, w >= 0, z >= 0。
/// 向量q、w和z是n元组，矩阵M是n乘n。
/// Solve(...)的输入是q和M。
/// 输出是w和z，当返回的bool为true时有效，但当返回的bool为false时无效。

// 该文件末尾的注释解释了预处理器符号对LCP求解器实现的意义。
// 如果算法未能在指定的最大迭代次数内收敛，
// 请考虑增加迭代次数并再次调用Solve(...)。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class LinearComplementarityProblemSolverShared
    {
    public:
        using ClassType = LinearComplementarityProblemSolverShared<Real>;

    public:
        /// 成员maxIterations通过此调用设置为默认值n*n。
        explicit LinearComplementarityProblemSolverShared(int n) noexcept;

        /// 当您需要在操作基类的多项式时使用零和一的特定表示时，请使用此构造函数。
        /// 特别是，这是为QFNumber对象选择正确的零和正确的一所必需的。
        explicit LinearComplementarityProblemSolverShared(int n, const Real& zero, const Real& one) noexcept;

        virtual ~LinearComplementarityProblemSolverShared() noexcept = default;
        LinearComplementarityProblemSolverShared(const LinearComplementarityProblemSolverShared& rhs) = delete;
        LinearComplementarityProblemSolverShared& operator=(const LinearComplementarityProblemSolverShared& rhs) = delete;
        LinearComplementarityProblemSolverShared(LinearComplementarityProblemSolverShared&& rhs) noexcept = delete;
        LinearComplementarityProblemSolverShared& operator=(LinearComplementarityProblemSolverShared&& rhs) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        /// 理论上，当存在解时，算法必须在有限次数的迭代中收敛。
        /// 迭代次数取决于手头的问题，但我们需要通过限制次数来防止无限循环。
        /// 该实现使用最大数量n*n（任意选择）。
        /// 您可以自己设置数字，也许当调用Solve失败时——增加迭代次数，然后再次调用并求解。
        void SetMaxIterations(int aMaxIterations) noexcept;

        NODISCARD int GetMaxIterations() const noexcept;

        /// 访问调用Solve中使用的实际迭代次数。
        NODISCARD int GetNumIterations() const noexcept;

    protected:
        using Variable = LinearComplementarityProblemSolverVariable<Real>;

    protected:
        /// 增广问题是w = q + M*z + z[n]*U = 0，其中U是1值的n元组。
        /// 我们对增广矩阵M | U | p(t)]进行运算，其中p(t) 是至多n次多项式的列向量。
        /// 如果p[r](t) 是行r的多项式，则p[r](0) = q[r]。
        /// 这些是q[r]的扰动，设计为使算法避免退化（在迭代过程中q项变为零）。
        /// 基本变量是w[0]到w[n-1]，非基本变量是z[0]到z[n]。
        /// 返回的z仅由z[0]到z[n-1]组成。

        /// 派生类确保指针指向每个数组的正确元素。矩阵m必须按行的主要顺序存储。
        NODISCARD bool Solve(const Real* q, const Real* m, Real* w, Real* z, LinearComplementarityProblemSolverType* result);

        /// 增强为二维数组。
        NODISCARD const Real& Augmented(int row, int col) const noexcept;

        NODISCARD Real& Augmented(int row, int col) noexcept;

        /// 支持n+1个系数和次数不大于n的多项式。
        void MakeZero(Real* aPoly) noexcept;

        void Copy(const Real* poly0, Real* poly1) noexcept;

        bool LessThan(const Real* poly0, const Real* poly1) noexcept;

        bool LessThanZero(const Real* aPoly) noexcept;

        void Multiply(const Real* aPoly, Real scalar, Real* product) noexcept;

        void SetVariableData(Variable* aVarBasic, Variable* aVarNonbasic, int aNumCols, Real* aAugmented, Real* aQMin, Real* aMinRatio, Real* aRatio, Real** aPoly) noexcept;

        NODISCARD int GetDimension() const noexcept;

    private:
        int dimension;
        int maxIterations;
        int numIterations;

        /// 这些指针由派生类构造函数设置为具有正确元素数的数组。
        /// 数组varBasic、varNonbasic、qMin、minRatio和ratio各有n+1个元素。
        /// 增广数组具有n行和2*(n+1)列，它们以行主顺序存储在一维数组中。
        /// 指针数组poly有n个元素。
        Variable* varBasic;
        Variable* varNonbasic;
        int numCols;
        Real* augmented;
        Real* qMin;
        Real* minRatio;
        Real* ratio;
        Real** poly;
        Real zero;
        Real one;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_COMPLEMENTARITY_PROBLEM_SOLVER_SHARED_H
