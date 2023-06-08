///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 19:13)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
#define MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H

#include "System/Helper/EnumOperator.h"

namespace Mathematics
{
    // �����ཻ���ϵ���Ϣ
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
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
