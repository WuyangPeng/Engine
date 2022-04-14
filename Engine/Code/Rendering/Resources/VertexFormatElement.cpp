///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:20)

#include "Rendering/RenderingExport.h"

#include "VertexFormatElement.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::VertexFormatElement::VertexFormatElement() noexcept
    : streamIndex{ 0 }, offset{ 0 }, vertexFormatType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VertexFormatElement::VertexFormatElement(int32_t streamIndex, int32_t offset, const VertexFormatType& vertexFormatType) noexcept
    : streamIndex{ streamIndex }, offset{ offset }, vertexFormatType{ vertexFormatType }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VertexFormatElement)

int32_t Rendering::VertexFormatElement::GetStreamIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return streamIndex;
}

void Rendering::VertexFormatElement::SetStreamIndex(int32_t aStreamIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    streamIndex = aStreamIndex;
}

int32_t Rendering::VertexFormatElement::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::VertexFormatElement::SetOffset(int32_t aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::VertexFormatFlags::AttributeType Rendering::VertexFormatElement::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormatType.GetType();
}

void Rendering::VertexFormatElement::SetType(AttributeType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormatType.SetType(type);
}

Rendering::VertexFormatFlags::AttributeUsage Rendering::VertexFormatElement::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormatType.GetUsage();
}

void Rendering::VertexFormatElement::SetUsage(AttributeUsage usage) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormatType.SetUsage(usage);
}

int32_t Rendering::VertexFormatElement::GetUsageIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return vertexFormatType.GetUsageIndex();
}

void Rendering::VertexFormatElement::SetUsageIndex(int32_t usageIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormatType.SetUsageIndex(usageIndex);
}

int Rendering::VertexFormatElement::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CORE_TOOLS_STREAM_SIZE(streamIndex);
    size += CORE_TOOLS_STREAM_SIZE(offset);
    size += vertexFormatType.GetStreamingSize();

    return size;
}

void Rendering::VertexFormatElement::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(streamIndex);
    target.Write(offset);
    vertexFormatType.Save(target);
}

void Rendering::VertexFormatElement::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(streamIndex);
    source.Read(offset);
    vertexFormatType.Load(source);
}

void Rendering::VertexFormatElement::SetVertexFormatType(const VertexFormatType& aVertexFormatType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    vertexFormatType = aVertexFormatType;
}

void Rendering::VertexFormatElement::Set(int32_t aStreamIndex, int32_t aOffset, const VertexFormatType& aVertexFormatType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    SetStreamIndex(aStreamIndex);
    SetOffset(aOffset);
    SetVertexFormatType(aVertexFormatType);
}

void Rendering::VertexFormatElement::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    outFile.Write(sizeof(int32_t), &streamIndex);
    outFile.Write(sizeof(int32_t), &offset);
    vertexFormatType.SaveToFile(outFile);
}

void Rendering::VertexFormatElement::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_9;

    inFile.Read(sizeof(int32_t), &streamIndex);
    inFile.Read(sizeof(int32_t), &offset);
    vertexFormatType.ReadFromFile(inFile);
}
