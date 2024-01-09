/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:53)

#ifndef RENDERING_RESOURCES_INDEX_FORMAT_H
#define RENDERING_RESOURCES_INDEX_FORMAT_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumOperator.h"

namespace Rendering
{
    enum class IndexFormatType : uint32_t
    {
        Zero = 0x00000000,

        None = 0xFFFFFFFF,
        PolygonPoint = 0x00000001,
        PolygonSegmentDisjoint = 0x00000002,
        PolygonSegmentContiguous = 0x00000004,
        TriangleMesh = 0x00000008,
        TriangleStrip = 0x00000010,
        PolygonSegmentDisjointAdjacency = 0x00000020,
        PolygonSegmentContiguousAdjacency = 0x00000040,
        TriangleMeshAdjacency = 0x00000080,
        TriangleStripAdjacency = 0x00000100,

        HasPoints = PolygonPoint,

        HasSegments = PolygonSegmentDisjoint |
                      PolygonSegmentContiguous |
                      PolygonSegmentDisjointAdjacency |
                      PolygonSegmentContiguousAdjacency,

        HasTriangles = TriangleMesh |
                       TriangleStrip |
                       TriangleMeshAdjacency |
                       TriangleStripAdjacency,

        NumTypes = 9
    };

}

#endif  // RENDERING_RESOURCES_INDEX_FORMAT_H