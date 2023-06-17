///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:19)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_H
#define RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLInputLayout, OpenGLInputLayoutImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLInputLayout
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLInputLayout);
        using OpenGLUInt = System::OpenGLUInt;

    public:
        OpenGLInputLayout(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBuffer& vertexBuffer);

        CLASS_INVARIANT_DECLARE;

        void Enable() noexcept;
        void Disable() noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_H