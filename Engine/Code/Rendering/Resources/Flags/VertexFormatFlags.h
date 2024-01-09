/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/29 13:54)

#ifndef RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
#define RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H

#include "Rendering/RenderingDll.h"

namespace Rendering::VertexFormatFlags
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
        PSize,
        TextureCoord,
        Tangent,
        Binormal,
        TessFactor,
        PositionT,
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

#endif  // RENDERING_RESOURCES_VERTEX_FORMAT_FLAGS_H
