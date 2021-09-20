// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:39)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H
#define RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "System/Windows/Flags/WindowsFlags.h" 
#include "Rendering/Renderers/Detail/PlatformTextureCubeImpl.h"

namespace Rendering
{
	class RendererImpl;
	class TextureCube;
	
	class RENDERING_HIDDEN_DECLARE Dx9TextureCube : public PlatformTextureCubeImpl
	{
	public:
		using ClassType = Dx9TextureCube;
		using ParentType = PlatformTextureCubeImpl;

	public:		
		Dx9TextureCube(Renderer* renderer, const TextureCube* texture);
 
                ~Dx9TextureCube();
                Dx9TextureCube(const Dx9TextureCube&) = default;
                Dx9TextureCube& operator=(const Dx9TextureCube&) = default;
                Dx9TextureCube(Dx9TextureCube&&) = default;
                Dx9TextureCube& operator=(Dx9TextureCube&&) = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		 void Enable (Renderer* renderer, int textureUnit) override;
		 void Disable (Renderer* renderer, int textureUnit) override;
		 void* Lock (int face,int level, BufferLocking mode) override;
		 void Unlock (int face,int level) override;

	private:
		//IDirect3DCubeTexture9* mTexture;
	};
}

#endif // RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H


