///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 15:21)

#ifndef PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_H
#define PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_H

#include "Physics/PhysicsDll.h"

#include "ExtremalQuery3.h"
#include "Mathematics/Meshes/BasicMesh.h"

namespace Physics
{
    template <typename Real>
    class ExtremalQuery3BSP
    {
    public:
        using ClassType = ExtremalQuery3BSP<Real>;
        using BasicMesh = Mathematics::BasicMesh;
        using ConvexPolyhedron3 = Mathematics::ConvexPolyhedron3<Real>;
    };

}

#endif  // PHYSICS_INTERSECTION_EXTREMAL_QUERY3BSP_H
