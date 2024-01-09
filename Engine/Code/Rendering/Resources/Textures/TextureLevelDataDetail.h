/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.3 (2023/12/29 13:46)

#ifndef RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H
#define RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H

#include "TextureLevelData.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData() noexcept
    : numItems{ 1 },
      levelDimension{},
      levelNumBytes{},
      levelOffsets{},
      hasMipMaps{ false },
      autoGenerateMipMaps{ false }
{
    static_assert(NumDimensions == 1, "NumDimensions must be 1.");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData(int numItems, int dimension0, bool hasMipMaps, int elementSize, int numLevels)
    : numItems{ numItems },
      levelDimension{},
      levelNumBytes{},
      levelOffsets(numItems),
      hasMipMaps{ hasMipMaps },
      autoGenerateMipMaps{ false }
{
    static_assert(NumDimensions == 1, "NumDimensions must be 1.");

    Init(dimension0, 1, 1, elementSize, numLevels);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData(int numItems, int dimension0, int dimension1, bool hasMipMaps, int elementSize, int numLevels)
    : numItems{ numItems },
      levelDimension{},
      levelNumBytes{},
      levelOffsets(numItems),
      hasMipMaps{ hasMipMaps },
      autoGenerateMipMaps{ false }
{
    static_assert(NumDimensions == 2, "NumDimensions must be 2.");

    Init(dimension0, dimension1, 1, elementSize, numLevels);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData(int numItems, int dimension0, int dimension1, int dimension2, bool hasMipMaps, int elementSize, int numLevels)
    : numItems{ numItems },
      levelDimension{},
      levelNumBytes{},
      levelOffsets(numItems),
      hasMipMaps{ hasMipMaps },
      autoGenerateMipMaps{ false }
{
    static_assert(NumDimensions == 3, "NumDimensions must be 3.");

    Init(dimension0, dimension1, dimension2, elementSize, numLevels);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::Init(int dimension0, int dimension1, int dimension2, int elementSize, int numLevels)
{
    levelDimension.at(0).at(0) = dimension0;

    if constexpr (1 < NumDimensions)
    {
        levelDimension.at(0).at(1) = dimension1;
    }

    if constexpr (2 < NumDimensions)
    {
        levelDimension.at(0).at(2) = dimension2;
    }

    levelNumBytes.at(0) = dimension0 * dimension1 * dimension2 * elementSize;

    if (hasMipMaps)
    {
        for (auto level = 1; level < numLevels; ++level)
        {
            if (1 < dimension0)
            {
                dimension0 >>= 1;
            }

            if (1 < dimension1)
            {
                dimension1 >>= 1;
            }

            if (1 < dimension2)
            {
                dimension2 >>= 1;
            }

            levelNumBytes.at(level) = dimension0 * dimension1 * dimension2 * elementSize;
            levelDimension.at(level).at(0) = dimension0;

            if constexpr (1 < NumDimensions)
            {
                levelDimension.at(level).at(1) = dimension1;
            }

            if constexpr (2 < NumDimensions)
            {
                levelDimension.at(level).at(2) = dimension2;
            }
        }

        InitLevelOffsetsHasMipMaps(numLevels);
    }
    else
    {
        InitLevelOffsetsNoMipMaps(numLevels);
    }
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::InitLevelOffsetsHasMipMaps(int numLevels)
{
    auto numBytes = 0;
    for (auto item = 0; item < numItems; ++item)
    {
        for (auto level = 0; level < numLevels; ++level)
        {
            levelOffsets.at(item).at(level) = numBytes;
            numBytes += levelNumBytes.at(level);
        }
    }
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::InitLevelOffsetsNoMipMaps(int numLevels)
{
    const auto levelNumByte = levelNumBytes.at(0);

    for (auto item = 1; item < numLevels; ++item)
    {
        levelOffsets.at(item).at(0) = item * levelNumByte;
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <int NumDimensions>
bool Rendering::TextureLevelData<NumDimensions>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return numItems;
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return NumDimensions;
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, index);
}

template <int NumDimensions>
bool Rendering::TextureLevelData<NumDimensions>::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return hasMipMaps;
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetDimension(int level, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(0 <= index && index < NumDimensions && 0 <= level && level < textureMaximumMipmapLevels, "Ë÷Òý´íÎó£¡");

    return levelDimension.at(level).at(index);
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(0 <= level && level < textureMaximumMipmapLevels, "Ë÷Òý´íÎó£¡");

    return levelNumBytes.at(level);
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_1(0 <= level && level < textureMaximumMipmapLevels && 0 <= item && item < numItems, "Ë÷Òý´íÎó£¡");

    return levelOffsets.at(item).at(level);
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::SetDimension(int level, int index, int dimension)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(0 <= index && index < NumDimensions && 0 <= level && level < textureMaximumMipmapLevels, "Ë÷Òý´íÎó£¡");

    levelDimension.at(level).at(index) = dimension;
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::SetNumLevelBytes(int level, int aNumLevelBytes)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_1(0 <= level && level < textureMaximumMipmapLevels, "Ë÷Òý´íÎó£¡");

    levelNumBytes.at(level) = aNumLevelBytes;
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(numItems);
    for (auto& value : levelDimension)
    {
        source.ReadContainer(value);
    }

    source.ReadContainer(levelNumBytes);

    const auto elementsNumber = source.Read<int32_t>();
    for (auto i = 0; i < elementsNumber; ++i)
    {
        LevelOffsetsType levelOffset{};
        source.ReadContainer(levelOffset);
        levelOffsets.emplace_back(levelOffset);
    }

    hasMipMaps = source.ReadBool();
    autoGenerateMipMaps = source.ReadBool();
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(numItems);
    for (auto& value : levelDimension)
    {
        target.WriteContainer(value);
    }

    target.WriteContainer(levelNumBytes);

    const auto elementsNumber = boost::numeric_cast<int32_t>(levelOffsets.size());
    target.Write(elementsNumber);

    for (const auto& levelOffset : levelOffsets)
    {
        target.WriteContainer(levelOffset);
    }

    target.Write(hasMipMaps);
    target.Write(autoGenerateMipMaps);
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(numItems);

    for (auto& value : levelDimension)
    {
        size += CoreTools::GetStreamSize(value);
    }

    size += CoreTools::GetStreamSize(levelNumBytes);

    const auto elementsNumber = boost::numeric_cast<int32_t>(levelOffsets.size());

    size += CoreTools::GetStreamSize(elementsNumber);

    for (const auto& levelOffset : levelOffsets)
    {
        size += CoreTools::GetStreamSize(levelOffset);
    }

    size += CoreTools::GetStreamSize(hasMipMaps);
    size += CoreTools::GetStreamSize(autoGenerateMipMaps);

    return size;
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (hasMipMaps)
    {
        autoGenerateMipMaps = true;
    }
}

template <int NumDimensions>
bool Rendering::TextureLevelData<NumDimensions>::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return autoGenerateMipMaps;
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H
