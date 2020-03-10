// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:25)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <memory>

namespace Rendering
{
	class Renderer;
	class Texture3D;
	
	class RENDERING_HIDDEN_DECLARE PlatformTexture3DImpl
	{
	public:
		using ClassType = PlatformTexture3DImpl;
		using PlatformTexture3DPtr = std::shared_ptr<ClassType>;

	public:
		PlatformTexture3DImpl();
		virtual ~PlatformTexture3DImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		virtual void Enable (Renderer* renderer, int textureUnit) = 0;
		virtual void Disable (Renderer* renderer, int textureUnit) = 0;
		virtual void* Lock (int level, BufferLocking mode) = 0;
		virtual void Unlock (int level) = 0;		
	
		static PlatformTexture3DPtr Create(Renderer* renderer,  const Texture3D* texture3D);

    private:
        static PlatformTexture3DPtr CreateDefault(Renderer* renderer,  const Texture3D* texture3D);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_IMPL_H
