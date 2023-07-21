///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:18)

#ifndef RENDERING_RENDERERS_OPENGL_MAPPING_H
#define RENDERING_RENDERERS_OPENGL_MAPPING_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/Flags/BufferFlags.h"
#include "Rendering/SceneGraph/Flags/VisualFlags.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"
#include "Rendering/Shaders/Flags/DepthStateFlags.h"

#include "Rendering/Shaders/Flags/StencilStateFlags.h"

namespace Rendering
{
    using Enum = System::OpenGLEnum;
    using UInt = System::OpenGLUInt;
    using Int = System::OpenGLInt;

    class RENDERING_DEFAULT_DECLARE OpenGLConstant
    {
    public:
        NODISCARD static Int GetOpenGLAttributeChannels(int index);
        NODISCARD static UInt GetOpenGLAttributeType(int index);
        NODISCARD static UInt GetOpenGLBufferLocking(int index);
        NODISCARD static UInt GetOpenGLBufferUsage(int index);
        NODISCARD static UInt GetOpenGLTextureFormat(int index);
        NODISCARD static UInt GetOpenGLTextureTarget(int index);
        NODISCARD static UInt GetOpenGLTextureTargetBinding(int index);
        NODISCARD static UInt GetOpenGLTextureType(int index);
        NODISCARD static Int GetOpenGLWrapMode(int index);
        NODISCARD static Enum GetOpenGLPrimitiveType(int index);
    };
}

#endif  // RENDERING_RENDERERS_OPENGL_MAPPING_H
