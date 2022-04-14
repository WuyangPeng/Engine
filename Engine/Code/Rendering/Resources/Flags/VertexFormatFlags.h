///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 10:25)

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

        // 顶点格式属性的用法(语义)。
        enum class AttributeUsage
        {
            None,
            Position,  // 属性 0
            Normal,  // 属性 2
            Tangent,  // 属性 14
            Binormal,  // 属性 15
            TextureCoord,  // 属性 8-15
            Color,  // 属性 3-4
            BlendIndices,  // 属性 7
            BlendWeight,  // 属性 1
            FogCoord,  // 属性 5
            Psize,  // 属性 6
            Quantity
        };
    }
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
