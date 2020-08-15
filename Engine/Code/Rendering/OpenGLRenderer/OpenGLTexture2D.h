// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 11:07)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_2D_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Window/Flags/WindowFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture2DImpl.h"

namespace Rendering
{
	class Renderer;
	class Texture2D;
	
	class RENDERING_HIDDEN_DECLARE OpenGLTexture2D : public PlatformTexture2DImpl
	{
	public:
		using ClassType = OpenGLTexture2D;
		using ParentType = PlatformTexture2DImpl;
		using UInt = System::OpenGLUInt;

	public:		
		OpenGLTexture2D (Renderer* renderer, const Texture2D* texture);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// �������
		  void Enable (Renderer* renderer, int textureUnit) noexcept override;
		  void Disable (Renderer* renderer, int textureUnit) noexcept override;
		  void* Lock (int level, BufferLocking mode) noexcept  override;
		  void Unlock (int level) noexcept override;

		  UInt GetTexture () const noexcept override;
		
	private:
		OpenGLTextureData<Texture2D> m_OpenGLTextureData;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_TEXTURE_2D_H