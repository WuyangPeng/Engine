/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 10:03)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_H

#include "Mathematics/MathematicsDll.h"

#include "CholeskyDecomposition.h"
#include "GaussNewtonMinimizerResult.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

/// 设F(p) = (F_{0}(p), F_{1}(p), ..., F_{n-1}(p))是参数p = (p_{0}, p_{1}, ..., p_{m-1})的向量值函数。
/// 非线性最小二乘问题是使实值误差函数E(p) = |F(p)|^2最小化，这是F(p)的平方长度。
///
/// 设 J = dF/dp = [dF_{r}/dp_{c}]表示雅可比矩阵，它是F的一阶偏导数的矩阵。
/// 矩阵有n行m列，索引(r,c) 指的是行r和列c。
/// 一阶近似为F(p + d) = F(p) + J(p)d，其中d是一个长度很小的m-by-1向量。
/// 因此，E的近似值为E(p + d) = |F(p + d)|^2 = |F(p) + J(p)d|^2。
/// 目标是选择d来最小化|F(p) + J(p)d|^2 ，并且希望E(p + d) < E(p)。
/// 选择一个初始p_{0}，希望该算法生成一个序列p_{i}，其中E(p_{i+1}) < E(p_{i})，
/// 并且在极限中E(p_{j}) 接近E的全局最小值。
/// 该算法被称为高斯-牛顿迭代。
/// 如果E在算法的一个步骤中不减小，则可以将算法修改为Levenberg-Marquardt迭代。
/// 有关描述和实现，请参见LevenbergMarquardtMinimizer.h。
///
/// 对于单个高斯-牛顿迭代，我们需要选择d来最小化|F(p) + J(p)d|^2，其中p是固定的。
/// 这是一个线性最小二乘问题，可以用正规方程(J^T(p)*J(p))*d = -J^T(p)*F(p)来表示。
/// 矩阵J^T*J是半正定的。
/// 如果它是可逆的，则d = -(J^T(p)*J(p))^{-1}*F(p)。
/// 如果它是不可逆的，则必须使用其他一些算法来选择d；
/// 一种选择是使用梯度下降的步骤。
/// Cholesky分解可以用于求解线性系统。
///
/// 尽管一个实现可以允许调用方传递函数F_{i}(p)的数组和导数dF_{r}/dp_{c}的数组，
/// 但一些应用程序可能涉及非常大的n，
/// 由于内存需求过大，无法存储所有计算的雅可比矩阵项。
/// 在这样的应用中，最好计算m乘m矩阵J^T*J和m乘1向量J^T*F的项。
/// 通常，m很小，因此内存需求不会过大。
/// 此外，可能存在调用方可以利用的F的附加结构；
/// 例如， F(p)的分量的3元组可能对应于可以使用现有数学库进行操作的向量。这里的实施支持这两种方法。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class GaussNewtonMinimizer
    {
    public:
        using ClassType = GaussNewtonMinimizer<Real>;

        using GaussNewtonMinimizerResult = GaussNewtonMinimizerResult<Real>;

        /// 域向量、范围向量、函数F和雅可比J的方便类型。
        using DVector = VariableLengthVector<Real>;  // numPDimensions
        using RVector = VariableLengthVector<Real>;  // numFDimensions
        using JMatrix = VariableMatrix<Real>;  // numFDimensions-by-numPDimensions
        using JtjMatrix = VariableMatrix<Real>;  // numPDimensions-by-numPDimensions
        using JtfVector = VariableLengthVector<Real>;  // numPDimensions
        using FFunction = std::function<void(DVector const&, RVector&)>;
        using JFunction = std::function<void(DVector const&, JMatrix&)>;
        using JPlusFunction = std::function<void(DVector const&, JtjMatrix&, JtfVector&)>;

    public:
        /// 创建直接计算F(p)和 J(p)的最小化器。
        GaussNewtonMinimizer(int numPDimensions, int numFDimensions, FFunction inFFunction, JFunction inJFunction);

        /// 创建计算J^T(p)*J(p)和-J(p)*F(p)的最小值。
        GaussNewtonMinimizer(int numPDimensions, int numFDimensions, FFunction inFFunction, JPlusFunction inJPlusFunction);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumPDimensions() const noexcept;
        NODISCARD int GetNumFDimensions() const noexcept;

        NODISCARD GaussNewtonMinimizerResult operator()(const DVector& p0, int maxIterations, Real updateLengthTolerance, Real errorDifferenceTolerance);

    private:
        void ComputeLinearSystemInputs(const DVector& pCurrent);

    private:
        using CholeskyDecomposition = CholeskyDecomposition<Real>;

    private:
        int numPDimensions;
        int numFDimensions;
        FFunction fFunction;
        JFunction jFunction;
        JPlusFunction jPlusFunction;

        /// 迭代期间J^T(p)*J(p)和-J^T(p)*F(p)的存储。
        RVector f;
        JMatrix j;
        JtjMatrix jtj;
        JtfVector negJtf;

        CholeskyDecomposition decomposer;

        bool useJFunction;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_GAUSS_NEWTON_MINIMIZER_H
