///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:28)

#include "Rendering/RenderingExport.h"

#include "Texture1DImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/TextureLevelDataDetail.h"

#include <vector>

Rendering::Texture1DImpl::Texture1DImpl(DataFormatType format, int length, bool hasMipmaps)
    : ClassType{ 1, format, length, hasMipmaps }
{
    RENDERING_ASSERTION_0(0 < length, "length 必须是正数\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture1DImpl::Texture1DImpl(int numItems, DataFormatType format, int length, bool hasMipmaps)
    : ParentType{ format, GetNumLevels(length, 1, 1, hasMipmaps) },
      textureLevelData{ numItems, length, hasMipmaps, GetTotalElements(1, length, 1, 1, hasMipmaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < length, "length 必须是正数\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture1DImpl::Texture1DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ DataFormatType::Unknown, 1 },
      textureLevelData{ 1, 0, false, 0, 1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture1DImpl)

int Rendering::Texture1DImpl::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems();
}

int Rendering::Texture1DImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::Texture1DImpl::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index);
}

int Rendering::Texture1DImpl::GetDimension(int level, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(level, index);
}

int Rendering::Texture1DImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::Texture1DImpl::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(item, level);
}

bool Rendering::Texture1DImpl::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.HasMipmaps();
}

void Rendering::Texture1DImpl::AutogenerateMipmaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return textureLevelData.AutogenerateMipmaps();
}

bool Rendering::Texture1DImpl::WantAutogenerateMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.WantAutogenerateMipmaps();
}

int Rendering::Texture1DImpl::GetNumSubresources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems() * GetNumLevels();
}

int Rendering::Texture1DImpl::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (textureLevelData.GetNumItems() <= item || GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"));
    }

    return GetNumLevels() * item + level;
}

int Rendering::Texture1DImpl::GetLength() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

void Rendering::Texture1DImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::Texture1DImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::Texture1DImpl::GetLevelDataStreamingSize() const
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

void Rendering::Texture1DImpl::SaveBaseToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto dataFormatType = GetFormat();
    outFile.Write(sizeof(DataFormatType), &dataFormatType);

    const auto dimension0 = GetDimension(0);
    outFile.Write(sizeof(int32_t), &dimension0);

    const auto hasMipmaps = HasMipmaps();
    outFile.Write(sizeof(bool), &hasMipmaps);

    const auto numItems = GetNumItems();
    outFile.Write(sizeof(int32_t), &numItems);
}
