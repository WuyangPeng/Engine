///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 10:10)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
#define MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H

#include "System/Helper/EnumMacro.h"

namespace Mathematics
{
    // 关于相交集合的信息
    enum class IntersectionType
    {
        Empty,
        Point,
        Segment,
        Ray,
        Line,
        Polygon,
        Plane,
        Polyhedron,
        Other,
        Circle,
        Sphere0,
        Sphere0Point,
        Sphere1,
        Sphere1Point,
    };

    ENUM_INCREMENTABLE_OPERATOR_DEFINE(IntersectionType);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
