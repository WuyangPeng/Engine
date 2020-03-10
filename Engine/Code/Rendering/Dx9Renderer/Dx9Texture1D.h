// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:37)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_1D_H
#define RENDERING_RENDERERS_DX9_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/Detail/PlatformTexture1DImpl.h"
#include "System/Window/Flags/WindowFlags.h"  

namespace Rendering
{
	class Renderer;
	class Texture1D;
	
	class RENDERING_HIDDEN_DECLARE Dx9Texture1D : public PlatformTexture1DImpl
	{
	public:
		using ClassType = Dx9Texture1D;
		using ParentType = PlatformTexture1DImpl;

	public:		
		Dx9Texture1D(Renderer* renderer, const Texture1D* texture);
		virtual ~Dx9Texture1D();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		virtual void Enable (Renderer* renderer, int textureUnit) override;
		virtual void Disable (Renderer* renderer, int textureUnit) override;
		virtual void* Lock (int level, BufferLocking mode) override;
		virtual void Unlock (int level) override;

	private:
		//IDirect3DTexture9* mTexture;
	};
}

#endif // RENDERING_RENDERERS_DX9_TEXTURE_1D_H
