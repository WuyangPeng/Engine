// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:31)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformTexture1DImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class Renderer;
	class Texture1D;
	
	class RENDERING_DEFAULT_DECLARE PlatformTexture1D : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformTexture1D);	
		using TextureType = Texture1D;

	public:
		PlatformTexture1D(Renderer* renderer, const Texture1D* texture1D);

		CLASS_INVARIANT_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		void Enable (Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock(int level, BufferLocking mode);
		void Unlock (int level);

	private:
		IMPL_TYPE_DECLARE(PlatformTexture1D);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H
