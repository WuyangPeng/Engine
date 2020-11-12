///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:38)

// 轴对齐包围盒3D类的声明
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H

#include "Mathematics/MathematicsDll.h"

#include "Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxesAlignBoundingBox3D final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = AxesAlignBoundingBox3D<Real>;
        using Vector3D = Vector3D<Real>;
        using Math = Math<Real>;

    public:
        constexpr AxesAlignBoundingBox3D() noexcept
            : m_MinPoint{}, m_MaxPoint{}
        {
        }

        explicit AxesAlignBoundingBox3D(const Vector3D& minPoint, const Vector3D& maxPoint);

        // 调用者必须确保xMin <= xMax 、 yMin <= yMax和zMin <= zMax。
        AxesAlignBoundingBox3D(Real xMin, Real xMax, Real yMin, Real yMax, Real zMin, Real zMax);

        template <typename RhsType>
        AxesAlignBoundingBox3D(const AxesAlignBoundingBox3D<RhsType>& aabb);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetMinPoint() const noexcept;
        [[nodiscard]] const Vector3D GetMaxPoint() const noexcept;

        // 计算盒子的中心点和盒子中心到盒子边缘（半径）的长度。
        [[nodiscard]] const Vector3D GetCenter() const;
        [[nodiscard]] Real GetExtentX() const noexcept;
        [[nodiscard]] Real GetExtentY() const noexcept;
        [[nodiscard]] Real GetExtentZ() const noexcept;

    private:
        void Recalculate();

    private:
        Vector3D m_MinPoint;
        Vector3D m_MaxPoint;
    };

    // 重叠的测试是在严格意义上。
    // 如果两个盒子沿公共边刚好接触，盒子被报告为重叠。
    template <typename Real>
    [[nodiscard]] bool HasXOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool HasYOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool HasZOverlap(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    template <typename Real>
    [[nodiscard]] bool IsIntersection(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    // 如果有重叠。在这种情况下，交点被返回。
    // 如果没有重叠，则抛出异常
    template <typename Real>
    [[nodiscard]] const AxesAlignBoundingBox3D<Real> FindIntersection(const AxesAlignBoundingBox3D<Real>& lhs, const AxesAlignBoundingBox3D<Real>& rhs);

    using FloatAxesAlignBoundingBox3D = AxesAlignBoundingBox3D<float>;
    using DoubleAxesAlignBoundingBox3D = AxesAlignBoundingBox3D<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_H