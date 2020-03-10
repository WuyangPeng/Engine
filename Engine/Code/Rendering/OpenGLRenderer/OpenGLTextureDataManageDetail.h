// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/29 11:18)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_DETAIL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_MANAGE_DETAIL_H

#include "Rendering/RenderingExport.h" 

#include "OpenGLTextureDataManager.h"
#include "TextureDataTraits.h"
#include "OpenGLTextureData.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename ManageType>
Rendering::OpenGLTextureDataManager<ManageType>
	::OpenGLTextureDataManager(ManageType& manager)
	:m_Manager{ manager }, m_Level{ -1 }, m_Face{ -1 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture1D> >
	::~OpenGLTextureDataManager();

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture2D> >
	::~OpenGLTextureDataManager();

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::Texture3D> >
	::~OpenGLTextureDataManager();

template <>
RENDERING_DEFAULT_DECLARE Rendering::OpenGLTextureDataManager<Rendering::OpenGLTextureData<Rendering::TextureCube> >
	::~OpenGLTextureDataManager();

#ifdef OPEN_CLASS_INVARIANT 
template <typename ManageType>
bool Rendering::OpenGLTextureDataManager<ManageType>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIAN

template <typename ManageType>
void* Rendering::OpenGLTextureDataManager<ManageType>
	::Lock(int level, BufferLocking mode)
{
	static_assert(TextureDataTraits<ManageType::TextureType>::sm_TextureType != TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_9;

	m_Level = level;

	return m_Manager.Lock(m_Level, mode);
}

template <typename ManageType>
void* Rendering::OpenGLTextureDataManager<ManageType>
	::Lock(int face, int level, BufferLocking mode)
{
	static_assert(TextureDataTraits<ManageType::TextureType>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_9;
	
	m_Level = level;
	m_Face = face;

	return m_Manager.Lock(m_Face, m_Level, mode);
}

#endif // RENDERING_OPENGL_RENDERER_OPENGL_TEXTURE_DATA_DETAIL_H