// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:38)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_3D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformTexture3DImpl.h"
#include "System/Window/Flags/WindowFlags.h"  

namespace Rendering
{
	class Renderer;
	class Texture3D;
	
	class RENDERING_HIDDEN_DECLARE Dx9Texture3D : public PlatformTexture3DImpl
	{
	public:
		using ClassType = Dx9Texture3D;
		using ParentType = PlatformTexture3DImpl;

	public:		
		Dx9Texture3D(Renderer* renderer, const Texture3D* texture);
            ~Dx9Texture3D();
                Dx9Texture3D(const Dx9Texture3D&) = default;
            Dx9Texture3D& operator=(const Dx9Texture3D&) = default;
                Dx9Texture3D(Dx9Texture3D&&) = default;
            Dx9Texture3D& operator=(Dx9Texture3D&&) = default;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		 void Enable (Renderer* renderer, int textureUnit) override;
		 void Disable (Renderer* renderer, int textureUnit) override;
		 void* Lock (int level, BufferLocking mode) override;
		 void Unlock (int level) override;

	private:
		//IDirect3DVolumeTexture9* mTexture;
	};
}

#endif // RENDERING_RENDERERS_DX9_TEXTURE_1D_H
