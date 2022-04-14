///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 16:45)

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

std::array<int, System::EnumCastUnderlying(Rendering::VertexFormatFlags::AttributeType::Quantity)> Rendering::VertexFormatImpl::componentSize{
    0,  // AttributeType::None
    4,  // AttributeType::Float1
    4,  // AttributeType::Float2
    4,  // AttributeType::Float3
    4,  // AttributeType::Float4
    2,  // AttributeType::Half1
    2,  // AttributeType::Half2
    2,  // AttributeType::Half3
    2,  // AttributeType::Half4
    1,  // AttributeType::UByte4
    2,  // AttributeType::Short1
    2,  // AttributeType::Short2
    2  // AttributeType::Short3
};

std::array<int, System::EnumCastUnderlying(Rendering::VertexFormatFlags::AttributeType::Quantity)> Rendering::VertexFormatImpl::numComponents{
    0,  // AttributeType::None
    1,  // AttributeType::Float1
    2,  // AttributeType::Float2
    3,  // AttributeType::Float3
    4,  // AttributeType::Float4
    1,  // AttributeType::Half1
    2,  // AttributeType::Half2
    3,  // AttributeType::Half3
    4,  // AttributeType::Half4
    4,  // AttributeType::UByte4
    1,  // AttributeType::Short1
    2,  // AttributeType::Short2
    4  // AttributeType::Short3
};

std::array<int, System::EnumCastUnderlying(Rendering::VertexFormatFlags::AttributeType::Quantity)> Rendering::VertexFormatImpl::typeSize{
    0,  // AttributeType::None
    4,  // AttributeType::Float1
    8,  // AttributeType::Float2
    12,  // AttributeType::Float3
    16,  // AttributeType::Float4
    2,  // AttributeType::Half1
    4,  // AttributeType::Half2
    6,  // AttributeType::Half3
    8,  // AttributeType::Half4
    4,  // AttributeType::UByte4
    2,  // AttributeType::Short1
    4,  // AttributeType::Short2
    8  // AttributeType::Short3
};

Rendering::VertexFormatImpl::VertexFormatImpl(int numAttributes) noexcept
    : numAttributes{ numAttributes }, stride{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexFormatImpl::VertexFormatImpl() noexcept
    : numAttributes{ 0 }, stride{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VertexFormatImpl::IsValid() const noexcept
{
    if (0 < numAttributes && numAttributes <= System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes) && 0 <= stride)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::VertexFormatImpl::SetAttribute(int attribute, int32_t streamIndex, int32_t offset, AttributeType type, AttributeUsage usage, int32_t usageIndex)
{
    RENDERING_CLASS_IS_VALID_1;

    SetAttribute(attribute, streamIndex, offset, VertexFormatType{ type, usage, usageIndex });
}

void Rendering::VertexFormatImpl::SetAttribute(int attribute, int32_t streamIndex, int32_t offset, const VertexFormatType& vertexFormatType)
{
    RENDERING_CLASS_IS_VALID_1;

    SetAttribute(attribute, VertexFormatElement{ streamIndex, offset, vertexFormatType });
}

void Rendering::VertexFormatImpl::SetAttribute(int attribute, const VertexFormatElement& vertexFormatElement)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 <= attribute && attribute < numAttributes, "无效索引在SetAttribute\n");

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

int32_t Rendering::VertexFormatImpl::GetStreamIndex(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetStreamIndex();
}

int32_t Rendering::VertexFormatImpl::GetOffset(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetOffset();
}

Rendering::VertexFormatFlags::AttributeType Rendering::VertexFormatImpl::GetAttributeType(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetType();
}

Rendering::VertexFormatFlags::AttributeUsage Rendering::VertexFormatImpl::GetAttributeUsage(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetUsage();
}

int32_t Rendering::VertexFormatImpl::GetUsageIndex(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= attribute && attribute < numAttributes, "无效索引在GetStreamIndex\n");

    return elements.at(attribute).GetUsageIndex();
}

int Rendering::VertexFormatImpl::GetStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return stride;
}

int Rendering::VertexFormatImpl::GetIndex(AttributeUsage usage, int32_t usageIndex) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    for (auto index = 0; index < numAttributes; ++index)
    {
        if (elements.at(index).GetUsage() == usage && elements.at(index).GetUsageIndex() == usageIndex)
        {
            return index;
        }
    }

    return -1;
}

int Rendering::VertexFormatImpl::GetComponentSize(AttributeType type) noexcept
{
    return componentSize.at(System::EnumCastUnderlying(type));
}

int Rendering::VertexFormatImpl::GetNumComponents(AttributeType type) noexcept
{
    return numComponents.at(System::EnumCastUnderlying(type));
}

int Rendering::VertexFormatImpl::GetTypeSize(AttributeType type) noexcept
{
    return typeSize.at(System::EnumCastUnderlying(type));
}

int Rendering::VertexFormatImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CORE_TOOLS_STREAM_SIZE(numAttributes);

    for (auto i = 0; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes); ++i)
    {
        size += elements.at(i).GetStreamingSize();
    }

    size += CORE_TOOLS_STREAM_SIZE(stride);

    return size;
}

void Rendering::VertexFormatImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(numAttributes);

    for (auto i = 0; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes); ++i)
    {
        elements.at(i).Save(target);
    }

    target.Write(stride);
}

void Rendering::VertexFormatImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numAttributes);

    for (auto i = 0; i < System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::Attributes); ++i)
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

    // m_NumAttributes已在LoadFromFile读取。
    // inFile.Read(sizeof(int32_t),&numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        elements.at(i).ReadFromFile(inFile);
    }

    inFile.Read(sizeof(int32_t), &stride);
}
