// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 16:50)

#ifndef RENDERING_RENDERERS_TEXTURE_MANAGEMENT_DETAIL_H
#define RENDERING_RENDERERS_TEXTURE_MANAGEMENT_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TextureManagement.h"
#include "PlatformTexture1D.h"
#include "PlatformTexture2D.h"
#include "PlatformTexture3D.h"
#include "PlatformTextureCube.h"
#include "TextureManagementLockEncapsulationDetail.h"
#include "Rendering/Resources/Texture1D.h"
#include "Rendering/Resources/Texture2D.h"
#include "Rendering/Resources/Texture3D.h"
#include "Rendering/Resources/TextureCube.h"
#include "Rendering/OpenGLRenderer/TextureDataTraits.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename PlatformTextureType>
Rendering::TextureManagement<PlatformTextureType>
	::TextureManagement(RendererPtr ptr)
	: m_Renderer{ ptr }, m_Textures{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename PlatformTextureType>
bool Rendering::TextureManagement <PlatformTextureType>
	::IsValid() const noexcept
{
	if(m_Renderer.lock())
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::Bind (TextureConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    if (m_Textures.find(texture) == m_Textures.end())
    {
		PlatformTextureSharedPtr platformTexture{ std::make_shared<PlatformTextureType>(m_Renderer.lock().get(), texture.GetData()) };
		m_Textures.insert({ texture, platformTexture });
    }
}

template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::Unbind (TextureConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

	m_Textures.erase(texture);
}
 
template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::Enable (TextureConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Textures.find(texture);
    PlatformTextureSharedPtr platformTexture;
    if (iter != m_Textures.end())
    {
        platformTexture = iter->second;
    }
    else
    {
        // 延迟构造。
		platformTexture = std::make_shared<PlatformTextureType>(m_Renderer.lock().get(), texture.GetData());
		m_Textures.insert({ texture,  platformTexture });
    }

     platformTexture->Enable(m_Renderer.lock().get(), textureUnit);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::Disable(TextureConstPtr texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
 
    if (iter != m_Textures.end())
    {
		auto platformTexture = iter->second;

        platformTexture->Disable(m_Renderer.lock().get(), textureUnit);
    }
}

template <typename PlatformTextureType>
void* Rendering::TextureManagement <PlatformTextureType>
	::Lock (TextureConstPtr texture,int level,BufferLocking mode)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType != TextureFlags::TextureCube,"sm_TextureType != TextureCube ");

	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
    PlatformTextureSharedPtr platformTexture;
    if (iter != m_Textures.end())
    {
        platformTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        platformTexture = std::make_shared<PlatformTextureType>(m_Renderer.lock().get(), texture.GetData());
        m_Textures.insert(std::make_pair(texture, platformTexture));
    }

     return platformTexture->Lock(level ,mode);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::Unlock (TextureConstPtr texture,int level)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType != TextureFlags::TextureCube);
	
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
 
    if (iter != m_Textures.end())
    {
		auto platformTexture = iter->second;

        platformTexture->Unlock(level);
    }
}

template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::Update (TextureConstPtr texture,int level)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType != TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;

	auto numBytes = texture->GetNumLevelBytes(level);
	auto srcData = texture->GetTextureData(level);

	TextureManagementLockEncapsulation<ClassType> encapsulation{ *this };

	auto trgData = encapsulation.Lock(texture, level, BufferLocking::WriteOnly);
    memcpy(trgData, srcData, numBytes);    
}

template <typename PlatformTextureType>
typename Rendering::TextureManagement<PlatformTextureType>::PlatformTextureSharedPtr Rendering::TextureManagement<PlatformTextureType>
	::GetResource (TextureConstPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
    if (iter != m_Textures.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的纹理资源！"));
    }
}

template <typename PlatformTextureType>
void* Rendering::TextureManagement <PlatformTextureType>
	::LockCube (TextureConstPtr texture,int face,int level,BufferLocking mode)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
    PlatformTextureSharedPtr platformTexture;
    if (iter != m_Textures.end())
    {
        platformTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        platformTexture = std::make_shared<PlatformTextureType>(m_Renderer.lock().get(), texture.GetData());
		m_Textures.insert({ texture, platformTexture });
    }

     return platformTexture->Lock( face,level ,mode);
}

template <typename PlatformTextureType>
void Rendering::TextureManagement <PlatformTextureType>
	::UnlockCube (TextureConstPtr texture,int face,int level)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
 
    if (iter != m_Textures.end())
    {
		auto platformTexture = iter->second;

        platformTexture->Unlock(face,level);
    }
}

template <typename PlatformTextureType>
void Rendering::TextureManagement < PlatformTextureType>
	::UpdateCube (TextureConstPtr texture,int face,int level)
{
	static_assert(TextureDataTraits<PlatformTextureType::TextureType>::sm_TextureType == TextureFlags::TextureCube);

	RENDERING_CLASS_IS_VALID_1;

	auto numBytes = texture->GetNumLevelBytes(level);
	auto srcData = texture->GetTextureData(face,level);

	TextureManagementLockEncapsulation<ClassType> encapsulation{ *this };

	auto trgData = encapsulation.LockCube(texture, face,level, BufferLocking::WriteOnly);
    memcpy(trgData, srcData, numBytes);    
}

template <typename PlatformTextureType>
bool Rendering::TextureManagement<PlatformTextureType>
	::IsInTextureMap( TextureConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Textures.find(texture) != m_Textures.end();
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>
	::InsertTextureMap( TextureConstPtr texture,const PlatformTextureSharedPtr& platformTexture )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Textures.insert({ texture, platformTexture });
}

template <typename PlatformTextureType>
void Rendering::TextureManagement<PlatformTextureType>
	::RemoveTextureMap( TextureConstPtr texture )
{
	RENDERING_CLASS_IS_VALID_1;

	m_Textures.erase(texture);
}

#endif // RENDERING_RENDERERS_TEXTURE_MANAGEMENT_DETAIL_H