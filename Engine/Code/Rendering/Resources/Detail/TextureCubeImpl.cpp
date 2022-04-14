///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 14:11)

#include "Rendering/RenderingExport.h"

#include "TextureCubeImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Rendering/DataTypes/ColourConvertFrom.h"
#include "Rendering/DataTypes/ColourConvertTo.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Resources/TextureLevelDataDetail.h"

#include <vector>

using std::vector;

Rendering::TextureCubeImpl::TextureCubeImpl(TextureFormat format, int dimension, int numLevels, BufferUsage usage)
    : ParentType{ format, TextureFlags::TextureCube, usage, numLevels },
      textureLevelData{ CalculateNumDimensions(TextureFlags::TextureCube) }
{
    RENDERING_ASSERTION_0(0 < dimension, "dimension 必须是正数\n");

    ResetDimension(dimension);
    VerifyNumLevels();
    ComputeNumLevelBytes();
    ResetTextureBufferNum();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureCubeImpl::TextureCubeImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ TextureFormat::A8R8G8B8, TextureFlags::TextureCube, BufferUsage::Texture, 0 },
      textureLevelData{ CalculateNumDimensions(TextureFlags::TextureCube) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::TextureCubeImpl::ResetDimension(int dimension)
{
    textureLevelData.SetDimension(0, 0, dimension);
    textureLevelData.SetDimension(1, 0, dimension);

    const auto maxLevels = GetMaxLevels();
    const auto numLevels = GetNumLevels();

    RENDERING_ASSERTION_0(0 <= numLevels && numLevels <= maxLevels, "numLevels无效！\n");

    if (numLevels == 0)
    {
        SetNumLevels(maxLevels);
    }
}

int Rendering::TextureCubeImpl::GetMaxLevels() const
{
    const auto logDimension = Mathematics::BitHacks::Log2OfPowerOfTwo(GetWidth());

    return logDimension + 1;
}

// private
void Rendering::TextureCubeImpl::ComputeNumLevelBytes()
{
    const auto type = GetTextureType();
    auto dimension0 = GetWidth();
    auto dimension1 = GetHeight();
    const auto numLevels = GetNumLevels();

    for (auto level = 0; level < numLevels; ++level)
    {
        textureLevelData.SetNumLevelBytes(level, CalculateNumLevelBytes(dimension0));
        textureLevelData.SetDimension(0, level, dimension0);
        textureLevelData.SetDimension(1, level, dimension1);

        if (1 < dimension0)
        {
            dimension0 >>= 1;
        }

        if (1 < dimension1)
        {
            dimension1 >>= 1;
        }
    }

    textureLevelData.RecountNumTotalBytes(numLevels, type);
    textureLevelData.RecountLevelOffsets(numLevels);
}

// private
int Rendering::TextureCubeImpl::CalculateNumLevelBytes(int dimension)
{
    const auto format = GetFormat();

    if (format == TextureFormat::DXT1)
    {
        auto max0 = dimension / 4;
        if (max0 < 1)
        {
            max0 = 1;
        }
        auto max1 = dimension / 4;
        if (max1 < 1)
        {
            max1 = 1;
        }

        return 8 * max0 * max1;
    }
    else if (format == TextureFormat::DXT3 || format == TextureFormat::DXT5)
    {
        auto max0 = dimension / 4;
        if (max0 < 1)
        {
            max0 = 1;
        }
        auto max1 = dimension / 4;
        if (max1 < 1)
        {
            max1 = 1;
        }

        return 16 * max0 * max1;
    }
    else
    {
        return GetPixelSize(format) * dimension * dimension;
    }
}

// private
void Rendering::TextureCubeImpl::VerifyNumLevels()
{
    const auto format = GetFormat();
    const auto numLevels = GetNumLevels();

    if (format == TextureFormat::R32F || format == TextureFormat::G32R32F || format == TextureFormat::A32B32G32R32F)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_0(false, "对于32位float纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
    else if (format == TextureFormat::D24S8)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_1(false, "深度纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCubeImpl)

int Rendering::TextureCubeImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::TextureCubeImpl::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index, level);
}

int Rendering::TextureCubeImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::TextureCubeImpl::GetNumTotalBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumTotalBytes();
}

int Rendering::TextureCubeImpl::GetLevelOffset(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(level);
}

int Rendering::TextureCubeImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

int Rendering::TextureCubeImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(1, 0);
}

