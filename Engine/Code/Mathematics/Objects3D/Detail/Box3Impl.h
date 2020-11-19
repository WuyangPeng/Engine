///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 13:43)

#ifndef MATHEMATICS_OBJECTS3D_BOX3_IMPL_H
#define MATHEMATICS_OBJECTS3D_BOX3_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Box3Impl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Box3Impl<Real>;
        using Math = Math<Real>;
        using Vector3D = Vector3D<Real>;
        using VerticesType = std::vector<Vector3D>;

    public:
        // 一个盒子有中心点C，轴方向U[0]、U[1]和U[2]（垂直和单位长度的向量），
        // 和范围e[0]、e[1]和e[2]（非负数）。
        // A point X = C + y[0] * U[0] + y[1] * U[1] + y[2] * U[2]是在内部或在盒子上，
        // 每当|y[i]| <= e[i]对于所有的i
        Box3Impl() noexcept;
        Box3Impl(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                 const Real extent0, const Real extent1, const Real extent2, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        // 返回的顶点数为8
        [[nodiscard]] const VerticesType ComputeVertices() const;
        [[nodiscard]] const Vector3D GetCenter() const noexcept;

        [[nodiscard]] const Vector3D GetAxis0() const noexcept;
        [[nodiscard]] const Vector3D GetAxis1() const noexcept;
        [[nodiscard]] const Vector3D GetAxis2() const noexcept;
        [[nodiscard]] const Vector3D GetAxis(int index) const;

        [[nodiscard]] Real GetExtent0() const noexcept;
        [[nodiscard]] Real GetExtent1() const noexcept;
        [[nodiscard]] Real GetExtent2() const noexcept;
        [[nodiscard]] Real GetExtent(int index) const;

        [[nodiscard]] Real GetEpsilon() const noexcept;

        void Set(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, const Vector3D& axis2,
                 const Real extent0, const Real extent1, const Real extent2) noexcept;

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

#endif  // MATHEMATICS_OBJECTS3D_BOX3_IMPL_H
