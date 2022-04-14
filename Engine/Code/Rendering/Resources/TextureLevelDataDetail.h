///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:11)

#ifndef RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H
#define RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "TextureLevelData.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <int WindowSize>
Rendering::TextureLevelData<WindowSize>::TextureLevelData(int numDimensions) noexcept
    : numDimensions{ numDimensions }, dimension{}, numLevelBytes{}, numTotalBytes{ 0 }, levelOffsets{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <int WindowSize>
bool Rendering::TextureLevelData<WindowSize>::IsValid() const noexcept
{
    if (0 <= numTotalBytes && numDimensions == WindowSize)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numDimensions;
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>::GetDimension(int index, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < WindowSize && 0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");

    return dimension.at(index).at(level);
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::SetDimension(int index, int level, int aDimension)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= index && index < WindowSize && 0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");

    if (0 <= index && index < WindowSize && 0 <= level && level < TextureMaximumMipmapLevels)
    {
        dimension.at(index).at(level) = aDimension;
    }
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");

    return numLevelBytes.at(level);
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>::GetNumTotalBytes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numTotalBytes;
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>::GetLevelOffset(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");

    return levelOffsets.at(level);
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::SetNumLevelBytes(int level, int aNumLevelBytes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= level && level < TextureMaximumMipmapLevels, "索引错误！");

    if (0 <= level && level < TextureMaximumMipmapLevels)
    {
        numLevelBytes.at(level) = aNumLevelBytes;
    }
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::RecountNumTotalBytes(int numLevels, TextureFlags type) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    numTotalBytes = 0;
    for (auto level = 0; level < numLevels; ++level)
    {
        numTotalBytes += numLevelBytes.at(level);
    }

    if (type == TextureFlags::TextureCube)
    {
        numTotalBytes *= 6;
    }
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::RecountLevelOffsets(int numLevels) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    levelOffsets.at(0) = 0;
    for (auto level = 0; level < numLevels - 1; ++level)
    {
        const auto nextLevel = level + 1;
        levelOffsets.at(nextLevel) = levelOffsets.at(level) + numLevelBytes.at(level);
    }
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numDimensions);

    for (auto i = 0; i < WindowSize; ++i)
    {
        source.ReadContainer(dimension.at(i));
    }

    source.ReadContainer(numLevelBytes);
    source.Read(numTotalBytes);
    source.ReadContainer(levelOffsets);
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numDimensions);

    for (auto i = 0; i < WindowSize; ++i)
    {
        target.WriteContainer(dimension.at(i));
    }

    target.WriteContainer(numLevelBytes);
    target.Write(numTotalBytes);
    target.WriteContainer(levelOffsets);
}

template <int WindowSize>
int Rendering::TextureLevelData<WindowSize>::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(numDimensions);

    size += WindowSize * TextureMaximumMipmapLevels * CORE_TOOLS_STREAM_SIZE(dimension.at(0).at(0));
    size += TextureMaximumMipmapLevels * CORE_TOOLS_STREAM_SIZE(numLevelBytes.at(0));
    size += CORE_TOOLS_STREAM_SIZE(numTotalBytes);
    size += TextureMaximumMipmapLevels * CORE_TOOLS_STREAM_SIZE(levelOffsets.at(0));

    return size;
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    outFile.Write(sizeof(int32_t), &numDimensions);

    for (auto i = 0; i < WindowSize; ++i)
    {
        outFile.Write(sizeof(int32_t), TextureMaximumMipmapLevels, dimension.at(i).data());
    }

    outFile.Write(sizeof(int32_t), TextureMaximumMipmapLevels, numLevelBytes.data());
    outFile.Write(sizeof(int32_t), &numTotalBytes);
    outFile.Write(sizeof(int32_t), TextureMaximumMipmapLevels, levelOffsets.data());
}

template <int WindowSize>
void Rendering::TextureLevelData<WindowSize>::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto oldNumDimensions = numDimensions;
    const auto oldNumTotalBytes = numTotalBytes;

    inFile.Read(sizeof(int32_t), &numDimensions);

    for (auto i = 0; i < WindowSize; ++i)
    {
        inFile.Read(sizeof(int32_t), TextureMaximumMipmapLevels, dimension.at(i).data());
    }

    inFile.Read(sizeof(int32_t), TextureMaximumMipmapLevels, numLevelBytes.data());
    inFile.Read(sizeof(int32_t), &numTotalBytes);
    inFile.Read(sizeof(int32_t), TextureMaximumMipmapLevels, levelOffsets.data());

    if (numDimensions != WindowSize || numTotalBytes < 0)
    {
        numDimensions = oldNumDimensions;
        numTotalBytes = oldNumTotalBytes;

        THROW_EXCEPTION(SYSTEM_TEXT("读取的纹理等级数据不正确。\n"s));
    }
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H
