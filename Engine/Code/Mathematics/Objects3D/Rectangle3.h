///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 17:02)

#ifndef MATHEMATICS_OBJECTS3D_RECTANGLE3_H
#define MATHEMATICS_OBJECTS3D_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Rectangle3Impl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Rectangle3Impl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Rectangle3Impl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE std::shared_ptr<Rectangle3Impl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Rectangle3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Rectangle3Impl = Rectangle3Impl<Real>;
        PERFORMANCE_UNSHARE_CLASSES_TYPE_DECLARE(Rectangle3);

        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // 点Real(s,t) = C + s0 * U0 + s1 * U1，其中C是矩形的中心，U0和U1是单位长度的垂直轴。
        // 参数s0和s1是由约束|s0| <= e0 和|s1| <= e1，
        // 其中e0 > 0和e1 > 0称为矩形的范围。
        Rectangle3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, Real extent0, Real extent1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetCenter() const noexcept;
        [[nodiscard]] const Vector3D GetAxis0() const noexcept;
        [[nodiscard]] const Vector3D GetAxis1() const noexcept;
        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;

        [[nodiscard]] const Vector3D GetAxis(int index) const;
        [[nodiscard]] Real GetExtent(int index) const;

        // 返回矩形的四个顶点
        [[nodiscard]] const VerticesType ComputeVertices() const;

        // 获取矩形角。
        [[nodiscard]] const Vector3D GetPPCorner() const;  // C + e0 * A0 + e1 * A1
        [[nodiscard]] const Vector3D GetPMCorner() const;  // C + e0 * A0 - e1 * A1
        [[nodiscard]] const Vector3D GetMPCorner() const;  // C - e0 * A0 + e1 * A1
        [[nodiscard]] const Vector3D GetMMCorner() const;  // C - e0 * A0 - e1 * A1

        [[nodiscard]] const Rectangle3 GetMove(Real t, const Vector3D& velocity) const;

    private:
        IMPL_TYPE_DECLARE(Rectangle3);
    };

    using FloatRectangle3 = Rectangle3<float>;
    using DoubleRectangle3 = Rectangle3<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_RECTANGLE3_H
