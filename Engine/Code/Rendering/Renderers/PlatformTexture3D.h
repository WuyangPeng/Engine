// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:32)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformTexture3DImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class Renderer;
	class Texture3D;
	
	class RENDERING_DEFAULT_DECLARE PlatformTexture3D : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformTexture3D); 
		using TextureType = Texture3D;

	public:
		PlatformTexture3D(Renderer* renderer, const Texture3D* texture3D);
		virtual ~PlatformTexture3D ();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		void Enable(Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock (int level, BufferLocking mode);
		void Unlock (int level);		
	
	private:
		IMPL_TYPE_DECLARE(PlatformTexture3D);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H
