///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:26)

#ifndef RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H
#define RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H

#include "ShaderManagement.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename TextureFlags, typename PdrTextureType>
Rendering::ShaderManagement<TextureFlags, PdrTextureType>::ShaderManagement(const RendererWeakPtr& renderer)
    : renderer{ renderer }, textures{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename TextureFlags, typename PdrTextureType>
bool Rendering::ShaderManagement<TextureFlags, PdrTextureType>::IsValid() const noexcept
{
    if (renderer.lock())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename TextureFlags, typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Bind(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    if (textures.find(texture) == textures.end())
    {
        auto pdrTexture = std::make_shared<PdrTextureType>(renderer.lock().get(), texture.get());
        textures.emplace(texture, pdrTexture);
    }
}

template <typename TextureFlags, typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Unbind(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    textures.erase(texture);
}

template <typename TextureFlags, typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Enable(const ConstTextureSharedPtr& texture, const ShaderParameters& parameters)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);
    PdrTextureSharedPtr pdrTexture{};
    if (iter != textures.end())
    {
        pdrTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        pdrTexture = std::make_shared<PdrTextureType>(renderer.lock().get(), texture.get());
        textures.insert({ texture, pdrTexture });
    }

    pdrTexture->Enable(renderer.lock().get(), texture.get(), &parameters);
}

template <typename TextureFlags, typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Disable(const ConstTextureSharedPtr& texture, const ShaderParameters& parameters)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);

    if (iter != textures.end())
    {
        auto pdrTexture = iter->second;

        pdrTexture->Disable(renderer.lock().get(), texture.get(), &parameters);
    }
}

template <typename TextureFlags, typename PdrTextureType>
void* Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Lock(const ConstTextureSharedPtr& texture, int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    auto iter = textures.find(texture);
    PdrTextureSharedPtr pdrTexture{};
    if (iter != textures.end())
    {
        pdrTexture = iter->second;
    }
    else
    {
        // 延迟构造。
        pdrTexture = std::make_shared<PdrTextureType>(renderer.lock().get(), texture.get());
        textures.emplace(texture, pdrTexture);
    }

    pdrTexture->Lock(level, mode);
}

template <typename TextureFlags, typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Unlock(const ConstTextureSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    auto iter = textures.find(texture);

    if (iter != textures.end())
    {
        auto pdrTexture = iter->second;

        pdrTexture->Unlock(level);
    }
}

template <typename TextureFlags, typename PdrTextureType>
void Rendering::ShaderManagement<TextureFlags, PdrTextureType>::Update(const ConstTextureSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    auto numBytes = texture->GetNumBytes(level);
    auto srcData = texture->GetData(level);
    auto trgData = Lock(texture, level, BufferLocking::WriteOnly);
    System::MemoryCopy(trgData, srcData, numBytes);
    Unlock(texture, level);
}

template <typename TextureFlags, typename PdrTextureType>
typename Rendering::ShaderManagement<TextureFlags, PdrTextureType>::PdrTextureSharedPtr Rendering::ShaderManagement<TextureFlags, PdrTextureType>::GetResource(const ConstTextureSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto iter = textures.find(texture);
    if (iter != textures.end())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定的顶点缓冲区资源！"s));
    }
}

#endif  // RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_DETAIL_H