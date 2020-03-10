// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 15:40)

#ifndef RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_H
#define RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
	template <typename PlatformTextureType>
	class TextureLockManager : boost::noncopyable
	{
	public:
		typedef TextureLockManager<PlatformTextureType> ClassType;

	public:
		explicit TextureLockManager(PlatformTextureType& manager);
		~TextureLockManager();

		CLASS_INVARIANT_DECLARE;
 
		void* Lock(int level, BufferLocking mode);
		void* Lock(int face, int level, BufferLocking mode);

	private:
		PlatformTextureType& m_Manager;
		int m_Level;
		int m_Face;
	};
}

#endif // RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_H



	