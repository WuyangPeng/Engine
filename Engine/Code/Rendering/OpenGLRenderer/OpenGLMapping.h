///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 15:47)

#ifndef RENDERING_RENDERERS_OPENGL_MAPPING_H
#define RENDERING_RENDERERS_OPENGL_MAPPING_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"
#include "Rendering/Shaders/Flags/DepthStateFlags.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Shaders/Flags/StencilStateFlags.h"

namespace Rendering
{
    using Enum = System::OpenGLEnum;
    using UInt = System::OpenGLUInt;
    using Int = System::OpenGLInt;

    class RENDERING_DEFAULT_DECLARE OpenGLConstant
    {
    public:
        NODISCARD static Enum GetOpenGLAlphaSrcBlend(int index);
        NODISCARD static Enum GetOpenGLAlphaDstBlend(int index);
        NODISCARD static Enum GetOpenGLAlphaCompare(int index);
        NODISCARD static Enum GetOpenGLDepthCompare(int index);
        NODISCARD static Enum GetOpenGLStencilCompare(int index);
        NODISCARD static Enum GetOpenGLStencilOperation(int index);
        NODISCARD static Int GetOpenGLAttributeChannels(int index);
        NODISCARD static UInt GetOpenGLAttributeType(int index);
        NODISCARD static UInt GetOpenGLBufferLocking(int index);
        NODISCARD static UInt GetOpenGLBufferUsage(int index);
        NODISCARD static Int GetOpenGLMinFilter(int index);
        NODISCARD static UInt GetOpenGLTextureFormat(int index);
        NODISCARD static UInt GetOpenGLTextureInternalFormat(int index);
        NODISCARD static UInt GetOpenGLTextureTarget(int index);
        NODISCARD static UInt GetOpenGLTextureTargetBinding(int index);
        NODISCARD static UInt GetOpenGLTextureType(int index);
        NODISCARD static Int GetOpenGLWrapMode(int index);
        NODISCARD static Enum GetOpenGLPrimitiveType(int index);
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_MAPPING_H
