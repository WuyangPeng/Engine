///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:25)

#include "Rendering/RenderingExport.h"

#include "VertexFormatAttribute.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

Rendering::VertexFormatAttribute::VertexFormatAttribute() noexcept
    : dataFormatType{ DataFormatType::Unknown }, semantic{ VertexFormatFlags::Semantic::None }, usageIndex{ 0 }, offset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatAttribute::VertexFormatAttribute(DataFormatType type, Semantic usage, int usageIndex, int offset) noexcept
    : dataFormatType{ type }, semantic{ usage }, usageIndex{ usageIndex }, offset{ offset }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatAttribute)

Rendering::DataFormatType Rendering::VertexFormatAttribute::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dataFormatType;
}

void Rendering::VertexFormatAttribute::SetType(DataFormatType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    dataFormatType = type;
}

Rendering::VertexFormatFlags::Semantic Rendering::VertexFormatAttribute::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return semantic;
}

void Rendering::VertexFormatAttribute::SetUsage(Semantic usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    semantic = usage;
}

int Rendering::VertexFormatAttribute::GetUsageIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return usageIndex;
}

void Rendering::VertexFormatAttribute::SetUsageIndex(int aUsageIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    usageIndex = aUsageIndex;
}

int Rendering::VertexFormatAttribute::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::VertexFormatAttribute::SetOffset(int aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

int Rendering::VertexFormatAttribute::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(dataFormatType);
    size += CoreTools::GetStreamSize(semantic);
    size += CoreTools::GetStreamSize(usageIndex);
    size += CoreTools::GetStreamSize(offset);

    return size;
}

void Rendering::VertexFormatAttribute::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(dataFormatType);
    target.WriteEnum(semantic);
    target.Write(usageIndex);
    target.Write(offset);
}

void Rendering::VertexFormatAttribute::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(dataFormatType);
    source.ReadEnum(semantic);
    source.Read(usageIndex);
    source.Read(offset);
}

void Rendering::VertexFormatAttribute::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    outFile.Write(sizeof(DataFormatType), &dataFormatType);
    outFile.Write(sizeof(Semantic), &semantic);
    outFile.Write(sizeof(int32_t), &usageIndex);
    outFile.Write(sizeof(int32_t), &offset);
}

void Rendering::VertexFormatAttribute::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    inFile.Read(sizeof(DataFormatType), &dataFormatType);
    inFile.Read(sizeof(Semantic), &semantic);
    inFile.Read(sizeof(int32_t), &usageIndex);
    inFile.Read(sizeof(int32_t), &offset);
}
