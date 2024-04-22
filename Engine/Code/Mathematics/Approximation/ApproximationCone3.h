/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/02 10:04)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector3.h"
#include "Mathematics/NumericalAnalysis/GaussNewtonMinimizer.h"
#include "Mathematics/NumericalAnalysis/LevenbergMarquardtMinimizerResult.h"

/// 圆锥体顶点为V，单位长度轴方向为U，圆锥体角度为 (0,pi/2)中的A。
/// 锥由以下点X代数定义：
///     Dot(U,X-V)/Length(X-V) = cos(A)
/// 这可以写成一个二次方程
///     (V-X)^T * (cos(A)^2 - U * U^T) * (V-X) = 0
/// 具有隐含约束Dot(U, X-V) > 0（X在“正”圆锥体上）。
/// 定义W = U/cos(A)，因此Length(W) > 1，并且
///     F(X;V,W) = (V-X)^T * (I - W * W^T) * (V-X) = 0
/// 点{X[i]}_{i=0}^{n-1}的非线性最小二乘拟合计算V和W以最小化误差函数
///     E(V,W) = sum_{i=0}^{n-1} F(X[i];V,W)^2
/// 当你的锥点真的几乎是一个锥时，我建议使用高斯-牛顿极小值；
/// 否则，请尝试Levenberg-Marquardt最小化器。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3
    {
    public:
        using ClassType = ApproximationCone3<Real>;

        using Vector3 = Algebra::Vector3<Real>;
        using Vector3Container = std::vector<Vector3>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using Math = Math<Real>;
        using GaussNewtonMinimizerResult = GaussNewtonMinimizerResult<Real>;
        using LevenbergMarquardtMinimizerResult = LevenbergMarquardtMinimizerResult<Real>;

    public:
        ApproximationCone3() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 如果要指定coneVertex、coneAxis和coneAngle是最小值的初始猜测，
        /// 请将参数useConeInputAsInitialGuess设置为“true”。
        /// 如果您希望函数计算初始猜测，请将该参数设置为“false”。
        /// 高斯-牛顿最小化器用于使用非线性最小二乘法拟合圆锥体。
        /// 拟合的圆锥体以coneVertex、coneAxis和coneAngle形式返回。
        /// 有关最小二乘算法及其所需参数的描述，请参见GaussNewtonMinimizer.h。
        NODISCARD GaussNewtonMinimizerResult operator()(const Vector3Container& aPoints,
                                                        int maxIterations,
                                                        Real updateLengthTolerance,
                                                        Real errorDifferenceTolerance,
                                                        bool useConeInputAsInitialGuess,
                                                        Vector3& coneVertex,
                                                        Vector3& coneAxis,
                                                        Real& coneAngle);

        /// 参数coneVertex、coneAxis和coneAngle是输入/输出变量。
        /// 调用方必须提供这些的初始猜测。函数估计圆锥体参数并返回这些参数。
        /// 有关最小二乘算法及其所需参数的描述，请参见GaussNewtonMinimizer.h。
        /// （文件LevenbergMarquardtMinimizer.h会将您引导到高斯-牛顿文件以读取有关参数的信息。
        NODISCARD LevenbergMarquardtMinimizerResult operator()(const Vector3Container& aPoints,
                                                               int maxIterations,
                                                               Real updateLengthTolerance,
                                                               Real errorDifferenceTolerance,
                                                               Real lambdaFactor,
                                                               Real lambdaAdjust,
                                                               int maxAdjustments,
                                                               bool useConeInputAsInitialGuess,
                                                               Vector3& coneVertex,
                                                               Vector3& coneAxis,
                                                               Real& coneAngle);

    private:
        void ComputeInitialCone(Vector3& coneVertex, Vector3& coneAxis, Real& coneAngle);

    private:
        Vector3Container points;
        std::function<void(const VariableLengthVector&, VariableLengthVector&)> fFunction;
        std::function<void(const VariableLengthVector&, VariableMatrix&)> jFunction;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_H
