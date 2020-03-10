// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:39)

#ifndef RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H
#define RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "System/Window/Flags/WindowFlags.h" 
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
		virtual ~Dx9TextureCube();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		// Œ∆¿Ì≤Ÿ◊˜
		virtual void Enable (Renderer* renderer, int textureUnit) override;
		virtual void Disable (Renderer* renderer, int textureUnit) override;
		virtual void* Lock (int face,int level, BufferLocking mode) override;
		virtual void Unlock (int face,int level) override;

	private:
		//IDirect3DCubeTexture9* mTexture;
	};
}

#endif // RENDERING_RENDERERS_DX9_TEXTURE_CUBE_H


