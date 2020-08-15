// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 16:07)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/Flags/BufferFlags.h"

#include <boost/noncopyable.hpp>

namespace Rendering
{
	template <typename TextureManagementType>
	class TextureManagementLockEncapsulation : boost::noncopyable
	{
	public:
		using ClassType = TextureManagementLockEncapsulation<TextureManagementType>;
		using TextureConstPtr = typename TextureManagementType::TextureConstPtr;

	public:
		explicit TextureManagementLockEncapsulation(TextureManagementType& manager) noexcept;
		~TextureManagementLockEncapsulation();
		TextureManagementLockEncapsulation(const TextureManagementLockEncapsulation&) = delete;
		TextureManagementLockEncapsulation& operator=(const TextureManagementLockEncapsulation&) = delete;
		TextureManagementLockEncapsulation(TextureManagementLockEncapsulation&&) = delete;
		TextureManagementLockEncapsulation& operator=(TextureManagementLockEncapsulation&&) = delete;

		CLASS_INVARIANT_DECLARE;

		void* Lock(TextureConstPtr texture,int level,BufferLocking mode);
		void* LockCube(TextureConstPtr texture,int face,int level,BufferLocking mode);

	private:
		TextureManagementType& m_Manager;
		TextureConstPtr m_Texture;
		int m_Level;
		int m_Face;
	};
}

#endif // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_H



	