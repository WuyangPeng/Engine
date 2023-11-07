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

        using Vector3 = Vector3<Real>;

    public:
        CylinderFit3UpdateData(const Vector3& point, const Vector3& center, const Vector3& axis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Vector3 GetDelta() const noexcept;
        NODISCARD Vector3 GetDeltaCrossAxis() const noexcept;
        NODISCARD Real GetDeltaCrossAxisLengthQuartic() const noexcept;
        NODISCARD Vector3 GetDescentDirection() const noexcept;

    private:
        NODISCARD static Vector3 CalculateDescentDirection(const Vector3& delta, const Vector3& axis) noexcept;

    private:
        Vector3 point;
        Vector3 delta;
        Vector3 deltaCrossAxis;
        Real deltaCrossAxisLengthQuartic;
        Vector3 descentDirection;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H
