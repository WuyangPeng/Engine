///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:35)

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
