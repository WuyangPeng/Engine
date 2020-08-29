// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:37)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_2D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "System/Window/Flags/WindowFlags.h"  
#include "Rendering/OpenGLRenderer/OpenGLBindTexture.h"
#include "Rendering/Renderers/Detail/PlatformTexture2DImpl.h"

namespace Rendering
{
	class Renderer;
	class Texture2D;
	
	class RENDERING_HIDDEN_DECLARE Dx9Texture2D : public PlatformTexture2DImpl
	{
	public:
		using ClassType = Dx9Texture2D;
		using ParentType = PlatformTexture2DImpl;

	public:		
		Dx9Texture2D(Renderer* renderer, const Texture2D* texture);
		  ~Dx9Texture2D();
                Dx9Texture2D(const Dx9Texture2D&) = default;
                  Dx9Texture2D& operator=(const Dx9Texture2D&) = default;
                Dx9Texture2D(Dx9Texture2D&&) = default;
                  Dx9Texture2D& operator=(Dx9Texture2D&&) = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		 void Enable (Renderer* renderer, int textureUnit) override;
		 void Disable (Renderer* renderer, int textureUnit) override;
		 void* Lock (int level, BufferLocking mode) override;
		 void Unlock (int level) override;

		 UInt GetTexture() const override;

	private:
		// Constructor for creating the color/depth textures for a render target.	 
		Dx9Texture2D(Renderer* renderer, bool isColortexture, const Texture2D* texture, bool autoGenMipMap);

		//IDirect3DTexture9* mTexture;
	};
}

#endif // RENDERING_RENDERERS_DX9_TEXTURE_2D_H
