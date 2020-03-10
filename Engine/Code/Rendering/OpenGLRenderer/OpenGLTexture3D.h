// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:07)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Window/Flags/WindowFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture3DImpl.h"

namespace Rendering
{
	class Renderer;
	class Texture3D;
	
	class RENDERING_HIDDEN_DECLARE OpenGLTexture3D : public PlatformTexture3DImpl
	{
	public:
		using ClassType = OpenGLTexture3D;
		using ParentType = PlatformTexture3DImpl;

	public:		
		OpenGLTexture3D (Renderer* renderer, const Texture3D* texture);
		virtual ~OpenGLTexture3D ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// �������
		virtual void Enable (Renderer* renderer, int textureUnit) override;
		virtual void Disable (Renderer* renderer, int textureUnit) override;
		virtual void* Lock (int level, BufferLocking mode) override;
		virtual void Unlock (int level) override;
		
	private:
		OpenGLTextureData<Texture3D> m_OpenGLTextureData;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H
