///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/15 14:55)

#include "Rendering/RenderingExport.h"

#include "Texture2DImpl.h"

#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/TextureLevelDataDetail.h"

#include <vector>

using std::vector;

Rendering::Texture2DImpl::Texture2DImpl(DataFormatType format, int width, int height, bool hasMipmaps)
    : ClassType{ 1, format, width, height, hasMipmaps }
{
    RENDERING_ASSERTION_0(0 < width, "width ����������\n");
    RENDERING_ASSERTION_0(0 < height, "height ����������\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture2DImpl::Texture2DImpl(int numItems, DataFormatType format, int width, int height, bool hasMipmaps)
    : ParentType{ format, GetNumLevels(width, height, 1, hasMipmaps) },
      textureLevelData{ numItems, width, height, hasMipmaps, GetTotalElements(1, width, height, 1, hasMipmaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < width, "width ����������\n");
    RENDERING_ASSERTION_0(0 < height, "height ����������\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture2DImpl::Texture2DImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ DataFormatType::Unknown, 1 },
      textureLevelData{ 1, 0, 0, false, 0, 1 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture2DImpl)

int Rendering::Texture2DImpl::GetNumItems() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems();
}

int Rendering::Texture2DImpl::GetNumDimensions() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumDimensions();
}

int Rendering::Texture2DImpl::GetDimension(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(index);
}

int Rendering::Texture2DImpl::GetDimension(int level, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetDimension(level, index);
}

int Rendering::Texture2DImpl::GetNumLevelBytes(int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumLevelBytes(level);
}

int Rendering::Texture2DImpl::GetLevelOffset(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetLevelOffset(item, level);
}

bool Rendering::Texture2DImpl::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.HasMipmaps();
}

int Rendering::Texture2DImpl::GetWidth() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 0);
}

int Rendering::Texture2DImpl::GetHeight() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GetDimension(0, 1);
}

void Rendering::Texture2DImpl::LoadLevelData(CoreTools::BufferSource& source)
{
    textureLevelData.Load(source);
}

void Rendering::Texture2DImpl::SaveLevelData(CoreTools::BufferTarget& target) const
{
    textureLevelData.Save(target);
}

int Rendering::Texture2DImpl::GetLevelDataStreamingSize() const
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

void Rendering::Texture2DImpl::AutogenerateMipmaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return textureLevelData.AutogenerateMipmaps();
}

bool Rendering::Texture2DImpl::WantAutogenerateMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.WantAutogenerateMipmaps();
}

int Rendering::Texture2DImpl::GetNumSubresources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems() * GetNumLevels();
}

int Rendering::Texture2DImpl::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (textureLevelData.GetNumItems() <= item || GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ч���롣"));
    }

    return GetNumLevels() * item + level;
}

void Rendering::Texture2DImpl::SaveBaseToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto dataFormatType = GetFormat();
    outFile.Write(sizeof(DataFormatType), &dataFormatType);

    const auto dimension0 = GetDimension(0);
    outFile.Write(sizeof(int32_t), &dimension0);

    const auto dimension1 = GetDimension(1);
    outFile.Write(sizeof(int32_t), &dimension1);

    const auto hasMipmaps = HasMipmaps();
    outFile.Write(sizeof(bool), &hasMipmaps);

    const auto numItems = GetNumItems();
    outFile.Write(sizeof(int32_t), &numItems);
}