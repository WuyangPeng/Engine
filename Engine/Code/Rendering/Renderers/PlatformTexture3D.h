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
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(PlatformTexture3DImpl); 

namespace Rendering
{
	class Renderer;
	class Texture3D;
	
	class RENDERING_DEFAULT_DECLARE PlatformTexture3D  
	{
	public:
            NON_COPY_TYPE_DECLARE(PlatformTexture3D); 
		using TextureType = Texture3D;

	public:
		PlatformTexture3D(Renderer* renderer, const Texture3D* texture3D);
		virtual ~PlatformTexture3D ();
		PlatformTexture3D(const PlatformTexture3D&) = delete;
		PlatformTexture3D& operator=(const PlatformTexture3D&) = delete;
		PlatformTexture3D( PlatformTexture3D&&) = delete;
		PlatformTexture3D& operator=( PlatformTexture3D&&) = delete;
		
		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		void Enable(Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock (int level, BufferLocking mode);
		void Unlock (int level);		
	
	private:
                PackageType impl;
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_3D_H
