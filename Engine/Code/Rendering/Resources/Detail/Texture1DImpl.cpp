///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 10:33)

#include "Rendering/RenderingExport.h"

#include "Texture1DImpl.h"
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

Rendering::Texture1DImpl::Texture1DImpl(TextureFormat format, int dimension0, int numLevels, BufferUsage usage)
    : ParentType{ format, TextureFlags::Texture1D, usage, numLevels }, textureLevelData{ CalculateNumDimensions(TextureFlags::Texture1D) }
{
    RENDERING_ASSERTION_0(0 < dimension0, "Dimension0 必须是正数\n");

    ResetDimension(dimension0);
    VerifyNumLevels();
    ComputeNumLevelBytes();
    ResetTextureBufferNum();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture1DImpl::Texture1DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ TextureFormat::A8R8G8B8, TextureFlags::Texture1D, BufferUsage::Texture, 0 },
      textureLevelData{ CalculateNumDimensions(TextureFlags::Texture1D) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

// private
void Rendering::Texture1DImpl::ResetDimension(int dimension0)
{
    textureLevelData.SetDimension(0, 0, dimension0);

    const auto maxLevels = GetMaxLevels();
    const auto numLevels = GetNumLevels();

    RENDERING_ASSERTION_0(0 <= numLevels && numLevels <= maxLevels, "numLevels无效！\n");

    if (numLevels == 0)
    {
        // 用户希望的最大数量的级别。
        SetNumLevels(maxLevels);
    }
}

int Rendering::Texture1DImpl::GetMaxLevels() const
{
    const auto logDimension0 = Mathematics::BitHacks::Log2OfPowerOfTwo(GetLength());
    const auto maxLevels = logDimension0 + 1;

    return maxLevels;
}

// private
void Rendering::Texture1DImpl::ComputeNumLevelBytes()
{
    const auto format = GetFormat();
    const auto type = GetTextureType();
    auto dimension0 = GetLength();
    const auto numLevels = GetNumLevels();

    for (auto level = 0; level < numLevels; ++level)
    {
        textureLevelData.SetNumLevelBytes(level, GetPixelSize(format) * dimension0);
        textureLevelData.SetDimension(0, level, dimension0);

        if (1 < dimension0)
        {
            dimension0 >>= 1;
        }
    }

    textureLevelData.RecountNumTotalBytes(numLevels, type);
    textureLevelData.RecountLevelOffsets(numLevels);
}

// private
void Rendering::Texture1DImpl::VerifyNumLevels()
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
    else if (format == TextureFormat::DXT1 || format == TextureFormat::DXT3 || format == TextureFormat::DXT5)
    {
        RENDERING_ASSERTION_1(false, "对于1D纹理没有DXT压缩\n");
        SetNumLevels(1);
    }
    else if (format == TextureFormat::D24S8)
    {
        RENDERING_ASSERTION_1(false, "深度纹理必须是2D的\n");
        SetNumLevels(1);
    }
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture1DImpl)

int Rendering::Texture1DImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::Texture1DImpl::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index, level);
}

int Rendering::Texture1DImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::Texture1DImpl::GetNumTotalBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumTotalBytes();
}

int Rendering::Texture1DImpl::GetLevelOffset(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(level);
}

int Rendering::Texture1DImpl::GetLength() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

void Rendering::Texture1DImpl::DoGenerateMipmaps()
{
    const auto numLevels = GetNumLevels();
    auto length = GetLength();
    auto texels = GetWriteData();
    for (auto level = 1; level < numLevels; ++level)
    {
        auto texelsNext = GetTextureData(level);
        const auto lengthNext = GetDimension(0, level);

        GenerateNextMipmap(length, texels, lengthNext, texelsNext);

        length = lengthNext;
        texels = texelsNext;
    }
}

char* Rendering::Texture1DImpl::GetTextureData(int level)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetTextureData\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return GetWriteData() + GetLevelOffset(level);

#include STSTEM_WARNING_POP
}

const char* Rendering::Texture1DImpl::GetTextureData(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= level && level < GetNumLevels(), "无效等级在GetTextureData\n");

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return GetReadOnlyData() + GetLevelOffset(level);

#include STSTEM_WARNING_POP
}

void Rendering::Texture1DImpl::GenerateNextMipmap(int length, const char* texels, int lengthNext, char* texelsNext)
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
        vector<char> fromVector{};  // 复制texels数组
        for (auto i = 0; i < length; ++i)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            fromVector.emplace_back(*(texels + i));

#include STSTEM_WARNING_POP
        }

        auto colour = fromFunction(fromVector);

        // 就地创建下一个miplevel。
        for (auto index = 0; index < lengthNext; ++index)
        {
            const auto base = 2 * index;
            const auto nextBase = base + 1;
            colour.at(index) = 0.5f * colour.at(base) + 0.5f * colour.at(nextBase);
        }

        auto toVector = toFunction(colour);

        for (auto value : toVector)
        {
            *texelsNext = value;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            ++texelsNext;

#include STSTEM_WARNING_POP
        }
    }
}

void Rendering::Texture1DImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::Texture1DImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::Texture1DImpl::GetLevelDataStreamingSize() const noexcept
{
    return textureLevelData.GetStreamingSize();
}

void Rendering::Texture1DImpl::SaveLevelDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.SaveToFile(outFile);
}

void Rendering::Texture1DImpl::LoadLevelDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    return textureLevelData.ReadFromFile(inFile);
}
