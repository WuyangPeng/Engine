///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 20:19)

#include "Rendering/RenderingExport.h"

#include "TextureCubeImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/TextureLevelDataDetail.h"

#include <vector>

Rendering::TextureCubeImpl::TextureCubeImpl(DataFormatType format, int length, bool hasMipMaps)
    : ParentType{ format, GetNumLevels(length, length, 1, hasMipMaps) },
      textureLevelData{ cubeFaceCount, length, length, hasMipMaps, GetTotalElements(cubeFaceCount, length, length, 1, hasMipMaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < length, "length 必须是正数\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureCubeImpl::TextureCubeImpl(int numCubes, DataFormatType format, int length, bool hasMipMaps)
    : ParentType{ format, GetNumLevels(length, length, 1, hasMipMaps) },
      textureLevelData{ numCubes * cubeFaceCount, length, length, hasMipMaps, GetTotalElements(numCubes * cubeFaceCount, length, length, 1, hasMipMaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < length, "length 必须是正数\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureCubeImpl::TextureCubeImpl(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ DataFormatType::Unknown, 0 }, textureLevelData{ cubeFaceCount, 0, 0, false, 0, 1 }
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureCubeImpl)

int Rendering::TextureCubeImpl::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems();
}

int Rendering::TextureCubeImpl::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index);
}

int Rendering::TextureCubeImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::TextureCubeImpl::GetDimension(int level, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(level, index);
}

int Rendering::TextureCubeImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::TextureCubeImpl::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(item, level);
}

bool Rendering::TextureCubeImpl::HasMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.HasMipMaps();
}

int Rendering::TextureCubeImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

int Rendering::TextureCubeImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 1);
}

void Rendering::TextureCubeImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::TextureCubeImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::TextureCubeImpl::GetLevelDataStreamingSize() const
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

void Rendering::TextureCubeImpl::AutoGenerateMipMaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return textureLevelData.AutoGenerateMipMaps();
}

bool Rendering::TextureCubeImpl::WantAutoGenerateMipMaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.WantAutoGenerateMipMaps();
}

int Rendering::TextureCubeImpl::GetNumSubResources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems() * GetNumLevels();
}

int Rendering::TextureCubeImpl::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (textureLevelData.GetNumItems() <= item || GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"))
    }

    return GetNumLevels() * item + level;
}

void Rendering::TextureCubeImpl::SaveBaseToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto dataFormatType = GetFormat();
    outFile.Write(sizeof(DataFormatType), &dataFormatType);

    const auto dimension0 = GetDimension(0);
    outFile.Write(sizeof(int32_t), &dimension0);

    const auto hasMipMaps = HasMipMaps();
    outFile.Write(sizeof(bool), &hasMipMaps);

    const auto numItems = GetNumItems();
    outFile.Write(sizeof(int32_t), &numItems);
}