void Rendering::TextureCubeImpl::DoGenerateMipmaps()
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto face = 0; face < 6; ++face)
    {
        const auto numLevels = GetNumLevels();
        auto dimension = GetWidth();

        auto faceOffset = face * GetNumTotalBytes() / 6;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

        auto texels = GetWriteData() + faceOffset;

#include STSTEM_WARNING_POP

        for (auto level = 1; level < numLevels; ++level)
        {
            auto texelsNext = GetTextureData(face, level);
            const auto dimensionNext = GetDimension(0, level);

            GenerateNextMipmap(dimension, texels, dimensionNext, texelsNext);

            dimension = dimensionNext;
            texels = texelsNext;
        }
    }
}

char* Rendering::TextureCubeImpl::GetTextureData(int face, int level)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetData\n");
    RENDERING_ASSERTION_0(0 <= face && face < 6, "无效面在GetData\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<char*>(static_cast<const ClassType*>(this)->GetTextureData(face, level));

#include STSTEM_WARNING_POP
}

const char* Rendering::TextureCubeImpl::GetTextureData(int face, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetData\n");
    RENDERING_ASSERTION_0(0 <= face && face < 6, "无效面在GetData\n");

    const auto faceOffset = face * GetNumTotalBytes() / 6;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return GetReadOnlyData() + faceOffset + GetLevelOffset(level);

#include STSTEM_WARNING_POP
}

void Rendering::TextureCubeImpl::GenerateNextMipmap(int dimension, const char* texels, int dimensionNext, char* texelsNext)
{
    if (texelsNext == nullptr)
    {
        return;
    }

    const auto format = GetFormat();

    auto fromFunction = ColourConvertFrom::GetConvertFromFunction(format);

    auto toFunction = ColourConvertTo::GetConvertToFunction(format);

    if (fromFunction != nullptr && toFunction != nullptr)
    {
        const auto numTexels = dimension * dimension;
        vector<char> fromVector{};
        for (auto i = 0; i < numTexels; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            fromVector.emplace_back(*(texels + i));

#include STSTEM_WARNING_POP
        }
        auto colour = fromFunction(fromVector);

        for (auto heightIndex = 0; heightIndex < dimensionNext; ++heightIndex)
        {
            for (auto widthIndex = 0; widthIndex < dimensionNext; ++widthIndex)
            {
                const auto index = widthIndex + dimensionNext * heightIndex;
                const auto base = 2 * (widthIndex + dimension * heightIndex);
                const auto fourthIndex = base + dimension + 1;
                const auto nextBase = base + 1;
                const auto i0 = base + dimension;

                if (fourthIndex < boost::numeric_cast<int>(colour.size()))
                {
                    colour.at(index) = 0.25f * colour.at(base) +
                                       0.25f * colour.at(nextBase) +
                                       0.25f * colour.at(i0) +
                                       0.25f * colour.at(fourthIndex);
                }
                else
                {
                    colour.at(index) = 0.5f * colour.at(base) +
                                       0.5f * colour.at(nextBase);
                }
            }
        }

        const auto numTexelsNext = dimensionNext * dimensionNext;

        auto result = toFunction(colour);

        for (auto value : result)
        {
            *texelsNext = value;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            ++texelsNext;

#include STSTEM_WARNING_POP
        }
    }
}

void Rendering::TextureCubeImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::TextureCubeImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::TextureCubeImpl::GetLevelDataStreamingSize() const noexcept
{
    return textureLevelData.GetStreamingSize();
}

void Rendering::TextureCubeImpl::SaveLevelDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    textureLevelData.SaveToFile(outFile);
}

void Rendering::TextureCubeImpl::LoadLevelDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    textureLevelData.ReadFromFile(inFile);
}

void Rendering::TextureCubeImpl::ExpandFileBufferSize()
{
    ExpandFileBufferSizeOnCube();
}
