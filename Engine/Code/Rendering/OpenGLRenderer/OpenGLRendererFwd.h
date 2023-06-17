///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:17)

#ifndef RENDERING_OPENGL_RENDERER_FWD_H
#define RENDERING_OPENGL_RENDERER_FWD_H

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

// 提供了基于OpenGL的抽象API实现
namespace Rendering
{
    System::OpenGLUInt BindTexture(ShaderFlags::SamplerType target, System::OpenGLUInt texture);
    System::OpenGLUInt GetBoundTexture(ShaderFlags::SamplerType target);

    template <VertexFormatFlags::Semantic usage>
    class OpenGLVertexFormatData;

    template <VertexFormatFlags::Semantic usage, VertexFormatFlags::MaximumNumber number>
    class OpenGLVertexFormatArrayData;

    template <typename Texture>
    class OpenGLTextureData;

    template <typename ManageType>
    class OpenGLTextureDataManager;

    class OpenGLRenderTargetData;
}

#endif  // RENDERING_OPENGL_RENDERER_FWD_H