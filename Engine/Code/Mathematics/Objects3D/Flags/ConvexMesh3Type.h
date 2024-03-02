///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/22 19:25)

#ifndef MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_TYPE_H
#define MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_TYPE_H

#include "Mathematics/MathematicsDll.h"

namespace Mathematics
{
    enum class ConvexMesh3Type
    {
        Empty = 0x00000000,
        Point = 0x00000001,
        Segment = 0x00000002,
        Polygon = 0x00000004,
        Polyhedron = 0x00000008
    };
}

#endif  // MATHEMATICS_OBJECTS_3D_CONVEX_MESH3_TYPE_H
