// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 16:48)

#ifndef RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TextureLockManager.h" 
#include "PlatformTexture1D.h"
#include "PlatformTexture2D.h"
#include "PlatformTexture3D.h"
#include "PlatformTextureCube.h"
#include "Rendering/OpenGLRenderer/TextureDataTraits.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

template <typename PlatformTextureType>
Rendering::TextureLockManager<PlatformTextureType>
	::TextureLockManager(PlatformTextureType& manager)
	:m_Manager{ manager }, m_Level{ -1 }, m_Face{ -1 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTexture1D>
	::~TextureLockManager();

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTexture2D>
	::~TextureLockManager();

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTexture3D>
	::~TextureLockManager();

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureLockManager<Rendering::PlatformTextureCube>
	::~TextureLockManager();
 
#ifdef OPEN_CLASS_INVARIANT
template <typename PlatformTextureType>
bool Rendering::TextureLockManager< PlatformTextureType>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename PlatformTextureType>
void* Rendering::TextureLockManager<PlatformTextureType>
	::Lock(int level, BufferLocking mode)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType != TextureFlags::TextureCube,"sm_TextureType != TextureCube");

	RENDERING_CLASS_IS_VALID_9;

	m_Level = level;

	return m_Manager.Lock(m_Level, mode);
}

template <typename PlatformTextureType>
void* Rendering::TextureLockManager<PlatformTextureType>
	::Lock(int face, int level, BufferLocking mode)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType == TextureFlags::TextureCube,"sm_TextureType == TextureCube");

	RENDERING_CLASS_IS_VALID_9;
	
	m_Level = level;
	m_Face = face;

	return m_Manager.Lock(m_Face, m_Level, mode);
}
 
#endif // RENDERING_RENDERERS_TEXTURE_LOCK_MANAGE_DETAIL_H