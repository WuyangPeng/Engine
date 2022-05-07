///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 15:36)

#ifndef RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
#define RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/RenderingDll.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
    using UInt = System::OpenGLUInt;
    using Int = System::OpenGLInt;

    // 支持绑定和重新绑定。 BindTexture结合输入纹理到指定的目标并返回以前绑定的目标纹理。
    // GetBoundTexture返回指定目标的当前绑定的纹理。
    NODISCARD RENDERING_DEFAULT_DECLARE UInt BindTexture(ShaderFlags::SamplerType target, UInt texture);
    NODISCARD RENDERING_DEFAULT_DECLARE UInt GetBoundTexture(ShaderFlags::SamplerType target);
}

#endif  // RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
