///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/08 21:52)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector2D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceLine2Line2Tool final
    {
    public:
        using ClassType = DistanceLine2Line2Tool<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        DistanceLine2Line2Tool(const Vector2D& lhsOrigin, const Vector2D& lhsDirection, const Vector2D& rhsOrigin, const Vector2D& rhsDirection);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetDet() const noexcept;
        [[nodiscard]] Real GetLhsT() const noexcept;
        [[nodiscard]] Real GetRhsT() const noexcept;
        [[nodiscard]] Real GetLhsT(Real extent) const noexcept;
        [[nodiscard]] Real GetRhsT(Real extent) const noexcept;
        [[nodiscard]] Real GetOriginDifferenceDotLhsDirection() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceDotRhsDirection() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceSquaredLength() const noexcept;
        [[nodiscard]] Real GetDirectionDot() const noexcept; 
        [[nodiscard]] Real GetSquaredDistanceWithParallel() const noexcept;
        [[nodiscard]] Real GetSquaredDistanceWithLhs() const noexcept;
        [[nodiscard]] Real GetSquaredDistanceWithRhs() const noexcept;
        [[nodiscard]] Real GetOriginDifferenceDotDirectionAverage() const noexcept;

    private:
        Vector2D m_OriginDifference;
        Real m_DirectionDot;
        Real m_OriginDifferenceDotLhsDirection;
        Real m_OriginDifferenceDotRhsDirection;
        Real m_OriginDifferenceSquaredLength;
        Real m_Det;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE2_LINE2_TOOL_H
