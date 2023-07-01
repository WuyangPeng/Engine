///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:27)

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
        PolyPoint = 0x00000001,
        PolySegmentDisjoint = 0x00000002,
        PolySegmentContiguous = 0x00000004,
        TriMesh = 0x00000008,
        TriStrip = 0x00000010,
        PolySegmentDisjointAdj = 0x00000020,
        PolySegmentContiguousAdj = 0x00000040,
        TriMeshAdj = 0x00000080,
        TriStripAdj = 0x00000100,

        HasPoints = PolyPoint,

        HasSegments = PolySegmentDisjoint |
                      PolySegmentContiguous |
                      PolySegmentDisjointAdj |
                      PolySegmentContiguousAdj,

        HasTriangles = TriMesh |
                       TriStrip |
                       TriMeshAdj |
                       TriStripAdj,

        NumTypes = 9
    };

}

#endif  // RENDERING_RESOURCES_INDEX_FORMAT_H