///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.1 (2023/07/01 15:37)

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
