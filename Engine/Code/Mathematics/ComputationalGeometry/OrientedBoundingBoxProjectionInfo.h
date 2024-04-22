/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/08 14:45)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_PROJECTION_INFO_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_PROJECTION_INFO_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class OrientedBoundingBoxProjectionInfo
    {
    public:
        using ClassType = OrientedBoundingBoxProjectionInfo<Real>;

    public:
        OrientedBoundingBoxProjectionInfo() noexcept;
        OrientedBoundingBoxProjectionInfo(int pointIndex, Real projection) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetPointIndex() const noexcept;
        NODISCARD Real GetProjection() const noexcept;

        NODISCARD void SetPointIndex(int aPointIndex) noexcept;
        NODISCARD void SetProjection(Real aProjection) noexcept;

    private:
        int pointIndex;
        Real projection;
    };

    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const OrientedBoundingBoxProjectionInfo<Real>& lhs, const OrientedBoundingBoxProjectionInfo<Real>& rhs) noexcept;
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_PROJECTION_INFO_H
