// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/26 15:31)

#ifndef RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H
#define RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/Resources/Flags/BufferFlags.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include <boost/noncopyable.hpp>

RENDERING_NON_COPY_EXPORT_IMPL(PlatformTexture1DImpl); 

namespace Rendering
{
	class Renderer;
	class Texture1D;
	
	class RENDERING_DEFAULT_DECLARE PlatformTexture1D  
	{
	public:
            NON_COPY_TYPE_DECLARE(PlatformTexture1D);	
		using TextureType = Texture1D;

	public:
		PlatformTexture1D(Renderer* renderer, const Texture1D* texture1D);
		virtual ~PlatformTexture1D () = default;
		PlatformTexture1D(const PlatformTexture1D&) = delete;
		PlatformTexture1D& operator=(const PlatformTexture1D&) = delete;
		PlatformTexture1D( PlatformTexture1D&&) = delete;
		PlatformTexture1D& operator=( PlatformTexture1D&&) = delete;

		
		CLASS_INVARIANT_DECLARE;

		// ��������
		void Enable (Renderer* renderer, int textureUnit);
		void Disable (Renderer* renderer, int textureUnit);
		void* Lock(int level, BufferLocking mode);
		void Unlock (int level);

	private:
                PackageType impl;
	};
}

#endif // RENDERING_RENDERERS_PLATFORM_TEXTURE_1D_H
