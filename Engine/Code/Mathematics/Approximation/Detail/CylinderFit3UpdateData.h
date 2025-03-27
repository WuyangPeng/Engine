///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:24)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE CylinderFit3UpdateData final
    {
    public:
        using ClassType = CylinderFit3UpdateData<Real>;

        using Vector3Type = Vector3<Real>;

    public:
        CylinderFit3UpdateData(const Vector3Type& point, const Vector3Type& center, const Vector3Type& axis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3Type GetPoint() const noexcept;
        NODISCARD Vector3Type GetDelta() const noexcept;
        NODISCARD Vector3Type GetDeltaCrossAxis() const noexcept;
        NODISCARD Real GetDeltaCrossAxisLengthQuartic() const noexcept;
        NODISCARD Vector3Type GetDescentDirection() const noexcept;

    private:
        NODISCARD static Vector3Type CalculateDescentDirection(const Vector3Type& delta, const Vector3Type& axis) noexcept;

    private:
        Vector3Type point;
        Vector3Type delta;
        Vector3Type deltaCrossAxis;
        Real deltaCrossAxisLengthQuartic;
        Vector3Type descentDirection;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H
