///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:20) 

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
