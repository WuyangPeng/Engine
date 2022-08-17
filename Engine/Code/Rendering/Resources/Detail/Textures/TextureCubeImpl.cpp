///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/15 15:20)

#include "Rendering/RenderingExport.h"

#include "TextureCubeImpl.h"
#include "CoreTools/FileManager/FileBuffer.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Flags/DataFormatType.h"
#include "Rendering/Resources/Textures/TextureLevelDataDetail.h"

#include <vector>

using std::vector;

Rendering::TextureCubeImpl::TextureCubeImpl(DataFormatType format, int length, bool hasMipmaps)
    : ParentType{ format, GetNumLevels(length, length, 1, hasMipmaps) },
      textureLevelData{ cubeFaceCount, length, length, hasMipmaps, GetTotalElements(cubeFaceCount, length, length, 1, hasMipmaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < length, "length ����������\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureCubeImpl::TextureCubeImpl(int numCubes, DataFormatType format, int length, bool hasMipmaps)
    : ParentType{ format, GetNumLevels(length, length, 1, hasMipmaps) },
      textureLevelData{ numCubes * cubeFaceCount, length, length, hasMipmaps, GetTotalElements(numCubes * cubeFaceCount, length, length, 1, hasMipmaps), GetNumLevels() }
{
    RENDERING_ASSERTION_0(0 < length, "length ����������\n");

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TextureCubeImpl::TextureCubeImpl(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ DataFormatType::Unknown, 0 }, textureLevelData{ cubeFaceCount, 0, 0, false, 0, 1 }
{
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

bool Rendering::TextureCubeImpl::HasMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.HasMipmaps();
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

void Rendering::TextureCubeImpl::AutogenerateMipmaps() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return textureLevelData.AutogenerateMipmaps();
}

bool Rendering::TextureCubeImpl::WantAutogenerateMipmaps() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.WantAutogenerateMipmaps();
}

int Rendering::TextureCubeImpl::GetNumSubresources() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return textureLevelData.GetNumItems() * GetNumLevels();
}

int Rendering::TextureCubeImpl::GetIndex(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (textureLevelData.GetNumItems() <= item || GetNumLevels() <= level)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��Ч���롣"));
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

    const auto hasMipmaps = HasMipmaps();
    outFile.Write(sizeof(bool), &hasMipmaps);

    const auto numItems = GetNumItems();
    outFile.Write(sizeof(int32_t), &numItems);
}