///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:36)

#ifndef RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H
#define RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "LoadTexture.h"
#include "TextureLevelDataDetail.h"
#include "Detail/TextureData.h"
#include "Detail/TextureImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"

template <typename TexturePtrType, int WindowSize>
TexturePtrType Rendering::LoadTexture::CreateTexture1DPtr(const TextureData& data, ReadFileManager& inFile)
{
    static_assert(WindowSize == 1, "WindowSize == 1");

    const auto numDimensions = TextureImpl::CalculateNumDimensions(data.GetTextureType());

    TextureLevelData<WindowSize> levelData{ numDimensions };
    levelData.ReadFromFile(inFile);
    const auto dimension0 = levelData.GetDimension(0, 0);
    TexturePtrType texture{ std::make_shared<Texture1D>(data.GetFormat(), dimension0, data.GetNumLevels(), data.GetUsage()) };

    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TexturePtrType, int WindowSize>
TexturePtrType Rendering::LoadTexture::CreateTexture2DPtr(const TextureData& data, ReadFileManager& inFile)
{
    static_assert(WindowSize == 2, "WindowSize == 2");

    const auto numDimensions = TextureImpl::CalculateNumDimensions(data.GetTextureType());

    TextureLevelData<WindowSize> levelData{ numDimensions };
    levelData.ReadFromFile(inFile);
    const auto dimension0 = levelData.GetDimension(0, 0);
    const auto dimension1 = levelData.GetDimension(1, 0);
    TexturePtrType texture{ std::make_shared<Texture2D>(data.GetFormat(), dimension0, dimension1, data.GetNumLevels(), data.GetUsage()) };

    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TexturePtrType, int WindowSize>
TexturePtrType Rendering::LoadTexture::CreateTexture3DPtr(const TextureData& data, ReadFileManager& inFile)
{
    static_assert(WindowSize == 3, "WindowSize == 3");

    const auto numDimensions = TextureImpl::CalculateNumDimensions(data.GetTextureType());

    TextureLevelData<WindowSize> levelData{ numDimensions };
    levelData.ReadFromFile(inFile);
    const auto dimension0 = levelData.GetDimension(0, 0);
    const auto dimension1 = levelData.GetDimension(1, 0);
    const auto dimension2 = levelData.GetDimension(2, 0);
    TexturePtrType texture{ std::make_shared<Texture3D>(data.GetFormat(), dimension0, dimension1, dimension2, data.GetNumLevels(), data.GetUsage()) };

    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TexturePtrType, int WindowSize>
TexturePtrType Rendering::LoadTexture::CreateTextureCubePtr(const TextureData& data, ReadFileManager& inFile)
{
    static_assert(WindowSize == 2, "WindowSize == 2");

    const auto numDimensions = TextureImpl::CalculateNumDimensions(data.GetTextureType());

    TextureLevelData<WindowSize> levelData{ numDimensions };
    levelData.ReadFromFile(inFile);
    const auto dimension = levelData.GetDimension(0, 0);
    TexturePtrType texture{ std::make_shared<TextureCube>(data.GetFormat(), dimension, data.GetNumLevels(), data.GetUsage()) };

    texture->ReadFromFile(inFile);

    return texture;
}

#endif  // RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H
