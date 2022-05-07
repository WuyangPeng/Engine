///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 15:18)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3_H

#include "Physics/PhysicsDll.h"

#include "Mathematics/Objects3D/ConvexPolyhedron3.h"

namespace Physics
{
    template <typename Real>
    class ExtremalQuery3
    {
    public:
        using ClassType = ExtremalQuery3<Real>;
        using ConvexPolyhedron3 = Mathematics::ConvexPolyhedron3<Real>;
        using Vector3D = Mathematics::Vector3<Real>;
    };
}

#endif  // PHYSICS_INTERSECTION_EXTREMAL_QUERY3_H
