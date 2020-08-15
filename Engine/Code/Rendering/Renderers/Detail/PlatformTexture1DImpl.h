// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 14:22)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_IMPL_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <memory>

namespace Rendering
{
	class Renderer;
	class Texture1D;
	
	class RENDERING_HIDDEN_DECLARE PlatformTexture1DImpl
	{
	public:
		using ClassType = PlatformTexture1DImpl;
		using PlatformTexture1DPtr = std::shared_ptr<ClassType>;

	public:
		PlatformTexture1DImpl() noexcept;
		virtual ~PlatformTexture1DImpl();
                PlatformTexture1DImpl(const PlatformTexture1DImpl&) = default;
                PlatformTexture1DImpl& operator=(const PlatformTexture1DImpl&) = default;
                PlatformTexture1DImpl(PlatformTexture1DImpl&&) = default;
                PlatformTexture1DImpl& operator=(PlatformTexture1DImpl&&) = default;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		virtual void Enable (Renderer* renderer, int textureUnit) = 0;
		virtual void Disable (Renderer* renderer, int textureUnit) = 0;
		virtual void* Lock (int level, BufferLocking mode) = 0;
		virtual void Unlock (int level) = 0;		
	
		static PlatformTexture1DPtr Create(Renderer* renderer,  const Texture1D* texture1D);

    private:
        static PlatformTexture1DPtr CreateDefault(Renderer* renderer,  const Texture1D* texture1D);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_IMPL_H
