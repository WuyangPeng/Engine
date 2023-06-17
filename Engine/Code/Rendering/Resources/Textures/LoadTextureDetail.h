///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:22)

#ifndef RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H
#define RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "LoadTexture.h"
#include "TextureLevelDataDetail.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "Rendering/Resources/Detail/Textures/TextureData.h"
#include "Rendering/Resources/Detail/Textures/TextureImpl.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

template <typename TextureType, int NumDimensions>
TextureType Rendering::LoadTexture::CreateTexture1D(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 1, "NumDimensions == 1");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<Texture1D>(dataFormatType, dimension0, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TextureType, int NumDimensions>
TextureType Rendering::LoadTexture::CreateTexture1DArray(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 1, "NumDimensions == 1");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<Texture1DArray>(numItems, dataFormatType, dimension0, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TextureType, int NumDimensions, typename ActualType>
TextureType Rendering::LoadTexture::CreateTexture2D(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 2, "NumDimensions == 2");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto dimension1 = 0;
    inFile.Read(sizeof(int32_t), &dimension1);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<ActualType>(dataFormatType, dimension0, dimension1, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TextureType, int NumDimensions>
TextureType Rendering::LoadTexture::CreateTexture2DArray(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 2, "NumDimensions == 2");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto dimension1 = 0;
    inFile.Read(sizeof(int32_t), &dimension1);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<Texture2DArray>(numItems, dataFormatType, dimension0, dimension1, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TextureType, int NumDimensions>
TextureType Rendering::LoadTexture::CreateTexture3D(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 3, "NumDimensions == 3");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto dimension1 = 0;
    inFile.Read(sizeof(int32_t), &dimension1);

    auto dimension2 = 0;
    inFile.Read(sizeof(int32_t), &dimension2);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<Texture3D>(dataFormatType, dimension0, dimension1, dimension2, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TextureType, int NumDimensions>
TextureType Rendering::LoadTexture::CreateTextureCube(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 2, "NumDimensions == 2");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<TextureCube>(dataFormatType, dimension0, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

template <typename TextureType, int NumDimensions>
TextureType Rendering::LoadTexture::CreateTextureCubeArray(ReadFileManager& inFile)
{
    static_assert(NumDimensions == 2, "NumDimensions == 2");

    auto dataFormatType = DataFormatType::Unknown;
    inFile.Read(sizeof(DataFormatType), &dataFormatType);

    auto dimension0 = 0;
    inFile.Read(sizeof(int32_t), &dimension0);

    auto hasMipmaps = false;
    inFile.Read(sizeof(bool), &hasMipmaps);

    auto numItems = 0;
    inFile.Read(sizeof(int32_t), &numItems);

    TextureType texture{ std::make_shared<TextureCubeArray>(numItems, dataFormatType, dimension0, hasMipmaps) };
    texture->ReadFromFile(inFile);

    return texture;
}

#endif  // RENDERING_RESOURCES_LOAD_TEXTURE_DETAIL_H
