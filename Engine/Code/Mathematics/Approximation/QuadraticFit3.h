///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:28)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    // 二次拟合为
    //   0 = C[0] + C[1]*X + C[2]*Y + C[3]*Z + C[4]*X^2 + C[5]*Y^2 +
    //       C[6]*Z^2 + C[7]*X*Y + C[8]*X*Z + C[9]*Y*Z
    // 符合Length(C) = 1。
    // 最小化E(C) = C^t M C与 Length(C) = 1 和
    // M = (sum_i V_i)(sum_i V_i)^t 其中
    // V = (1, X, Y, Z, X^2, Y^2, Z^2, X*Y, X*Z, Y*Z)

    // 最小值为M的最小特征值和C是一个对应的单位长度的特征向量。

    // 输入:
    //   n = 要拟合点的数量。
    //   p[0..n-1] = 要拟合点的数组。
    //
    // 输出:
    //   coeff = 二次拟合系数（特征向量）。
    //   eigenValue = 是非负值，并且测量的拟合的规范形式
    //  （最小特征值;0 = 精确拟合，否则为正数）

    // 规范形式。  二次方程可以被分解为
    // P^T A P + B^T P + K = 0 这里 P = (X,Y,Z), K = C[0], B = (C[1],C[2],C[3]),
    // 以及A是3×3对称矩阵 A00 = C[4], A11 = C[5], A22 = C[6],
    // A01 = C[7]/2, A02 = C[8]/2, 和 A12 = C[9]/2.
    // 矩阵 A = Real^T D Real其中Real是正交矩阵和D是对角矩阵（使用特征分解）。
    // 定义 V = Real P = (v0,v1,v2), E = Real B = (e0,e1,e2), D = diag(d0,d1,d2), 和 f = K
    // 以获得
    //   d0 v0^2 + d1 v1^2 + d2 v^2 + e0 v0 + e1 v1 + e2 v2 + f = 0
    // 特征值依赖于d_i的符号。

    template <typename Real>
    class QuadraticFit3 final
    {
    public:
        using ClassType = QuadraticFit3<Real>;

        using Vector3Type = Vector3<Real>;
        using VariableLengthVectorType = VariableLengthVector<Real>;
        using Points = std::vector<Vector3Type>;

    public:
        explicit QuadraticFit3(const Points& points);

        CLASS_INVARIANT_DECLARE;

        NODISCARD VariableLengthVectorType GetCoeff() const;
        NODISCARD Real GetEigenValue() const noexcept;

    private:
        void Calculate(const Points& points);

    private:
        constexpr static auto eigenSystemSize = 10;

    private:
        VariableLengthVectorType coeff;
        Real eigenValue;
    };

    using QuadraticFit3F = QuadraticFit3<float>;
    using QuadraticFit3D = QuadraticFit3<double>;
}

#endif  // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT3_H
