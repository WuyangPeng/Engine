///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 16:40)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceLine3Line3Tool final
    {
    public:
        using ClassType = DistanceLine3Line3Tool<Real>;
        using Vector3D = Vector3D<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = Math<Real>;

    public:
        DistanceLine3Line3Tool(const Vector3D& lhsOrigin, const Vector3D& lhsDirection, const Vector3D& rhsOrigin, const Vector3D& rhsDirection);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetDet() const noexcept;
        [[nodiscard]] Real GetLhsT() const noexcept;
        [[nodiscard]] Real GetRhsT() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceDotLhsDirection() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceDotRhsDirection() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceSquaredLength() const noexcept;
        [[nodiscard]] Real GetDirectionDot() const noexcept;

        [[nodiscard]] Real GetLhsT(Real extent) const noexcept;
        [[nodiscard]] Real GetRhsT(Real extent) const noexcept;
        [[nodiscard]] Real GetSquaredDistanceWithParallel() const noexcept;
        [[nodiscard]] Real GetSquaredDistanceWithLhs() const noexcept;
        [[nodiscard]] Real GetSquaredDistanceWithRhs() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceDotDirectionAverage() const noexcept;

    private:
        Vector3D m_OriginDifference;
        Real m_DirectionDot;
        Real m_OriginDifferenceDotLhsDirection;
        Real m_OriginDifferenceDotRhsDirection;
        Real m_OriginDifferenceSquaredLength;
        Real m_Det;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
