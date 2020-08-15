// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:08)

#ifndef RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H
#define RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "OpenGLTextureData.h"
#include "System/Window/Flags/WindowFlags.h"
#include "Rendering/Renderers/Detail/PlatformTextureCubeImpl.h"

namespace Rendering
{
	class RendererImpl;
	class TextureCube;
	
	class RENDERING_HIDDEN_DECLARE OpenGLTextureCube : public PlatformTextureCubeImpl
	{
	public:
		using ClassType = OpenGLTextureCube;
		using ParentType = PlatformTextureCubeImpl;

	public:		
		OpenGLTextureCube (Renderer* renderer, const TextureCube* texture);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		  void Enable (Renderer* renderer, int textureUnit) noexcept override;
           void Disable(Renderer* renderer, int textureUnit) noexcept override;
		  void* Lock (int face,int level, BufferLocking mode) noexcept override;
		  void Unlock (int face,int level) noexcept override;
		
	private:
		OpenGLTextureData<TextureCube> m_OpenGLTextureData;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H


