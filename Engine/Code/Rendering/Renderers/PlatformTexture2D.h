// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:31)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

RENDERING_EXPORT_SHARED_PTR(PlatformTexture2DImpl);
EXPORT_NONCOPYABLE_CLASS(RENDERING);

namespace Rendering
{
	class Renderer;
	class Texture2D;
	
	class RENDERING_DEFAULT_DECLARE PlatformTexture2D : boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(PlatformTexture2D);
		using TextureType = Texture2D;
		using UInt = System::OpenGLUInt;

	public:
		PlatformTexture2D(Renderer* renderer, const Texture2D* texture2D);
		virtual ~PlatformTexture2D ();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		// Œ∆¿Ì≤Ÿ◊˜
		void Enable (Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock(int level, BufferLocking mode);
		void Unlock (int level);	

		UInt GetTexture () const;
	
	private:
		IMPL_TYPE_DECLARE(PlatformTexture2D);
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_2D_H
