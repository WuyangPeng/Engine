///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/29 20:40)

#ifndef RENDERING_OPENGL_RENDERER_REFERENCE_TYPE_H
#define RENDERING_OPENGL_RENDERER_REFERENCE_TYPE_H

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

#endif  // RENDERING_OPENGL_RENDERER_REFERENCE_TYPE_H
