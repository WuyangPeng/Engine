// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:07)

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
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
                  void Enable(Renderer* renderer, int textureUnit) noexcept override;
		  void Disable (Renderer* renderer, int textureUnit) noexcept override;
		  void* Lock (int level, BufferLocking mode) noexcept override;
		  void Unlock (int level) noexcept override;
		
	private:
		OpenGLTextureData<Texture3D> m_OpenGLTextureData;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_TEXTURE_3D_H
