/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/26 13:49)

#ifndef RENDERING_SHADERS_REFERENCE_TYPE_H
#define RENDERING_SHADERS_REFERENCE_TYPE_H

namespace Rendering
{
    enum class ReferenceType
    {
        Vertex,
        Geometry,
        Pixel,
        Compute,
        TessControl,
        TessEvaluation
    };
}

#endif  // RENDERING_SHADERS_REFERENCE_TYPE_H
