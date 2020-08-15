// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 10:58)

#ifndef RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
#define RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H

#include "Rendering/RenderingDll.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"

namespace Rendering
{
	using UInt = System::OpenGLUInt;
	using Int = System::OpenGLInt;
 
	// 支持绑定和重新绑定。 BindTexture结合输入纹理到指定的目标并返回以前绑定的目标纹理。 
	// GetBoundTexture返回指定目标的当前绑定的纹理。
	RENDERING_DEFAULT_DECLARE UInt BindTexture(ShaderFlags::SamplerType target, UInt texture) noexcept;
	RENDERING_DEFAULT_DECLARE UInt GetBoundTexture(ShaderFlags::SamplerType target) noexcept;
}

#endif // RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
