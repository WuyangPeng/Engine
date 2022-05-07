///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 15:17)

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
