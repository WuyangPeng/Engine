///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 14:25)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Ellipsoid3Coefficients.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class Ellipsoid3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Ellipsoid3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Ellipsoid3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Ellipsoid3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipsoid3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Ellipsoid3Impl = Ellipsoid3Impl<Real>;
        DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(Ellipsoid3);

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Matrix3 = Matrix3<Real>;
        using Ellipsoid3Coefficients = Ellipsoid3Coefficients<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        // 椭圆体有中心K，轴方向U[0], U[1], 和 U[2]（所有单位长度向量），
        // 和扩展e[0], e[1], 和 e[2]（全是正数）。
        // 点X = K + y[0] * U[0] + y[1] * U[1] + y[2] * U[2]是在椭圆体上，
        // 测试为椭球体内部的点用“<=”，代替“=”在先前的表达式中。
        // 椭球体的代数表示是
        //   1 = (X-K)^T * (U[0] * U[0]^T / e[0]^2 + U[1] * U[1]^T / e[1]^2 +
        //                  U[2] * U[2]^T / e[2]^2) * (X - K)
        //     = (X-K)^T * M * (X - K)
        // 其中，上标T表示转置。观察到U[i] * U[i]^T是一个矩阵，而不是标量积。
        // 矩阵M是对称的。椭球体也由一元二次方程表示
        //   0 = a0 + a1 * x[0] + a2 * x[1] + a3 * x[2] + a4 * x[0]^2 + a5 * x[0] * x[1] +
        //       a6 * x[0] * x[2] + a7 * x[1]^2 + a8 * x[1] * x[2] + a9 * x[2]^2
        //     = a0 + [a1 a2 a3] * X + X^T * [a4     a5 / 2 a6 / 2] * X
        //                                   [a5 / 2 a7     a8 / 2]
        //                                   [a6 / 2 a8 / 2 a9  ]
        //     = C + B^T * X + X^T * A * X
        // 其中X = (x[0],x[1],x[2])。这个等式可以被分解到(X-K)^T * M * (X - K) = 1，
        // 其中K = -A^{-1} * B / 2, M = A / (B^T * A^{-1} * B / 4 - C)。
        // 为椭圆体时，M必须具有所有特征值为正。
        Ellipsoid3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                   const Real extent0, const Real extent1, const Real extent2, const Real epsilon = Math::GetZeroTolerance());

        explicit Ellipsoid3(const Ellipsoid3Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Vector3D GetAxis0() const noexcept;
        [[nodiscard]] const Vector3D GetAxis1() const noexcept;
        [[nodiscard]] const Vector3D GetAxis2() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetExtent2() const noexcept;

        // 计算 M = sum_{i = 0}^2 U[i] * U[i]^T/e[i]^2.
        [[nodiscard]] const Matrix3 GetMatrix() const;

        // 计算 M^{-1} = sum_{i = 0}^2 U[i] * U[i]^T * e[i]^2.
        [[nodiscard]] const Matrix3 GetMatrixInverse() const;

        // 构建二次方程式，表示椭圆体的系数。
        [[nodiscard]] const Ellipsoid3Coefficients ToCoefficients() const;

        // 构建m_Center，m_Axis和m_Extent从二次方程。
        // 如果输入系数不能表示一个椭圆体，则抛出异常。
        void FromCoefficients(const Ellipsoid3Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        // 计算的二次函数 Q(X) = (X-K)^T * M * (X-K) - 1.
        [[nodiscard]] Real Evaluate(const Vector3D& point) const;

        // 测试输入点是否在椭圆体内部或边上。
        // 该点被包含当Q(X) <= 0，其中Q(X)为函数Evaluate()。
        [[nodiscard]] bool Contains(const Vector3D& point) const;

        [[nodiscard]] const Ellipsoid3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        IMPL_TYPE_DECLARE(Ellipsoid3);
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Ellipsoid3<Real>& lhs, const Ellipsoid3<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Ellipsoid3<Real>& ellipsoid);

    using FloatEllipsoid3 = Ellipsoid3<float>;
    using DoubleEllipsoid3 = Ellipsoid3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_H
