///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 11:36)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_H

#include "Mathematics/MathematicsDll.h"

#include "Ellipse2Coefficients.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Algebra/Vector2Tools.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Ellipse2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse2<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Matrix2 = Matrix2<Real>;
        using Ellipse2Coefficients = Ellipse2Coefficients<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // 椭圆具有中心K，轴方向U[0]和U[1]（两个都是单位长度向量），
        // 和扩展e[0] 和 e[1]（两个都是均为正数）。
        // 点X = K + y[0] * U[0] + y[1] * U[1]是椭圆时，
        // 当(y[0] / e[0])^2 + (y[1] / e[1])^2 = 1。
        // 该试验椭圆内部的点使用“<=”代替“=”。
        // 椭圆的代数表示是
        //   1 = (X-K)^T * (U[0] * U[0]^T / e[0]^2 + U[1 ]* U[1]^T / e[1]^2) * (X-K)
        //     = (X-K)^T * M * (X-K)
        // 其中，上标T表示转置。观察到U[i] * U[i]^T是一个矩阵，而不是标量积。
        // 矩阵M是对称的。椭圆也由一元二次方程表示
        //   0 = a0 + a1 * x[0] + a2 * x[1] + a3 * x[0]^2 + a4 * x[0]*x[1] + a5 * x[1]^2
        //     = a0 + [a1 a2] * X + X^T * [a3   a4 / 2] * X
        //                                [a4 / 2 a5  ]
        //     = C + B^T * X + X^T * A * X
        // 其中X = (x[0],x[1])。这个等式可以被分解到(X - K)^T * M * (X - K) = 1，
        // 其中K = -A^{-1} * B / 2, M = A / (B^T * A^{-1} * B / 4 - C)。
        // 为椭圆形时，M必须具有所有特征值为正。

        Ellipse2(const Vector2& center,
                 const Vector2& axis0,
                 const Vector2& axis1,
                 const Real extent0,
                 const Real extent1,
                 const Real epsilon = Math::GetZeroTolerance()) noexcept;

        explicit Ellipse2(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetCenter() const noexcept;
        NODISCARD Vector2 GetAxis0() const noexcept;
        NODISCARD Vector2 GetAxis1() const noexcept;
        NODISCARD Real GetExtent0() const noexcept;
        NODISCARD Real GetExtent1() const noexcept;

        // 计算 M = sum_{i=0}^1 U[i]*U[i]^T/e[i]^2.
        NODISCARD Matrix2 GetMatrix() const;

        // 计算 M^{-1} = sum_{i=0}^1 U[i]*U[i]^T*e[i]^2.
        NODISCARD Matrix2 GetMatrixInverse() const;

        // 构建二次方程式，表示椭圆的系数。
        NODISCARD Ellipse2Coefficients ToCoefficients() const;

        // 构建m_Center，m_Axis和m_Extent从二次方程。
        // 如果输入系数不能表示一个椭圆，则抛出异常。
        void FromCoefficients(const Ellipse2Coefficients& coefficients, const Real newEpsilon = Math::GetZeroTolerance());

        // 计算的二次函数 Q(X) = (X-K)^T * M * (X-K) - 1.
        NODISCARD Real Evaluate(const Vector2& point) const;

        // 测试输入点是否在椭圆形内部或边上。
        // 该点被包含当Q(X) <= 0，其中Q(X)函数Evaluate()。
        NODISCARD bool Contains(const Vector2& point) const;

        NODISCARD Ellipse2 GetMove(Real t, const Vector2& velocity) const;

    private:
        static constexpr auto axisSize = 2;
        using AxisType = std::array<Vector2, axisSize>;
        using ExtentType = std::array<Real, axisSize>;

    private:
        Vector2 center;
        AxisType axis;
        ExtentType extent;
        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Ellipse2<Real>& lhs, const Ellipse2<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ellipse2<Real>& line);

    using Ellipse2F = Ellipse2<float>;
    using Ellipse2D = Ellipse2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_H
