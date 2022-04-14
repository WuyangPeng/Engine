///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/30 10:25)

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

        // �����ʽ���Ե��÷�(����)��
        enum class AttributeUsage
        {
            None,
            Position,  // ���� 0
            Normal,  // ���� 2
            Tangent,  // ���� 14
            Binormal,  // ���� 15
            TextureCoord,  // ���� 8-15
            Color,  // ���� 3-4
            BlendIndices,  // ���� 7
            BlendWeight,  // ���� 1
            FogCoord,  // ���� 5
            Psize,  // ���� 6
            Quantity
        };
    }
}

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
