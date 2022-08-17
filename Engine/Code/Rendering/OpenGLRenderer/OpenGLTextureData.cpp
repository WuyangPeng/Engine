///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 14:10)

#include "Rendering/RenderingExport.h"

#include "OpenGLTextureDataDetail.h"
#include "OpenGLTextureDataManageDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "System/MemoryTools/MemoryHelper.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture1D>::CreateMipmapLevelStructures(const Texture1D* aTexture, MAYBE_UNUSED UInt previousBind) noexcept
{
    if (aTexture == nullptr)
    {
        return;
    }

    for (auto level = 0u; level < numLevels; ++level)
    {
        OpenGLTextureDataManager<ClassType> manager(*this);
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture2D>::CreateMipmapLevelStructures(const Texture2D* aTexture, MAYBE_UNUSED UInt previousBind) noexcept
{
    if (aTexture == nullptr)
    {
        return;
    }

    for (auto level = 0u; level < numLevels; ++level)
    {
        OpenGLTextureDataManager<ClassType> manage(*this);
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture3D>::CreateMipmapLevelStructures(const Texture3D* aTexture, MAYBE_UNUSED UInt previousBind) noexcept
{
    if (aTexture == nullptr)
    {
        return;
    }

    // 创建mipmap层次结构。无图像的初始化产生。

    for (auto level = 0u; level < numLevels; ++level)
    {
        OpenGLTextureDataManager<ClassType> manager(*this);
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::TextureCube>::CreateMipmapLevelStructures(const TextureCube* aTexture, MAYBE_UNUSED UInt previousBind) noexcept
{
    if (aTexture == nullptr)
    {
        return;
    }

    // 创建mipmap层次结构。无图像的初始化产生。

    for (auto face = 0; face < textureFace; ++face)
    {
        for (auto level = 0u; level < numLevels; ++level)
        {
            OpenGLTextureDataManager<ClassType> manager(*this);
        }
    }
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture1D>::TextureImage(MAYBE_UNUSED int level) noexcept
{
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture2D>::TextureImage(MAYBE_UNUSED int level) noexcept
{
}

// private
template <>
void Rendering::OpenGLTextureData<Rendering::Texture3D>::TextureImage(MAYBE_UNUSED int level) noexcept
{
}
