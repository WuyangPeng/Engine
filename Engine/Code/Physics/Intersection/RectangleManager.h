///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:36)

#ifndef PHYSICS_INTERSECTION_RECTANGLE_MANAGER_H
#define PHYSICS_INTERSECTION_RECTANGLE_MANAGER_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/AxesAlignBoundingBox2.h"
#include "Mathematics/Meshes/EdgeKey.h"

#include <set>
#include <vector>

namespace Physics
{
    template <typename Real>
    class RectangleManager
    {
    public:
        using ClassType = RectangleManager<Real>;
    };

}

#endif  // PHYSICS_INTERSECTION_RECTANGLE_MANAGER_H
