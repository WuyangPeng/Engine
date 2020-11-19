///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 11:40)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector2DTools.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Ellipse2Coefficients.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Ellipse2Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse2Impl<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Matrix2 = Matrix2<Real>;
        using Vector2DTools = Vector2DTools<Real>;
        using Ellipse2Coefficients = Ellipse2Coefficients<Real>;

    public:
        Ellipse2Impl(const Vector2D& center, const Vector2D& axis0, const Vector2D& axis1,
                     const Real extent0, const Real extent1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        explicit Ellipse2Impl(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] const Vector2D GetAxis0() const noexcept;
        [[nodiscard]] const Vector2D GetAxis1() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetEpsilon() const noexcept;

        // 计算 M = sum_{i=0}^1 U[i]*U[i]^T/e[i]^2.
        [[nodiscard]] const Matrix2 GetMatrix() const;

        // 计算 M^{-1} = sum_{i=0}^1 U[i]*U[i]^T*e[i]^2.
        [[nodiscard]] const Matrix2 GetMatrixInverse() const;

        // 构建二次方程式，表示椭圆的系数。
        [[nodiscard]] const Ellipse2Coefficients ToCoefficients() const;

        // 构建m_Center，m_Axis和m_Extent从二次方程。
        // 如果输入系数不能表示一个椭圆，则抛出异常。
        [[nodiscard]] void FromCoefficients(const Ellipse2Coefficients& coefficients, const Real epsilon = Math::GetZeroTolerance());

        // 计算的二次函数 Q(X) = (X-K)^T * M * (X-K) - 1.
        [[nodiscard]] Real Evaluate(const Vector2D& point) const;

        // 测试输入点是否在椭圆形内部或边上。
        // 该点被包含当Q(X) <= 0，其中Q(X)函数Evaluate()。
        [[nodiscard]] bool Contains(const Vector2D& point) const;

    private:
        static constexpr auto sm_AxisSize = 2;
        using AxisType = std::array<Vector2D, sm_AxisSize>;
        using ExtentType = std::array<Real, sm_AxisSize>;

    private:
        Vector2D m_Center;
        AxisType m_Axis;
        ExtentType m_Extent;
        Real m_Epsilon;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_IMPL_H
