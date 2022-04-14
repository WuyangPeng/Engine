///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.4 (2022/03/24 21:49)

#ifndef MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_H
#define MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Objects2D/Objects2DFwd.h"
#include "Mathematics/Objects3D/Objects3DFwd.h"

namespace Mathematics
{
    template <typename Real>
    class PerspProjEllipsoid
    {
    public:
        using ClassType = PerspProjEllipsoid<Real>;

    public:
        static void PerspectiveProjectEllipsoid(const Ellipsoid3<Real>& ellipsoid,
                                                const Vector3<Real>& eye,
                                                const Plane3<Real>& plane,
                                                const Vector3<Real>& u,
                                                const Vector3<Real>& v,
                                                Vector3<Real>& p,
                                                Ellipse2<Real>& ellipse);
    };

}

#endif  // MATHEMATICS_MISCELLANEOUS_PERS_PPROJ_ELLIPSOID_H
