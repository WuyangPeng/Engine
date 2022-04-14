///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:15)

#include "Rendering/RenderingExport.h"

#include "VertexFormatType.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::VertexFormatType::VertexFormatType() noexcept
    : attributeType{ VertexFormatFlags::AttributeType::None }, attributeUsage{ VertexFormatFlags::AttributeUsage::None }, usageIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatType::VertexFormatType(AttributeType type, AttributeUsage usage, int32_t usageIndex) noexcept
    : attributeType{ type }, attributeUsage{ usage }, usageIndex{ usageIndex }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatType)

Rendering::VertexFormatFlags::AttributeType Rendering::VertexFormatType::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return attributeType;
}

void Rendering::VertexFormatType::SetType(AttributeType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    attributeType = type;
}

Rendering::VertexFormatFlags::AttributeUsage Rendering::VertexFormatType::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return attributeUsage;
}

void Rendering::VertexFormatType::SetUsage(AttributeUsage usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    attributeUsage = usage;
}

int32_t Rendering::VertexFormatType::GetUsageIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return usageIndex;
}

void Rendering::VertexFormatType::SetUsageIndex(int32_t aUsageIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    usageIndex = aUsageIndex;
}

int Rendering::VertexFormatType::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(attributeType);
    size += CORE_TOOLS_STREAM_SIZE(attributeUsage);
    size += CORE_TOOLS_STREAM_SIZE(usageIndex);

    return size;
}

void Rendering::VertexFormatType::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteEnum(attributeType);
    target.WriteEnum(attributeUsage);
    target.Write(usageIndex);
}

void Rendering::VertexFormatType::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadEnum(attributeType);
    source.ReadEnum(attributeUsage);
    source.Read(usageIndex);
}

void Rendering::VertexFormatType::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    outFile.Write(sizeof(AttributeType), &attributeType);
    outFile.Write(sizeof(AttributeUsage), &attributeUsage);
    outFile.Write(sizeof(unsigned int), &usageIndex);
}

void Rendering::VertexFormatType::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    inFile.Read(sizeof(AttributeType), &attributeType);
    inFile.Read(sizeof(AttributeUsage), &attributeUsage);
    inFile.Read(sizeof(int32_t), &usageIndex);
}
