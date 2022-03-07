///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/02 22:26)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AxesAlignBoundingBox3<Real>;
        using Vector3 = Vector3<Real>;
        using Math = Math<Real>;
        using PointIndex = typename Vector3::PointIndex;

    public:
        constexpr AxesAlignBoundingBox3() noexcept
            : minPoint{ Math::maxReal, Math::maxReal, Math::maxReal }, maxPoint{ Math::minReal, Math::minReal, Math::minReal }
        {
        }

        AxesAlignBoundingBox3(const Vector3& minPoint, const Vector3& maxPoint) noexcept;

        // 调用者必须确保xMin <= xMax 、 yMin <= yMax和zMin <= zMax。
        AxesAlignBoundingBox3(Real xMin, Real xMax, Real yMin, Real yMax, Real zMin, Real zMax) noexcept;

        template <typename RhsType>
        AxesAlignBoundingBox3(const AxesAlignBoundingBox3<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsBoxValid() const noexcept;

        NODISCARD Vector3 GetMinPoint() const noexcept;
        NODISCARD Vector3 GetMaxPoint() const noexcept;
        NODISCARD Real GetMinPoint(int index) const;
        NODISCARD Real GetMaxPoint(int index) const;
        NODISCARD Real GetMinPoint(PointIndex index) const;
        NODISCARD Real GetMaxPoint(PointIndex index) const;

        // 计算盒子的中心点和盒子中心到盒子边缘（半径）的长度。
        NODISCARD Vector3 GetCenter() const;
        NODISCARD Real GetExtentX() const noexcept;
        NODISCARD Real GetExtentY() const noexcept;
        NODISCARD Real GetExtentZ() const noexcept;

    private:
        Vector3 minPoint;
        Vector3 maxPoint;
    };

    // 重叠的测试是在严格意义上。
    // 如果两个盒子沿公共边刚好接触，盒子被报告为重叠。
    template <typename Real>
    NODISCARD bool HasXOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    template <typename Real>
    NODISCARD bool HasYOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    template <typename Real>
    NODISCARD bool HasZOverlap(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    template <typename Real>
    NODISCARD bool IsIntersection(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    // 如果有重叠。在这种情况下，交点被返回。
    // 如果没有重叠，则返回的AxesAlignBoundingBox2是无效的。
    template <typename Real>
    NODISCARD AxesAlignBoundingBox3<Real> FindIntersection(const AxesAlignBoundingBox3<Real>& lhs, const AxesAlignBoundingBox3<Real>& rhs);

    using AxesAlignBoundingBox3F = AxesAlignBoundingBox3<float>;
    using AxesAlignBoundingBox3D = AxesAlignBoundingBox3<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_H