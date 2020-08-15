// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 10:58)

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
 
	// ֧�ְ󶨺����°󶨡� BindTexture�����������ָ����Ŀ�겢������ǰ�󶨵�Ŀ������ 
	// GetBoundTexture����ָ��Ŀ��ĵ�ǰ�󶨵�����
	RENDERING_DEFAULT_DECLARE UInt BindTexture(ShaderFlags::SamplerType target, UInt texture) noexcept;
	RENDERING_DEFAULT_DECLARE UInt GetBoundTexture(ShaderFlags::SamplerType target) noexcept;
}

#endif // RENDERING_RENDERERS_OPENGL_BIND_TEXTURE_H
