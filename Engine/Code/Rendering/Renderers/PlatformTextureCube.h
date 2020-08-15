// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:32)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformTextureCubeImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class Renderer;
	class TextureCube;
	
	class RENDERING_DEFAULT_DECLARE PlatformTextureCube : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformTextureCube);
		using TextureType = TextureCube;

	public:
		PlatformTextureCube(Renderer* renderer, const TextureCube* textureCube);
		virtual ~PlatformTextureCube ();
		PlatformTextureCube(const PlatformTextureCube&) = delete;
		PlatformTextureCube& operator=(const PlatformTextureCube&) = delete;
		PlatformTextureCube( PlatformTextureCube&&) = delete;
		PlatformTextureCube& operator=( PlatformTextureCube&&) = delete;
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		void Enable (Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock (int face,int level, BufferLocking mode);
		void Unlock (int face,int level);		
	
	private:
		IMPL_TYPE_DECLARE(PlatformTextureCube);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_CUBE_H
