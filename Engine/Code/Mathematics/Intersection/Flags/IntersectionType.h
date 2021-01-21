///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.0 (2020/12/16 10:10)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
#define MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H

#include "System/Helper/EnumMacro.h"

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

    ENUM_INCREMENTABLE_OPERATOR_DEFINE(IntersectionType);
}

#endif  // MATHEMATICS_INTERSECTION_INTERSECTION_TYPE_H
