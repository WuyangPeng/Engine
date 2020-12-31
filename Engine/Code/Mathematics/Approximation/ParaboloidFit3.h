///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/03 16:54)

#ifndef MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_H
#define MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    // 一组点的最小二乘拟合抛物面。
    // 抛物面的形式z = c0*x^2+c1*x*y+c2*y^2+c3*x+c4*y+c5。
    // 一个成功的拟合是“m_IsFitSuccess”为true。
    // 给定一组样品(x_i,y_i,z_i) 为0 <= i < N,，并且假定真值位于一个抛物面
    //     z = p0*x*x + p1*x*y + p2*y*y + p3*x + p4*y + p5  = Dot(P,Q(x,y))
    // 这里 P = (p0,p1,p2,p3,p4,p5) 和 Q(x,y) = (x*x,x*y,y*y,x,y,1),
    // 选择P以最小化平方误差的和
    //     E(P) = sum_{i=0}^{N-1} [Dot(P,Q_i)-z_i]^2
    // 这里 Q_i = Q(x_i,y_i).
    // 最小值当E的渐变是零向量时发生，
    //     grad(E) = 2 sum_{i=0}^{N-1} [Dot(P,Q_i)-z_i] Q_i = 0
    // 有些代数转换这6个方程的6个未知数系统
    //     [(sum_{i=0}^{N-1} Q_i Q_i^t] P = sum_{i=0}^{N-1} z_i Q_i
    // 该产品Q_i是6x1矩阵Q_i与1x6阵Q_i^t，结果是一个6×6矩阵的乘积。
    // 定义6x6对称矩阵A = sum_{i=0}^{N-1} Q_i Q_i^t和6x1向量B = sum_{i=0}^{N-1} z_i Q_i
    // P的选择是解线性系统A*P = B的方程。
    // A和B的条目显示在变量相应的产品总和。 例如，
    // s(x^3 y) = sum_{i=0}^{N-1} x_i^3 y_i.
    //
    // +-                                                     -++  +   +-      -+
    // | s(x^4) s(x^3 y)   s(x^2 y^2) s(x^3)   s(x^2 y) s(x^2) ||p0|   |s(z x^2)|
    // |        s(x^2 y^2) s(x y^3)   s(x^2 y) s(x y^2) s(x y) ||p1|   |s(z x y)|
    // |                   s(y^4)     s(x y^2) s(y^3)   s(y^2) ||p2| = |s(z y^2)|
    // |                              s(x^2)   s(x y)   s(x)   ||p3|   |s(z x)  |
    // |                                       s(y^2)   s(y)   ||p4|   |s(z y)  |
    // |                                                s(1)   ||p5|   |s(z)    |
    // +-                                                     -++  +   +-      -+
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE ParaboloidFit3 final
    {
    public:
        using ClassType = ParaboloidFit3<Real>;
        using Vector3D = Vector3D<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using Points = std::vector<Vector3D>;

    public:
        explicit ParaboloidFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] VariableLengthVector GetCoeff() const;
        [[nodiscard]] bool GetIsFitSuccess() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static int sm_VariableMatrixSize = 6;

    private:
        VariableLengthVector m_Coeff;
        bool m_IsFitSuccess;
    };

    using FloatParaboloidFit3 = ParaboloidFit3<float>;
    using DoubleParaboloidFit3 = ParaboloidFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_PARABOLOID_FIT3_H
