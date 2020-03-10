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
		virtual ~OpenGLTextureCube ();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		virtual void Enable (Renderer* renderer, int textureUnit) override;
		virtual void Disable (Renderer* renderer, int textureUnit) override;
		virtual void* Lock (int face,int level, BufferLocking mode) override;
		virtual void Unlock (int face,int level) override;
		
	private:
		OpenGLTextureData<TextureCube> m_OpenGLTextureData;
	};
}

#endif // RENDERING_RENDERERS_OPENGL_TEXTURE_CUBE_H


