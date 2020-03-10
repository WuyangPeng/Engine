// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/26 16:42)

#ifndef RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H
#define RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "ShaderManagement.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <typename TextureFlags,typename PdrTextureType>
Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::ShaderManagement(RendererWeakPtr ptr)
	: m_Renderer{ ptr }, m_Textures{}
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename TextureFlags,typename PdrTextureType>
bool Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::IsValid() const
{
	if(m_Renderer.lock())
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Bind (TextureConstWeakPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    if (m_Textures.find(texture) == m_Textures.end())
    {
		PdrTextureSharedPtr pdrTexture{ std::make_shared<PdrTextureType>(m_Renderer, texture) };
		m_Textures.insert({ texture, pdrTexture });
    }
}

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Unbind (TextureConstWeakPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

	m_Textures.erase(texture);
}
 
template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Enable (TextureConstWeakPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Textures.find(texture);
    PdrTextureSharedPtr pdrTexture;
    if (iter != m_Textures.end())
    {
        pdrTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        pdrTexture = std::make_shared<PdrTextureType>(m_Renderer, texture);
		m_Textures.insert({ texture,  pdrTexture });
    }

     pdrTexture->Enable(m_Renderer);
}

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Disable (TextureConstWeakPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Textures.find(texture);
 
    if (iter != m_Textures.end())
    {
		auto pdrTexture = iter->second;

        pdrBuffer->Disable(m_Renderer);
    }
}

template <typename TextureFlags,typename PdrTextureType>
void* Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Lock (TextureConstWeakPtr texture,int level,BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	auto iter = m_Textures.find(texture);
    PdrTextureSharedPtr pdrTexture;
    if (iter != m_Textures.end())
    {
		pdrTexture = iter->second;
    }
    else
    {
        // 延迟构造。
		pdrTexture = std::make_shared<PdrTextureType>(m_Renderer, texture);
		m_Textures.insert({ buffer, pdrTexture });
    }

	pdrTexture->Lock(level ,mode);
}

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Unlock (TextureConstWeakPtr texture,int level)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Textures.find(buffer);
 
    if (iter != m_Textures.end())
    {
		auto pdrTexture = iter->second;

		pdrTexture->Unlock(level);
    }
}

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Update (TextureConstWeakPtr texture,int level)
{
	RENDERING_CLASS_IS_VALID_1;

    auto numBytes = buffer->GetNumBytes(level);
	auto srcData = buffer->GetData(level);
	auto trgData = Lock(buffer, level ,Buffer::BL_WRITE_ONLY);
    memcpy(trgData, srcData, numBytes);
    Unlock(buffer, level);
}

template <typename TextureFlags,typename PdrTextureType>
Rendering::ShaderManagement<TextureFlags, PdrTextureType>::PdrTextureSharedPtr Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::GetResource (TextureConstWeakPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Textures.find(texture);
    if (iter != m_Textures.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的顶点缓冲区资源！"));
    }
}

#endif // RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H