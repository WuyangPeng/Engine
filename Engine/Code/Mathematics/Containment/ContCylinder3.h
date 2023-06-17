///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:42)

#ifndef MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_H
#define MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Cylinder3.h"

namespace Mathematics
{
    template <typename Real>
    class ContCylinder3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContCylinder3<Real>;

    public:
        NODISCARD static Cylinder3<Real> ContCylinder(const std::vector<Vector3<Real>>& points);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_CYLINDER3_H
