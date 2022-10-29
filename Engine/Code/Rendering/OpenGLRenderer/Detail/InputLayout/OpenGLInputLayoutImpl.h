///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/27 13:44)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/OpenGLFwd.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/InputLayout/OpenGLInputLayoutAttribute.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

#include <array>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLInputLayoutImpl
    {
    public:
        using ClassType = OpenGLInputLayoutImpl;
        using OpenGLUInt = System::OpenGLUInt;
        using OpenGLData = System::OpenGLData;

    public:
        OpenGLInputLayoutImpl(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBuffer& vertexBuffer);
        ~OpenGLInputLayoutImpl() noexcept;
        OpenGLInputLayoutImpl(const OpenGLInputLayoutImpl& rhs) = default;
        OpenGLInputLayoutImpl& operator=(const OpenGLInputLayoutImpl& rhs) = default;
        OpenGLInputLayoutImpl(OpenGLInputLayoutImpl&& rhs) = default;
        OpenGLInputLayoutImpl& operator=(OpenGLInputLayoutImpl&& rhs) = default;

        CLASS_INVARIANT_DECLARE;

        void Enable() noexcept;
        void Disable() noexcept;

        NODISCARD static OpenGLData GetChannelType(ChannelType channelType);

    private:
        static constexpr auto attributeCount = System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes);

        using AttributesContainer = std::array<OpenGLInputLayoutAttribute, attributeCount>;

    private:
        OpenGLUInt vertexBufferHandle;
        OpenGLUInt vertexArrayHandle;
        int numAttributes;
        AttributesContainer attributes;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_IMPL_H