///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/02/23 10:40)

#ifndef MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H
#define MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H

#include "System/Helper/EnumOperator.h"

namespace Mathematics
{
    // 顶点投影图（如何将顶点投影到间隔的最小和最大点）。
    enum class VertexProjectionMap
    {
        M2,
        M11,  // 线段
        M3,
        M21,
        M12,
        M111,  // 三角形
        M44,
        M2_2,
        M1_1  // 盒子
    };
}

#endif  // MATHEMATICS_INTERSECTION_VERTEX_PROJECTION_MAP_H
