///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/10 16:34)

#ifndef MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_H
#define MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Objects3D/Ellipsoid3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class ContEllipsoid3 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = ContEllipsoid3<Real>;

    public:
        NODISCARD static Ellipsoid3<Real> ContEllipsoid(const std::vector<Vector3<Real>>& points);

        static void ProjectEllipsoid(const Ellipsoid3<Real>& ellipsoid, const Line3<Real>& line, Real& smin, Real& smax);

        NODISCARD static Ellipsoid3<Real> MergeEllipsoids(const Ellipsoid3<Real>& ellipsoid0, const Ellipsoid3<Real>& ellipsoid1);
    };
}

#endif  // MATHEMATICS_CONTAINMENT_CONT_ELLIPSOID3_H
