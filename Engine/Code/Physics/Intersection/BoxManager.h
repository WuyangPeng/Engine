///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:35)

#ifndef PHYSICS_INTERSECTION_BOX_MANAGER_H
#define PHYSICS_INTERSECTION_BOX_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/AxesAlignBoundingBox3.h"
#include "Mathematics/Meshes/EdgeKey.h"

#include <set>
#include <vector>

namespace Physics
{
    template <typename Real>
    class BoxManager
    {
    public:
        using ClassType = BoxManager<Real>;
        using AxesAlignBoundingBox3D = Mathematics::AxesAlignBoundingBox3<Real>;
        using EdgeKey = Mathematics::EdgeKey;
    };

}

#endif  // PHYSICS_INTERSECTION_BOX_MANAGER_H
