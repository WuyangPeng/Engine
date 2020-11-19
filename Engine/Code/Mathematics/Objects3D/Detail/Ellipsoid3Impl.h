///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 13:36)
///
#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_IMPL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Ellipsoid3Coefficients.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Ellipsoid3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipsoid3Impl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using Matrix3 = Matrix3<Real>;
        using Ellipsoid3Coefficients = Ellipsoid3Coefficients<Real>;
        using Vector3DTools = Vector3DTools<Real>;

    public:
        Ellipsoid3Impl(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                       const Real extent0, const Real extent1, const Real extent2, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        explicit Ellipsoid3Impl(const Ellipsoid3Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Vector3D GetAxis0() const noexcept;
        [[nodiscard]] const Vector3D GetAxis1() const noexcept;
        [[nodiscard]] const Vector3D GetAxis2() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetExtent2() const noexcept;
        [[nodiscard]] Real GetEpsilon() const noexcept;

        // 计算 M = sum_{i=0}^2 U[i] * U[i]^T / e[i]^2.
        [[nodiscard]] const Matrix3 GetMatrix() const;

        // 计算 M^{-1} = sum_{i=0}^2 U[i] * U[i]^T * e[i]^2.
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

    private:
        static constexpr auto sm_AxisSize = 3;
        using AxisType = std::array<Vector3D, sm_AxisSize>;
        using ExtentType = std::array<Real, sm_AxisSize>;

    private:
        Vector3D m_Center;
        AxisType m_Axis;
        ExtentType m_Extent;

        Real m_Epsilon;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_IMPL_H
