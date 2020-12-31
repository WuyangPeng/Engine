///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 16:16)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE CylinderFit3UpdateData final
    {
    public:
        using ClassType = CylinderFit3UpdateData<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        CylinderFit3UpdateData(const Vector3D& point, const Vector3D& center, const Vector3D& axis);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Vector3D GetDelta() const noexcept;
        [[nodiscard]] const Vector3D GetDeltaCrossAxis() const noexcept;
        [[nodiscard]] Real GetDeltaCrossAxisLengthQuartic() const noexcept;
        [[nodiscard]] const Vector3D GetDescentDirection() const noexcept;

    private:
        [[nodiscard]] static const Vector3D CalculateDescentDirection(const Vector3D& delta, const Vector3D& axis) noexcept;

    private:
        Vector3D m_Point;
        Vector3D m_Delta;
        Vector3D m_DeltaCrossAxis;
        Real m_DeltaCrossAxisLengthQuartic;
        Vector3D m_DescentDirection;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_H
