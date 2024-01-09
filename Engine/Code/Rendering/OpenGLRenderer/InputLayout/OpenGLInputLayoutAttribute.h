/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 19:50)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_ATTRIBUTE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_ATTRIBUTE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLInputLayoutAttribute
    {
    public:
        using ClassType = OpenGLInputLayoutAttribute;

        using OpenGLInt = System::OpenGLInt;
        using OpenGLSize = System::OpenGLSize;
        using OpenGLIntPtr = System::OpenGLIntPtr;
        using OpenGLBoolean = System::OpenGLBoolean;

    public:
        OpenGLInputLayoutAttribute() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD VertexFormatFlags::Semantic GetSemantic() const noexcept;
        void SetSemantic(VertexFormatFlags::Semantic aSemantic) noexcept;

        NODISCARD OpenGLInt GetNumChannels() const noexcept;
        void SetNumChannels(OpenGLInt aNumChannels) noexcept;

        NODISCARD OpenGLInt GetChannelType() const noexcept;
        void SetChannelType(OpenGLInt aChannelType) noexcept;

        NODISCARD OpenGLBoolean GetNormalize() const noexcept;
        void SetNormalize(OpenGLBoolean aNormalize) noexcept;

        NODISCARD OpenGLInt GetLocation() const noexcept;
        void SetLocation(OpenGLInt aLocation) noexcept;

        NODISCARD OpenGLIntPtr GetOffset() const noexcept;
        void SetOffset(OpenGLIntPtr aOffset) noexcept;

        NODISCARD OpenGLSize GetStride() const noexcept;
        void SetStride(OpenGLSize aStride) noexcept;

    private:
        VertexFormatFlags::Semantic semantic;
        OpenGLInt numChannels;
        OpenGLInt channelType;
        OpenGLBoolean normalize;
        OpenGLInt location;
        OpenGLIntPtr offset;
        OpenGLSize stride;
    };

}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_ATTRIBUTE_H