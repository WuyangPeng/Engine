// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:03)

#ifndef RENDERING_OPENGL_RENDERER_FWD_H
#define RENDERING_OPENGL_RENDERER_FWD_H

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "Rendering/Shaders/Flags/ShaderFlags.h"
#include "Rendering/Resources/Flags/VertexFormatFlags.h"

// �ṩ�˻���OpenGL�ĳ���APIʵ��
namespace Rendering
{
	System::OpenGLUInt BindTexture(ShaderFlags::SamplerType target, System::OpenGLUInt texture);
	System::OpenGLUInt GetBoundTexture(ShaderFlags::SamplerType target);

	template <VertexFormatFlags::AttributeUsage usage>
	class OpenGLVertexFormatData;

	template <VertexFormatFlags::AttributeUsage usage,VertexFormatFlags::MaximumNumber number>
	class OpenGLVertexFormatArrayData;

	template <typename Texture>
	class OpenGLTextureData;

	template <typename ManageType>
	class OpenGLTextureDataManager;

	class OpenGLRenderTargetData;
}

#endif // RENDERING_OPENGL_RENDERER_FWD_H