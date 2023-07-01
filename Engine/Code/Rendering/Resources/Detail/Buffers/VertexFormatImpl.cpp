///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 17:12)

#include "Rendering/RenderingExport.h"

#include "VertexFormatImpl.h"
#include "CoreTools/FileManager/ReadFileManager.h"
#include "CoreTools/FileManager/WriteFileManager.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Buffers/VertexFormatAttribute.h"
#include "Rendering/Resources/DataFormat.h"

Rendering::VertexFormatImpl::VertexFormatImpl(int numAttributes) noexcept
    : numAttributes{ numAttributes }, stride{ 0 }, elements{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexFormatImpl::VertexFormatImpl() noexcept
    : numAttributes{ 0 }, stride{ 0 }, elements{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VertexFormatImpl::IsValid() const noexcept
{
    if (0 < numAttributes && numAttributes <= attributes && 0 <= stride)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::VertexFormatImpl::Reset() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    numAttributes = 0;
    stride = 0;

    for (auto& value : elements)
    {
        value = VertexFormatAttribute{};
    }
}

void Rendering::VertexFormatImpl::Bind(Semantic semantic, DataFormatType type, int unit)
{
    RENDERING_CLASS_IS_VALID_1;

    if (numAttributes < 0 && attributes <= numAttributes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("超过最大属性。"))
    }

    if (semantic == Semantic::Color)
    {
        if (System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::ColorUnits) < unit)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("颜色单位无效。"))
        }
    }
    else if (semantic == Semantic::TextureCoord)
    {
        if (System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits) < unit)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("纹理单位无效。"))
        }
    }
    else
    {
        if (unit != 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的语义单元。"))
        }
    }

    elements.at(numAttributes) = VertexFormatAttribute{ type, semantic, unit, stride };

    ++numAttributes;
    stride += DataFormat::GetNumBytesPerStruct(type);
}

void Rendering::VertexFormatImpl::SetAttribute(int attribute, DataFormatType type, Semantic usage, int usageIndex, int offset)
{
    RENDERING_CLASS_IS_VALID_1;

    SetAttribute(attribute, VertexFormatAttribute{ type, usage, usageIndex, offset });
}

void Rendering::VertexFormatImpl::SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatElement)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_1(0 <= attribute && attribute < numAttributes, "无效索引在SetAttribute\n");

    if (0 < attribute)
    {
        const auto previousIndex = attribute - 1;
        RENDERING_ASSERTION_1(elements.at(previousIndex).GetOffset() < vertexFormatElement.GetOffset(), "偏移量必须比属性索引高。\n");
    }
    else
    {
        RENDERING_ASSERTION_1(vertexFormatElement.GetOffset() == 0, "第一个属性的偏移量必须为零。\n");
    }

    elements.at(attribute) = vertexFormatElement;
}

void Rendering::VertexFormatImpl::SetStride(int aStride)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 < aStride, "Stride必须是正数。\n");

    stride = aStride;
}

int32_t Rendering::VertexFormatImpl::GetNumAttributes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numAttributes;
}

int32_t Rendering::VertexFormatImpl::GetOffset(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetOffset();
}

Rendering::DataFormatType Rendering::VertexFormatImpl::GetAttributeType(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetType();
}

Rendering::VertexFormatFlags::Semantic Rendering::VertexFormatImpl::GetAttributeUsage(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetUsage();
}

int32_t Rendering::VertexFormatImpl::GetUsageIndex(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_1(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetUsageIndex();
}

int Rendering::VertexFormatImpl::GetStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return stride;
}

int Rendering::VertexFormatImpl::GetIndex(Semantic usage, int usageIndex) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    for (auto index = 0; index < numAttributes; ++index)
    {
        if (const auto& attribute = elements.at(index);
            attribute.GetUsage() == usage && attribute.GetUsageIndex() == usageIndex)
        {
            return index;
        }
    }

    return -1;
}

int Rendering::VertexFormatImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        size += elements.at(i).GetStreamingSize();
    }

    size += CoreTools::GetStreamSize(stride);

    return size;
}

void Rendering::VertexFormatImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        elements.at(i).Save(target);
    }

    target.Write(stride);
}

void Rendering::VertexFormatImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        elements.at(i).Load(source);
    }

    source.Read(stride);
}

void Rendering::VertexFormatImpl::SaveToFile(WriteFileManager& outFile) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    outFile.Write(sizeof(int32_t), &numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        elements.at(i).SaveToFile(outFile);
    }

    outFile.Write(sizeof(int32_t), &stride);
}

void Rendering::VertexFormatImpl::ReadFromFile(ReadFileManager& inFile)
{
    RENDERING_CLASS_IS_VALID_1;

    // numAttributes已在VertexFormat读取。
    // inFile.Read(sizeof(int32_t),&numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        elements.at(i).ReadFromFile(inFile);
    }

    inFile.Read(sizeof(int32_t), &stride);
}
