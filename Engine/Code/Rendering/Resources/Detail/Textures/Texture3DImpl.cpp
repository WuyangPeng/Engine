///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/15 15:05)

#include "Rendering/RenderingExport.h"

#include "Texture3DImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/TextureLevelDataDetail.h"

#include <vector>

using std::vector;

Rendering::Texture3DImpl::Texture3DImpl(DataFormatType format, int width, int height, int thickness, bool hasMipmaps)
    : ParentType{ format, GetNumLevels(width, height, thickness, hasMipmaps) },
      textureLevelData{ 1, width, height, thickness, hasMipmaps, GetTotalElements(1, width, height, thickness, hasMipmaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < width, "width 必须是正数\n");
    RENDERING_ASSERTION_0(0 < height, "height 必须是正数\n");
    RENDERING_ASSERTION_0(0 < thickness, "thickness 必须是正数\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture3DImpl::Texture3DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ DataFormatType::Unknown, 0 }, textureLevelData{ 1, 0, 0, 0, false, 0, 1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture3DImpl)

int Rendering::Texture3DImpl::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems();
}

int Rendering::Texture3DImpl::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index);
}

int Rendering::Texture3DImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::Texture3DImpl::GetDimension(int level, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(level, index);
}

int Rendering::Texture3DImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::Texture3DImpl::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(item, level);
}

bool Rendering::Texture3DImpl::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.HasMipmaps();
}

int Rendering::Texture3DImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

int Rendering::Texture3DImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 1);
}

int Rendering::Texture3DImpl::GetThickness() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 2);
}

void Rendering::Texture3DImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::Texture3DImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::Texture3DImpl::GetLevelDataStreamingSize() const
{
    return textureLevelData.GetStreamingSize();
}

void Rendering::Texture3DImpl::SaveLevelDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    textureLevelData.SaveToFile(outFile);
}

void Rendering::Texture3DImpl::LoadLevelDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    textureLevelData.ReadFromFile(inFile);
}

void Rendering::Texture3DImpl::AutogenerateMipmaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return textureLevelData.AutogenerateMipmaps();
}

bool Rendering::Texture3DImpl::WantAutogenerateMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.WantAutogenerateMipmaps();
}

int Rendering::Texture3DImpl::GetNumSubresources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems() * GetNumLevels();
}

int Rendering::Texture3DImpl::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (textureLevelData.GetNumItems() <= item || GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"));
    }

    return GetNumLevels() * item + level;
}

void Rendering::Texture3DImpl::SaveBaseToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto dataFormatType = GetFormat();
    outFile.Write(sizeof(DataFormatType), &dataFormatType);

    const auto dimension0 = GetDimension(0);
    outFile.Write(sizeof(int32_t), &dimension0);

    const auto dimension1 = GetDimension(1);
    outFile.Write(sizeof(int32_t), &dimension1);

    const auto dimension2 = GetDimension(2);
    outFile.Write(sizeof(int32_t), &dimension2);

    const auto hasMipmaps = HasMipmaps();
    outFile.Write(sizeof(bool), &hasMipmaps);

    const auto numItems = GetNumItems();
    outFile.Write(sizeof(int32_t), &numItems);
}