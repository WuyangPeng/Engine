///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:24)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering
{
    namespace VertexFormatFlags
    {
        enum class MaximumNumber
        {
            // �����ʽ���Ե����������
            Attributes = 16,

            // �������굥λ���������
            TextureCoordinateUnits = 8,

            // ��ɫ��λ���������
            ColorUnits = 2
        };

        // �����ʽ���Ե��÷�(����)��
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

        // �����ʽ���Ե�ͨ�����͡�
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
