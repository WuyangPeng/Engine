/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/16 14:03)

#include "Rendering/RenderingExport.h"

#include "VertexFormatImpl.h"
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
    : numAttributes{ numAttributes }, vertexSize{ 0 }, elements{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::VertexFormatImpl::VertexFormatImpl() noexcept
    : numAttributes{ 0 }, vertexSize{ 0 }, elements{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::VertexFormatImpl::IsValid() const noexcept
{
    if (0 <= numAttributes && numAttributes < attributes && 0 <= vertexSize)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::VertexFormatImpl::Reset() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    numAttributes = 0;
    vertexSize = 0;

    for (auto& value : elements)
    {
        value.Clear();
    }
}

void Rendering::VertexFormatImpl::Bind(DataFormatType type, Semantic semantic, int unit)
{
    RENDERING_CLASS_IS_VALID_1;

    // ��֤���롣
    if (numAttributes < 0 && attributes <= numAttributes)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����������ԡ�"))
    }

    if (semantic == Semantic::Color)
    {
        if (System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::ColorUnits) < unit)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��ɫ��λ��Ч��"))
        }
    }
    else if (semantic == Semantic::TextureCoord)
    {
        if (System::EnumCastUnderlying(VertexFormatFlags::MaximumNumber::TextureCoordinateUnits) < unit)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("����λ��Ч��"))
        }
    }
    else
    {
        if (unit != 0)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��Ч�����嵥Ԫ��"))
        }
    }

    // ��������
    auto& attribute = elements.at(numAttributes);
    attribute.SetVertexFormatAttribute(type, semantic, unit, vertexSize);

    ++numAttributes;

    // �ƽ�ƫ�ơ�
    vertexSize += DataFormat::GetNumBytesPerStruct(type);
}

void Rendering::VertexFormatImpl::SetAttribute(int attribute, DataFormatType type, Semantic semantic, int unit, int offset)
{
    RENDERING_CLASS_IS_VALID_1;

    SetAttribute(attribute, VertexFormatAttribute{ type, semantic, unit, offset });
}

void Rendering::VertexFormatImpl::SetAttribute(int attribute, const VertexFormatAttribute& vertexFormatAttribute)
{
    RENDERING_CLASS_IS_VALID_1;

    if (0 < attribute)
    {
        const auto previousIndex = attribute - 1;
        RENDERING_ASSERTION_0(elements.at(previousIndex).GetOffset() < vertexFormatAttribute.GetOffset(), "ƫ������������������ߡ�\n");
    }
    else
    {
        RENDERING_ASSERTION_0(vertexFormatAttribute.GetOffset() == 0, "��һ�����Ե�ƫ��������Ϊ�㡣\n");
    }

    elements.at(attribute) = vertexFormatAttribute;
}

void Rendering::VertexFormatImpl::SetVertexSize(int aVertexSize)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(0 < aVertexSize, "Stride������������\n");

    vertexSize = aVertexSize;
}

int32_t Rendering::VertexFormatImpl::GetNumAttributes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return numAttributes;
}

int32_t Rendering::VertexFormatImpl::GetOffset(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return elements.at(attribute).GetOffset();
}

Rendering::DataFormatType Rendering::VertexFormatImpl::GetAttributeType(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return elements.at(attribute).GetType();
}

Rendering::VertexFormatFlags::Semantic Rendering::VertexFormatImpl::GetSemantic(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return elements.at(attribute).GetSemantic();
}

int32_t Rendering::VertexFormatImpl::GetUnit(int attribute) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return elements.at(attribute).GetUnit();
}

int Rendering::VertexFormatImpl::GetVertexSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return vertexSize;
}

int Rendering::VertexFormatImpl::GetIndex(Semantic semantic, int unit) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    for (auto index = 0; index < numAttributes; ++index)
    {
        if (const auto& attribute = elements.at(index);
            attribute.GetSemantic() == semantic && attribute.GetUnit() == unit)
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

    size += CoreTools::GetStreamSize(vertexSize);

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

    target.Write(vertexSize);
}

void Rendering::VertexFormatImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(numAttributes);

    for (auto i = 0; i < numAttributes; ++i)
    {
        elements.at(i).Load(source);
    }

    source.Read(vertexSize);
}
