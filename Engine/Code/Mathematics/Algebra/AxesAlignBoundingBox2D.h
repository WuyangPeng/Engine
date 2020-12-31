///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 9:57)

// 轴对齐包围盒2D类的声明
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H

#include "Mathematics/MathematicsDll.h"

#include "Vector2D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2D final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AxesAlignBoundingBox2D<Real>;
        using Vector2D = Vector2D<Real>;
        using Math = Math<Real>;

    public:
        constexpr AxesAlignBoundingBox2D() noexcept
            : m_MinPoint{}, m_MaxPoint{}
        {
        }

        AxesAlignBoundingBox2D(const Vector2D& minPoint, const Vector2D& maxPoint);

        template <typename RhsType>
        AxesAlignBoundingBox2D(const AxesAlignBoundingBox2D<RhsType>& aabb);

        // 调用者必须确保xMin <= xMax 和 yMin <= yMax。
        AxesAlignBoundingBox2D(Real xMin, Real xMax, Real yMin, Real yMax);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetMinPoint() const noexcept;
        [[nodiscard]] const Vector2D GetMaxPoint() const noexcept;

        // 计算盒子的中心点和盒子中心到盒子边缘（半径）的长度。
        [[nodiscard]] const Vector2D GetCenter() const noexcept;
        [[nodiscard]] Real GetExtentX() const noexcept;
        [[nodiscard]] Real GetExtentY() const noexcept;

    private:
        void Recalculate();

    private:
        Vector2D m_MinPoint;
        Vector2D m_MaxPoint;
    };

    // 重叠的测试是在严格意义上。
    // 如果两个盒子沿公共边刚好接触，盒子被报告为重叠。
    template <typename Real>
    [[nodiscard]] bool HasXOverlap(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool HasYOverlap(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool IsIntersection(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs);

    // 如果有重叠。在这种情况下，交点被返回。
    // 如果没有重叠，则抛出异常
    template <typename Real>
    [[nodiscard]] const AxesAlignBoundingBox2D<Real> FindIntersection(const AxesAlignBoundingBox2D<Real>& lhs, const AxesAlignBoundingBox2D<Real>& rhs);

    using FloatAxesAlignBoundingBox2D = AxesAlignBoundingBox2D<float>;
    using DoubleAxesAlignBoundingBox2D = AxesAlignBoundingBox2D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_H