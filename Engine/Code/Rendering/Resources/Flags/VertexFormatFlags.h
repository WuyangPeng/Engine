///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    namespace VertexFormatFlags
    {
        enum class MaximumNumber
        {
            // 顶点格式属性的最大数量。
            Attributes = 16,

            // 纹理坐标单位的最大数量
            TextureCoordinateUnits = 8,

            // 颜色单位的最大数量
            ColorUnits = 2
        };

        // 顶点格式属性的用法(语义)。
        enum class Semantic
        {
            None,
            Position,
            BlendWeight,
            BlendIndices,
            Normal,
            Psize,
            TextureCoord,
            Tangent,
            Binormal,
            TessFactor,
            Positiont,
            Color,
            FogCoord,
            Depth,
            Sample,
            Quantity
        };

        // 顶点格式属性的通道类型。
        enum class AttributeType
        {
            None,
            Float1,
            Float2,
            Float3,
            Float4,
            Half1,
            Half2,
            Half3,
            Half4,
            UByte4,
            Short1,
            Short2,
            Short4,
            Quantity
        };
    }
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
