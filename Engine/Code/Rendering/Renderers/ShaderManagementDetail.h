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
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26486)
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
	::IsValid() const noexcept
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
		PdrTextureSharedPtr pdrTexture{ std::make_shared<PdrTextureType>(m_Renderer.lock().get(), texture.get()) };
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
	::Enable (TextureConstWeakPtr texture, const ConstShaderParametersSmartPointer& parameters)
{
	RENDERING_CLASS_IS_VALID_1;
	parameters;
        const auto iter = m_Textures.find(texture);
    PdrTextureSharedPtr pdrTexture;
    if (iter != m_Textures.end())
    {
        pdrTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        pdrTexture = std::make_shared<PdrTextureType>(m_Renderer.lock().get(), texture.get());
		m_Textures.insert({ texture,  pdrTexture });
    }

     pdrTexture->Enable(m_Renderer.lock().get(),texture.get(),parameters.get());
}

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Disable (TextureConstWeakPtr texture, const ConstShaderParametersSmartPointer& parameters)
{
	RENDERING_CLASS_IS_VALID_1;
	parameters;
        const auto iter = m_Textures.find(texture);
 
    if (iter != m_Textures.end())
    {
		auto pdrTexture = iter->second;

		pdrTexture->Disable(m_Renderer.lock().get(), texture.get(), parameters.get());
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
		pdrTexture = std::make_shared<PdrTextureType>(m_Renderer.lock().get(), texture.get());
		m_Textures.insert({ texture, pdrTexture });
    }

	pdrTexture->Lock(level ,mode);
}

template <typename TextureFlags,typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::Unlock (TextureConstWeakPtr texture,int level)
{
	RENDERING_CLASS_IS_VALID_1;

    auto iter = m_Textures.find(texture);
 
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

    auto numBytes = texture->GetNumBytes(level);
	auto srcData = texture->GetData(level);
	auto trgData = Lock(texture, level , BufferLocking::WriteOnly);
    memcpy(trgData, srcData, numBytes);
    Unlock(texture, level);
}

template <typename TextureFlags,typename PdrTextureType>
typename Rendering::ShaderManagement<TextureFlags, PdrTextureType>::PdrTextureSharedPtr Rendering::ShaderManagement<TextureFlags, PdrTextureType>
	::GetResource (TextureConstWeakPtr texture)
{
	RENDERING_CLASS_IS_VALID_1;

const auto iter = m_Textures.find(texture);
    if (iter != m_Textures.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的顶点缓冲区资源！"s));
    }
}
#include STSTEM_WARNING_POP
#endif // RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H