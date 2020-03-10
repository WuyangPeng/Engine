// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/26 16:55)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TextureManagementLockEncapsulation.h" 
#include "TextureManagement.h"
#include "PlatformTexture1D.h"
#include "PlatformTexture2D.h"
#include "PlatformTexture3D.h"
#include "PlatformTextureCube.h"
#include "Rendering/OpenGLRenderer/TextureDataTraits.h"
#include "Rendering/Resources/Flags/TextureFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 

template <typename TextureManagementType>
Rendering::TextureManagementLockEncapsulation<TextureManagementType>
	::TextureManagementLockEncapsulation(TextureManagementType& manager)
	:m_Manager{ manager }, m_Texture{ nullptr }, m_Level{ -1 }, m_Face{ -1 }
{
	RENDERING_SELF_CLASS_IS_VALID_9;
}

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture1D> >
	::~TextureManagementLockEncapsulation();

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture2D> >
	::~TextureManagementLockEncapsulation();

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTexture3D> >
	::~TextureManagementLockEncapsulation();

template <>
RENDERING_DEFAULT_DECLARE Rendering::TextureManagementLockEncapsulation<Rendering::TextureManagement<Rendering::PlatformTextureCube> >
	::~TextureManagementLockEncapsulation();
 
#ifdef OPEN_CLASS_INVARIANT
template <typename TextureManagementType>
bool Rendering::TextureManagementLockEncapsulation<TextureManagementType>
	::IsValid() const noexcept
{
    return true;
}
#endif // OPEN_CLASS_INVARIANT


template <typename TextureManagementType>
void* Rendering::TextureManagementLockEncapsulation<TextureManagementType>
	::Lock( TextureConstPtr texture,int level,BufferLocking mode )
{
	static_assert(TextureDataTraits<TextureManagementType::TextureType>::sm_TextureType != TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_9;

	auto videoMemory = m_Manager.Lock(texture,level,mode);
	m_Texture = texture;
	m_Level = level;
	
	return videoMemory;	
}


template <typename TextureManagementType>
void* Rendering::TextureManagementLockEncapsulation<TextureManagementType>
	::LockCube( TextureConstPtr texture,int face,int level,BufferLocking mode )
{
	static_assert(TextureDataTraits<TextureManagementType::TextureType>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_9;

	auto videoMemory = m_Manager.LockCube(texture,face,level,mode);
	m_Texture = texture;
	m_Level = level; 
	m_Face = face;

	return videoMemory;	
}
 
#endif // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_LOCK_ENCAPSULATION_DETAIL_H