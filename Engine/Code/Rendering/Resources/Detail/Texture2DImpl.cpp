///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 11:14)

#include "Rendering/RenderingExport.h"

#include "Texture2DImpl.h"

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

Rendering::Texture2DImpl::Texture2DImpl(TextureFormat format, int dimension0, int dimension1, int numLevels, BufferUsage usage)
    : ParentType{ format, TextureFlags::Texture2D, usage, numLevels }, textureLevelData{ CalculateNumDimensions(TextureFlags::Texture2D) }
{
    RENDERING_ASSERTION_0(0 < dimension0, "Dimension0 必须是正数\n");
    RENDERING_ASSERTION_0(0 < dimension1, "Dimension1 必须是正数\n");

    ResetDimension(dimension0, dimension1);
    VerifyNumLevels();
    ComputeNumLevelBytes();
    ResetTextureBufferNum();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture2DImpl::Texture2DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ TextureFormat::A8R8G8B8, TextureFlags::Texture2D, BufferUsage::Texture, 0 }, textureLevelData{ CalculateNumDimensions(TextureFlags::Texture2D) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::Texture2DImpl::ResetDimension(int dimension0, int dimension1)
{
    textureLevelData.SetDimension(0, 0, dimension0);
    textureLevelData.SetDimension(1, 0, dimension1);

    const auto maxLevels = GetMaxLevels();
    const auto numLevels = GetNumLevels();

    RENDERING_ASSERTION_0(0 <= numLevels && numLevels <= maxLevels, "numLevels无效！\n");

    if (numLevels == 0)
    {
        // 用户希望的最大数量的级别。
        SetNumLevels(maxLevels);
    }
}

int Rendering::Texture2DImpl::GetMaxLevels() const
{
    const auto logDimension0 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetWidth());
    const auto logDimension1 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetHeight());
    const auto maxLevels = logDimension0 <= logDimension1 ? logDimension1 + 1 : logDimension0 + 1;

    return maxLevels;
}

// private
void Rendering::Texture2DImpl::ComputeNumLevelBytes()
{
    const auto type = GetTextureType();
    auto dimension0 = GetWidth();
    auto dimension1 = GetHeight();
    const auto numLevels = GetNumLevels();

    for (auto level = 0; level < numLevels; ++level)
    {
        textureLevelData.SetNumLevelBytes(level, CalculateNumLevelBytes(dimension0, dimension1));
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
int Rendering::Texture2DImpl::CalculateNumLevelBytes(int dimension0, int dimension1)
{
    const auto format = GetFormat();

    if (format == TextureFormat::DXT1)
    {
        auto max0 = dimension0 / 4;
        if (max0 < 1)
        {
            max0 = 1;
        }
        int max1 = dimension1 / 4;
        if (max1 < 1)
        {
            max1 = 1;
        }

        return 8 * max0 * max1;
    }
    else if (format == TextureFormat::DXT3 || format == TextureFormat::DXT5)
    {
        auto max0 = dimension0 / 4;
        if (max0 < 1)
        {
            max0 = 1;
        }
        auto max1 = dimension1 / 4;
        if (max1 < 1)
        {
            max1 = 1;
        }

        return 16 * max0 * max1;
    }
    else
    {
        return GetPixelSize(format) * dimension0 * dimension1;
    }
}

// private
void Rendering::Texture2DImpl::VerifyNumLevels()
{
    const auto format = GetFormat();
    const auto numLevels = GetNumLevels();

    if (format == TextureFormat::R32F || format == TextureFormat::G32R32F || format == TextureFormat::A32B32G32R32F)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_1(false, "对于32位float纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
    else if (format == TextureFormat::D24S8)
    {
        if (1 < numLevels)
        {
            RENDERING_ASSERTION_0(false, "深度纹理没有mipmaps\n");
            SetNumLevels(1);
        }
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2DImpl)

int Rendering::Texture2DImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::Texture2DImpl::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index, level);
}

int Rendering::Texture2DImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::Texture2DImpl::GetNumTotalBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumTotalBytes();
}

int Rendering::Texture2DImpl::GetLevelOffset(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(level);
}

int Rendering::Texture2DImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

int Rendering::Texture2DImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(1, 0);
}

void Rendering::Texture2DImpl::DoGenerateMipmaps()
{
    const auto numLevels = GetNumLevels();
    auto width = GetWidth();
    auto height = GetHeight();
    auto texels = GetWriteData();
    for (auto level = 1; level < numLevels; ++level)
    {
        auto texelsNext = GetTextureData(level);
        const auto widthNext = GetDimension(0, level);
        const auto heightNext = GetDimension(1, level);

        GenerateNextMipmap(width, height, texels, widthNext, heightNext, texelsNext);

        width = widthNext;
        height = heightNext;
        texels = texelsNext;
    }
}

char* Rendering::Texture2DImpl::GetTextureData(int level)
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetData\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<char*>(static_cast<const ClassType*>(this)->GetTextureData(level));

#include STSTEM_WARNING_POP
}

const char* Rendering::Texture2DImpl::GetTextureData(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetTextureData\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return GetReadOnlyData() + GetLevelOffset(level);

#include STSTEM_WARNING_POP
}

void Rendering::Texture2DImpl::GenerateNextMipmap(int width, int height, const char* texels, int widthNext, int heightNext, char* texelsNext)
{
    if (texelsNext == nullptr)
    {
        return;
    }

    // 用于临时存储生成的mipmaps。

    const auto format = GetFormat();

    // 像素从原生格式转换为32位RGBA。
    auto fromFunction = ColourConvertFrom::GetConvertFromFunction(format);

    // 像素从32位RGBA纹理转换为本机格式。
    auto toFunction = ColourConvertTo::GetConvertToFunction(format);

    if (fromFunction != nullptr && toFunction != nullptr)
    {
        const auto numTexels = width * height;
        vector<char> fromVector{};
        for (auto i = 0; i < numTexels; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            fromVector.emplace_back(*(texels + i));

#include STSTEM_WARNING_POP
        }

        auto colour = fromFunction(fromVector);

        // 就地创建下一个miplevel。
        for (auto heightIndex = 0; heightIndex < heightNext; ++heightIndex)
        {
            for (auto widthIndex = 0; widthIndex < widthNext; ++widthIndex)
            {
                const auto index = widthIndex + widthNext * heightIndex;
                const auto base = 2 * (widthIndex + width * heightIndex);
                const auto nextBase = base + 1;
                const auto nextBaseWidth = base + width;
                const size_t fourthIndex = boost::numeric_cast<size_t>(base + width + 1);

                if (fourthIndex < colour.size())
                {
                    colour.at(index) = 0.25f * colour.at(base) + 0.25f * colour.at(nextBase) + 0.25f * colour.at(nextBaseWidth) + 0.25f * colour.at(fourthIndex);
                }
                else
                {
                    colour.at(index) = 0.5f * colour.at(base) + 0.5f * colour.at(nextBase);
                }
            }
        }

        const auto numTexelsNext = widthNext * heightNext;

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

void Rendering::Texture2DImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::Texture2DImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::Texture2DImpl::GetLevelDataStreamingSize() const noexcept
{
    return textureLevelData.GetStreamingSize();
}

void Rendering::Texture2DImpl::SaveLevelDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    textureLevelData.SaveToFile(outFile);
}

void Rendering::Texture2DImpl::LoadLevelDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    textureLevelData.ReadFromFile(inFile);
}
