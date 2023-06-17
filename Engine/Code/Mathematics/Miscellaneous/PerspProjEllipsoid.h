///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 10:23)

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
