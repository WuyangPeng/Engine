///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/15 16:34)

#include "Rendering/RenderingExport.h"

#include "Texture.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Detail/Textures/TextureImpl.h"
#include "Rendering/Resources/Flags/CopyType.h"
#include "Rendering/Resources/Flags/UsageType.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, Texture);
CORE_TOOLS_DEFAULT_OBJECT_LOAD_CONSTRUCTOR_DEFINE(Rendering, Texture);

Rendering::Texture::Texture(int numElements, int elementSize, GraphicsObjectType type)
    : ParentType{ numElements, elementSize, type }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture::Texture(int numElements, int elementSize, const StorageType& storage, GraphicsObjectType type)
    : ParentType{ numElements, elementSize, storage, type }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Texture)

Rendering::Texture::ConstSpanIterator Rendering::Texture::GetDataFor(int item, int level) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto offset = GetLevelOffset(item, level);

    return GetData(offset);
}

Rendering::SubResource Rendering::Texture::GetSubResource(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto numLevels = GetNumLevels();
    const auto item = index / numLevels;
    const auto level = index % numLevels;
    const auto rowPitch = GetDimension(level, 0) * GetElementSize();

    SubResource sr{ item, level, GetDataFor(item, level), rowPitch, GetDimension(level, 1) * rowPitch };

    return sr;
}

Rendering::Texture::SpanIterator Rendering::Texture::GetDataFor(int item, int level)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto offset = GetLevelOffset(item, level);

    return GetData(offset);
}

void Rendering::Texture::SaveTypeToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto type = GetType();

    outFile.Write(sizeof(GraphicsObjectType), &type);
}

void Rendering::Texture::SaveResourceDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto usage = GetUsage();
    const auto copy = GetCopy();
    const auto offset = GetOffset();
    const auto numActiveElements = GetNumActiveElements();

    outFile.Write(sizeof(UsageType), &usage);
    outFile.Write(sizeof(CopyType), &copy);
    outFile.Write(sizeof(int32_t), &offset);
    outFile.Write(sizeof(int32_t), &numActiveElements);
}

void Rendering::Texture::SaveStorageDataToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto textureData = GetData();
    const StorageType storageData{ textureData.GetCurrent(), textureData.GetEnd() };

    outFile.Write(sizeof(char), storageData.size(), storageData.data());
}

void Rendering::Texture::ReadResourceDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    auto usage = UsageType::Immutable;
    auto copy = CopyType::None;
    auto offset = 0;
    auto numActiveElements = 0;

    inFile.Read(sizeof(UsageType), &usage);
    inFile.Read(sizeof(CopyType), &copy);
    inFile.Read(sizeof(int32_t), &offset);
    inFile.Read(sizeof(int32_t), &numActiveElements);

    SetUsage(usage);
    SetCopy(copy);
    SetOffset(offset);
    SetNumActiveElements(numActiveElements);
}

void Rendering::Texture::ReadStorageDataFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    StorageType storageData(GetNumBytes());

    inFile.Read(sizeof(char), storageData.size(), storageData.data());

    SetNewData(storageData);
}
