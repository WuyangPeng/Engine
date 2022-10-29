///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/27 18:26)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/InputLayout/OpenGLInputLayout.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

#include <map>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLInputLayoutManagerImpl
    {
    public:
        using ClassType = OpenGLInputLayoutManagerImpl;
        using OpenGLUInt = System::OpenGLUInt;
        using OpenGLInputLayoutSharedPtr = std::shared_ptr<OpenGLInputLayout>;

    public:
        OpenGLInputLayoutManagerImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInputLayoutSharedPtr Bind(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBufferSharedPtr& vertexBuffer);
        void Unbind(const VertexBufferSharedPtr& vertexBuffer);
        void UnbindAll() noexcept;
        NODISCARD bool HasElements() const noexcept;

    private:
        using InputLayoutKey = std::pair<ConstVertexBufferSharedPtr, OpenGLUInt>;
        using Container = std::map<InputLayoutKey, OpenGLInputLayoutSharedPtr>;

    private:
        Container inputLayout;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_IMPL_H