///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
///	ÁªÏµ×÷Õß£º94458936@qq.com
///
///	±ê×¼£ºstd:c++20
///	ÒýÇæ°æ±¾£º0.8.1.0 (2022/08/13 13:33)

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

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData() noexcept
    : numItems{ 1 },
      levelDimension{},
      levelNumBytes{},
      levelOffsets{},
      hasMipmaps{ false },
      autogenerateMipmaps{ false }
{
    static_assert(NumDimensions == 1, "NumDimensions must be 1.");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData(int numItems, int dimension0, bool hasMipmaps, int elementSize, int numLevels)
    : numItems{ numItems },
      levelDimension{},
      levelNumBytes{},
      levelOffsets(numItems),
      hasMipmaps{ hasMipmaps },
      autogenerateMipmaps{ false }
{
    static_assert(NumDimensions == 1, "NumDimensions must be 1.");

    Init(dimension0, 1, 1, elementSize, numLevels);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData(int numItems, int dimension0, int dimension1, bool hasMipmaps, int elementSize, int numLevels)
    : numItems{ numItems },
      levelDimension{},
      levelNumBytes{},
      levelOffsets(numItems),
      hasMipmaps{ hasMipmaps },
      autogenerateMipmaps{ false }
{
    static_assert(NumDimensions == 2, "NumDimensions must be 2.");

    Init(dimension0, dimension1, 1, elementSize, numLevels);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <int NumDimensions>
Rendering::TextureLevelData<NumDimensions>::TextureLevelData(int numItems, int dimension0, int dimension1, int dimension2, bool hasMipmaps, int elementSize, int numLevels)
    : numItems{ numItems },
      levelDimension{},
      levelNumBytes{},
      levelOffsets(numItems),
      hasMipmaps{ hasMipmaps },
      autogenerateMipmaps{ false }
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

    if (hasMipmaps)
    {
        for (auto level = 1; level < numLevels; ++level)
        {
            if (dimension0 > 1)
            {
                dimension0 >>= 1;
            }

            if (dimension1 > 1)
            {
                dimension1 >>= 1;
            }

            if (dimension2 > 1)
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

        InitLevelOffsetsHasMipmaps(numLevels);
    }
    else
    {
        InitLevelOffsetsNoMipmaps(numLevels);
    }
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::InitLevelOffsetsHasMipmaps(int numLevels)
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
void Rendering::TextureLevelData<NumDimensions>::InitLevelOffsetsNoMipmaps(int numLevels)
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
bool Rendering::TextureLevelData<NumDimensions>::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return hasMipmaps;
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
void Rendering::TextureLevelData<NumDimensions>::Load(CoreTools::BufferSource& source)
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

    hasMipmaps = source.ReadBool();
    autogenerateMipmaps = source.ReadBool();
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::Save(CoreTools::BufferTarget& target) const
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

    target.Write(hasMipmaps);
    target.Write(autogenerateMipmaps);
}

template <int NumDimensions>
int Rendering::TextureLevelData<NumDimensions>::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(numItems);

    for (auto& value : levelDimension)
    {
        size += CORE_TOOLS_STREAM_SIZE(value);
    }

    size += CORE_TOOLS_STREAM_SIZE(levelNumBytes);

    const auto elementsNumber = boost::numeric_cast<int32_t>(levelOffsets.size());

    size += CORE_TOOLS_STREAM_SIZE(elementsNumber);

    for (const auto& levelOffset : levelOffsets)
    {
        size += CORE_TOOLS_STREAM_SIZE(levelOffset);
    }

    size += CORE_TOOLS_STREAM_SIZE(hasMipmaps);
    size += CORE_TOOLS_STREAM_SIZE(autogenerateMipmaps);

    return size;
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    outFile.Write(sizeof(int32_t), &numItems);
    for (auto& value : levelDimension)
    {
        outFile.Write(sizeof(int32_t), value.size(), value.data());
    }
    outFile.Write(sizeof(int32_t), levelNumBytes.size(), levelNumBytes.data());
    const auto elementsNumber = boost::numeric_cast<int32_t>(levelOffsets.size());
    outFile.Write(sizeof(int32_t), &elementsNumber);

    for (auto levelOffset : levelOffsets)
    {
        outFile.Write(sizeof(int32_t), levelOffset.size(), levelOffset.data());
    }

    outFile.Write(sizeof(bool), &hasMipmaps);
    outFile.Write(sizeof(bool), &autogenerateMipmaps);
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    inFile.Read(sizeof(int32_t), &numItems);

    for (auto& value : levelDimension)
    {
        inFile.Read(sizeof(int32_t), value.size(), value.data());
    }

    inFile.Read(sizeof(int32_t), levelNumBytes.size(), levelNumBytes.data());

    auto elementsNumber = 0;
    inFile.Read(sizeof(int32_t), &elementsNumber);

    levelOffsets.resize(elementsNumber);

    for (auto levelOffset : levelOffsets)
    {
        inFile.Read(sizeof(int32_t), levelOffset.size(), levelOffset.data());
    }

    inFile.Read(sizeof(bool), &hasMipmaps);
    inFile.Read(sizeof(bool), &autogenerateMipmaps);
}

template <int NumDimensions>
void Rendering::TextureLevelData<NumDimensions>::AutogenerateMipmaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (hasMipmaps)
    {
        autogenerateMipmaps = true;
    }
}

template <int NumDimensions>
bool Rendering::TextureLevelData<NumDimensions>::WantAutogenerateMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return autogenerateMipmaps;
}

#endif  // RENDERING_RESOURCES_TEXTURE_LEVEL_DATA_DETAIL_H
