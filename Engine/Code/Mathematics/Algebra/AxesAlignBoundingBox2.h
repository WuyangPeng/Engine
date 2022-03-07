///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/02 22:12)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H

#include "Mathematics/MathematicsDll.h"

#include "Vector2.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AxesAlignBoundingBox2<Real>;
        using Vector2 = Vector2<Real>;
        using Math = Math<Real>;
        using PointIndex = typename Vector2::PointIndex;

    public:
        constexpr AxesAlignBoundingBox2() noexcept
            : minPoint{ Math::maxReal, Math::maxReal }, maxPoint{ Math::minReal, Math::minReal }
        {
        }

        AxesAlignBoundingBox2(const Vector2& minPoint, const Vector2& maxPoint) noexcept;

        template <typename RhsType>
        AxesAlignBoundingBox2(const AxesAlignBoundingBox2<RhsType>& aabb);

        // 调用者必须确保xMin <= xMax 和 yMin <= yMax。
        AxesAlignBoundingBox2(Real xMin, Real xMax, Real yMin, Real yMax) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector2 GetMinPoint() const noexcept;
        NODISCARD Vector2 GetMaxPoint() const noexcept;

        NODISCARD Real GetMinPoint(int index) const;
        NODISCARD Real GetMaxPoint(int index) const;
        NODISCARD Real GetMinPoint(PointIndex index) const;
        NODISCARD Real GetMaxPoint(PointIndex index) const;

        // 计算盒子的中心点和盒子中心到盒子边缘（半径）的长度。
        NODISCARD Vector2 GetCenter() const;
        NODISCARD Real GetExtentX() const noexcept;
        NODISCARD Real GetExtentY() const noexcept;

    private:
        Vector2 minPoint;
        Vector2 maxPoint;
    };

    // 重叠的测试是在严格意义上。
    // 如果两个盒子沿公共边刚好接触，盒子被报告为重叠。
    template <typename Real>
    NODISCARD bool HasXOverlap(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    template <typename Real>
    NODISCARD bool HasYOverlap(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    template <typename Real>
    NODISCARD bool IsIntersection(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    // 如果有重叠。在这种情况下，交点被返回。
    // 如果没有重叠，则返回的AxesAlignBoundingBox2是无效的。
    template <typename Real>
    NODISCARD AxesAlignBoundingBox2<Real> FindIntersection(const AxesAlignBoundingBox2<Real>& lhs, const AxesAlignBoundingBox2<Real>& rhs);

    using AxesAlignBoundingBox2F = AxesAlignBoundingBox2<float>;
    using AxesAlignBoundingBox2D = AxesAlignBoundingBox2<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_H