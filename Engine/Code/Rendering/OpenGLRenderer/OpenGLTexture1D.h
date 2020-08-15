// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:06)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_1D_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Window/Flags/WindowFlags.h"
#include "Rendering/Renderers/Detail/PlatformTexture1DImpl.h"

namespace Rendering
{
	class Renderer;
	class Texture1D;
	
	class RENDERING_HIDDEN_DECLARE OpenGLTexture1D : public PlatformTexture1DImpl
	{
	public:
		using ClassType = OpenGLTexture1D;
		using ParentType = PlatformTexture1DImpl;

	public:		
		OpenGLTexture1D (Renderer* renderer, const Texture1D* texture);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		  void Enable (Renderer* renderer, int textureUnit) noexcept override;
		  void Disable (Renderer* renderer, int textureUnit) noexcept override;
		  void* Lock (int level, BufferLocking mode) noexcept override;
                    void Unlock(int level) noexcept override;
		
	private:
		OpenGLTextureData<Texture1D> m_OpenGLTextureData;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_TEXTURE_1D_H
