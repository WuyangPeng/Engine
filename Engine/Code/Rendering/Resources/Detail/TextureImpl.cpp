///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/30 22:58)

#include "Rendering/RenderingExport.h"

#include "TextureImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

#include <vector>

using std::vector;

std::array<int, System::EnumCastUnderlying(Rendering::TextureFlags::Quantity)> Rendering::TextureImpl::numDimensions{
    1,  // TextureType::Texture1D
    2,  // TextureType::Texture2D
    3,  // TextureType::Texture3D
    2  // TextureType::TextureCube
};

std::array<int, System::EnumCastUnderlying(Rendering::TextureFormat::Quantity)> Rendering::TextureImpl::pixelSize{
    0,  // TextureFormat::None
    2,  // TextureFormat::R5G6B5
    2,  // TextureFormat::A1R5G5B5
    2,  // TextureFormat::A4R4G4B4
    1,  // TextureFormat::A8
    1,  // TextureFormat::L8
    2,  // TextureFormat::A8L8
    3,  // TextureFormat::R8G8B8
    4,  // TextureFormat::A8R8G8B8
    4,  // TextureFormat::A8B8G8R8
    2,  // TextureFormat::L16
    4,  // TextureFormat::G16R16
    8,  // TextureFormat::A16B16G16R16
    2,  // TextureFormat::R16F
    4,  // TextureFormat::G16R16F
    8,  // TextureFormat::A16B16G16R16F
    4,  // TextureFormat::R32F
    8,  // TextureFormat::G32R32F
    16,  // TextureFormat::A32B32G32R32F,
    0,  // TextureFormat::DXT1 (特殊处理)
    0,  // TextureFormat::DXT3 (特殊处理)
    0,  // TextureFormat::DXT5 (特殊处理)
    4  // TextureFormat::D24S8
};

std::array<bool, System::EnumCastUnderlying(Rendering::TextureFormat::Quantity)> Rendering::TextureImpl::mipmapable{
    false,  // TextureFormat::None
    true,  // TextureFormat::R5G6B5
    true,  // TextureFormat::A1R5G5B5
    true,  // TextureFormat::A4R4G4B4
    true,  // TextureFormat::A8
    true,  // TextureFormat::L8
    true,  // TextureFormat::A8L8
    true,  // TextureFormat::R8G8B8
    true,  // TextureFormat::A8R8G8B8
    true,  // TextureFormat::A8B8G8R8
    true,  // TextureFormat::L16
    true,  // TextureFormat::G16R16
    true,  // TextureFormat::A16B16G16R16
    true,  // TextureFormat::R16F
    true,  // TextureFormat::G16R16F
    true,  // TextureFormat::A16B16G16R16F
    false,  // TextureFormat::R32F
    false,  // TextureFormat::G32R32F
    false,  // TextureFormat::A32B32G32R32F,
    true,  // TextureFormat::DXT1 (特殊处理)
    true,  // TextureFormat::DXT3 (特殊处理)
    true,  // TextureFormat::DXT5 (特殊处理)
    false  // TextureFormat::D24S8
};

std::array<int, System::EnumCastUnderlying(Rendering::TextureFormat::Quantity)> Rendering::TextureImpl::itemSize{
    0,  // TextureFormat::None
    2,  // TextureFormat::R5G6B5
    2,  // TextureFormat::A1R5G5B5
    2,  // TextureFormat::A4R4G4B4
    1,  // TextureFormat::A8
    1,  // TextureFormat::L8
    1,  // TextureFormat::A8L8
    1,  // TextureFormat::R8G8B8
    1,  // TextureFormat::A8R8G8B8
    1,  // TextureFormat::A8B8G8R8
    2,  // TextureFormat::L16
    2,  // TextureFormat::G16R16
    2,  // TextureFormat::A16B16G16R16
    2,  // TextureFormat::R16F
    2,  // TextureFormat::G16R16F
    2,  // TextureFormat::A16B16G16R16F
    4,  // TextureFormat::R32F
    4,  // TextureFormat::G32R32F
    4,  // TextureFormat::A32B32G32R32F,
    1,  // TextureFormat::DXT1
    1,  // TextureFormat::DXT3
    1,  // TextureFormat::DXT5
    4  // TextureFormat::D24S8
};

Rendering::TextureImpl::TextureImpl(TextureFormat format, TextureFlags type, BufferUsage usage, int numLevels)
    : textureData{ format, type, usage, numLevels }, textureUserField{}, data{ CalculateItemSize(format) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, TextureImpl)

