/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/15 15:12)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_H

#include "Mathematics/MathematicsDll.h"

#include "CholeskyDecomposition.h"
#include "LevenbergMarquardtMinimizerResult.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

/// 关于最小化问题的公式以及Levenberg-Marquardt与高斯-牛顿的关系，
/// 请参见GaussNewtonMinimizer.h。
namespace Mathematics
{
    template <typename T>
    class LevenbergMarquardtMinimizer
    {
    public:
        using ClassType = LevenbergMarquardtMinimizer<T>;

        using Math = Math<T>;
        using LevenbergMarquardtMinimizerResult = LevenbergMarquardtMinimizerResult<T>;

        /// 域向量、范围向量、函数F和雅可比J的方便类型。
        using DVector = VariableLengthVector<T>;  // numPDimensions
        using RVector = VariableLengthVector<T>;  // numFDImensions
        using JMatrix = VariableMatrix<T>;  // numFDimensions-by-numPDimensions
        using JtjMatrix = VariableMatrix<T>;  // numPDimensions-by-numPDimensions
        using JtfVector = VariableLengthVector<T>;  // numPDimensions
        using FFunction = std::function<void(DVector const&, RVector&)>;
        using JFunction = std::function<void(DVector const&, JMatrix&)>;
        using JPlusFunction = std::function<void(DVector const&, JtjMatrix&, JtfVector&)>;

    public:
        /// 创建直接计算F(p)和J(p) 的最小化器。
        LevenbergMarquardtMinimizer(int numPDimensions,
                                    int numFDimensions,
                                    FFunction inFFunction,
                                    JFunction inJFunction);

        /// 创建计算J^T(p)*J(p)和-J(p)*F(p)）的最小值。
        LevenbergMarquardtMinimizer(int numPDimensions,
                                    int numFDimensions,
                                    FFunction inFFunction,
                                    JPlusFunction inJPlusFunction);

        ~LevenbergMarquardtMinimizer() noexcept = default;
        LevenbergMarquardtMinimizer(const LevenbergMarquardtMinimizer& rhs) = delete;
        LevenbergMarquardtMinimizer& operator=(const LevenbergMarquardtMinimizer& rhs) = delete;
        LevenbergMarquardtMinimizer(LevenbergMarquardtMinimizer&& rhs) noexcept = delete;
        LevenbergMarquardtMinimizer& operator=(LevenbergMarquardtMinimizer&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetNumPDimensions() const noexcept;
        NODISCARD int GetNumFDimensions() const noexcept;

        /// lambda正，乘数为正，p参数的初始猜测为p0。
        /// 典型的选择是lambda=0.001multiplier=10。
        /// 更详细地解释lambda，Multiview Geometry提到lambda = 0.001*average(diagonal(JTJ))，
        /// 但让我们只在平均值前面暴露因子。

        NODISCARD LevenbergMarquardtMinimizerResult operator()(const DVector& p0,
                                                               int maxIterations,
                                                               T updateLengthTolerance,
                                                               T errorDifferenceTolerance,
                                                               T lambdaFactor,
                                                               T lambdaAdjust,
                                                               int maxAdjustments);

    private:
        void ComputeLinearSystemInputs(const DVector& pCurrent, T lambda);

        /// 当线性系统无法求解时（在这种情况下，result.converged为false），
        /// 或者当误差减少到调用方指定的公差范围内时（在本情况下，result.converged为true），
        /// 返回的 'first'为true。
        /// 当 'first'值为true时，'second'值在错误减少时为true，否则为false。
        NODISCARD std::pair<bool, bool> DoIteration(const DVector& pCurrent,
                                                    T lambdaFactor,
                                                    T updateLengthTolerance,
                                                    T errorDifferenceTolerance,
                                                    DVector& pNext,
                                                    LevenbergMarquardtMinimizerResult& result);

    private:
        using CholeskyDecomposition = CholeskyDecomposition<T>;

    private:
        int numPDimensions;
        int numFDimensions;
        FFunction fFunction;
        JFunction jFunction;
        JPlusFunction jPlusFunction;

        /// 迭代期间J^T(p)*J(p) and -J^T(p)*F(p)的存储。
        RVector f;
        JMatrix j;
        JtjMatrix jtj;
        JtfVector negJtf;

        CholeskyDecomposition decomposer;

        bool useJFunction;
    };
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LEVENBERG_MARQUARDT_MINIMIZER_H
