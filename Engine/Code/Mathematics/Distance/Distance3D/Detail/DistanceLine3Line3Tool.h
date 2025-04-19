///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE DistanceLine3Line3Tool final
    {
    public:
        using ClassType = DistanceLine3Line3Tool<Real>;

        using Vector3Type = Vector3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = Math<Real>;

    public:
        DistanceLine3Line3Tool(const Vector3Type& lhsOrigin, const Vector3Type& lhsDirection, const Vector3Type& rhsOrigin, const Vector3Type& rhsDirection);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetDet() const noexcept;
        NODISCARD Real GetLhsT() const noexcept;
        NODISCARD Real GetRhsT() const noexcept;
        NODISCARD Real GetOriginDifferenceDotLhsDirection() const noexcept;
        NODISCARD Real GetOriginDifferenceDotRhsDirection() const noexcept;
        NODISCARD Real GetOriginDifferenceSquaredLength() const noexcept;
        NODISCARD Real GetDirectionDot() const noexcept;

        NODISCARD Real GetLhsT(Real extent) const noexcept;
        NODISCARD Real GetRhsT(Real extent) const noexcept;
        NODISCARD Real GetSquaredDistanceWithParallel() const noexcept;
        NODISCARD Real GetSquaredDistanceWithLhs() const noexcept;
        NODISCARD Real GetSquaredDistanceWithRhs() const noexcept;
        NODISCARD Real GetOriginDifferenceDotDirectionAverage() const noexcept;

    private:
        Vector3Type originDifference;
        Real directionDot;
        Real originDifferenceDotLhsDirection;
        Real originDifferenceDotRhsDirection;
        Real originDifferenceSquaredLength;
        Real det;
    };
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_TOOL_H