Rendering::TextureFormat Rendering::TextureImpl::GetFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.GetFormat();
}

Rendering::TextureFlags Rendering::TextureImpl::GetTextureType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.GetTextureType();
}

Rendering::BufferUsage Rendering::TextureImpl::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.GetUsage();
}

int Rendering::TextureImpl::GetNumLevels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.GetNumLevels();
}

int Rendering::TextureImpl::GetPixelSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto format = GetFormat();

    return GetPixelSize(format);
}

// static
int Rendering::TextureImpl::GetPixelSize(TextureFormat format)
{
    return pixelSize.at(System::EnumCastUnderlying(format));
}

bool Rendering::TextureImpl::IsCompressed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureData.IsCompressed();
}

bool Rendering::TextureImpl::IsMipmapable() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto format = GetFormat();

    return mipmapable.at(System::EnumCastUnderlying(format));
}

const char* Rendering::TextureImpl::GetReadOnlyData() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return data.GetReadOnlyData();
}

char* Rendering::TextureImpl::GetWriteData()
{
    RENDERING_CLASS_IS_VALID_9;

    return data.GetWriteData();
}

void Rendering::TextureImpl::SetUserField(int index, int userField)
{
    RENDERING_CLASS_IS_VALID_9;

    return textureUserField.SetUserField(index, userField);
}

int Rendering::TextureImpl::GetUserField(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureUserField.GetUserField(index);
}

void Rendering::TextureImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    textureData.Load(source);

    LoadLevelData(source);

    textureUserField.Load(source);

    data.Load(source);
}

void Rendering::TextureImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    textureData.Save(target);

    SaveLevelData(target);

    textureUserField.Save(target);

    data.Save(target);
}

int Rendering::TextureImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = textureData.GetStreamingSize();

    size += GetLevelDataStreamingSize();
    size += textureUserField.GetStreamingSize();
    size += data.GetStreamingSize();

    return size;
}

// protected
void Rendering::TextureImpl::SetNumLevels(int numLevels) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    textureData.SetNumLevels(numLevels);
}

// static
int Rendering::TextureImpl::CalculateNumDimensions(TextureFlags type)
{
    return numDimensions.at(System::EnumCastUnderlying(type));
}

void Rendering::TextureImpl::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    textureData.SaveToFile(outFile);
    SaveLevelDataToFile(outFile);
    textureUserField.SaveToFile(outFile);
    data.SaveToFile(outFile);
}

void Rendering::TextureImpl::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    // 已在LoadTexture读取
    // textureData.ReadFromFile(inFile);
    // LoadLevelDataFromFile(inFile);

    textureUserField.ReadFromFile(inFile);

    const auto numTotalBytes = GetNumTotalBytes();
    data.Reset(numTotalBytes);
    data.ReadFromFile(inFile);
}

void Rendering::TextureImpl::ExpandFileBufferSize()
{
    const auto numTotalBytes = GetNumTotalBytes();
    const auto numLevel0Bytes = GetNumLevelBytes(0);
    data.ExpandFileBufferSize(numTotalBytes, numLevel0Bytes);
}

void Rendering::TextureImpl::ExpandFileBufferSizeOnCube()
{
    const auto numTotalBytes = GetNumTotalBytes();
    const auto numLevel0Bytes = GetNumLevelBytes(0);
    data.ExpandFileBufferSizeOnCube(numTotalBytes, numLevel0Bytes);
}

void Rendering::TextureImpl::GenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_9;

    RecomputationLevelBytes();
    DoGenerateMipmaps();
}

bool Rendering::TextureImpl::HasMipmaps() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetNumLevels() == GetMaxLevels();
}

void Rendering::TextureImpl::RecomputationLevelBytes()
{
    const auto maxLevels = GetMaxLevels();
    const auto numLevels = GetNumLevels();
    if (numLevels != maxLevels)
    {
        SetNumLevels(maxLevels);
        VerifyNumLevels();
        ComputeNumLevelBytes();
        ExpandFileBufferSize();
    }
}

// static
int Rendering::TextureImpl::CalculateItemSize(TextureFormat format)
{
    return itemSize.at(System::EnumCastUnderlying(format));
}

// protected
void Rendering::TextureImpl::ResetTextureBufferNum()
{
    const auto numTotalBytes = GetNumTotalBytes();
    data.Reset(numTotalBytes);
}
