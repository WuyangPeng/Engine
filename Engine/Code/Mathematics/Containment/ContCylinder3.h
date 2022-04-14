///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/10 14:31)

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
