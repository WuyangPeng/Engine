///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:36)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_DETAIL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_DATA_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "VertexBuffer.h"
#include "VertexBufferAccessorData.h"
#include "VertexFormat.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::VertexFormatFlags::AttributeUsage usage>
Rendering::VertexBufferAccessorData<usage>::VertexBufferAccessorData() noexcept
    : data{ nullptr }, dataChannels{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
Rendering::VertexBufferAccessorData<usage>::VertexBufferAccessorData(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer)
    : data{ nullptr }, dataChannels{ 0 }
{
    Init(vertexformat, vertexbuffer);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <Rendering::VertexFormatFlags::AttributeUsage usage>
bool Rendering::VertexBufferAccessorData<usage>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage>
void Rendering::VertexBufferAccessorData<usage>::Init(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer, int number)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto baseType = VertexFormatFlags::AttributeType::None;

    const auto index = vertexformat.GetIndex(usage, number);
    if (0 <= index)
    {
        data = vertexbuffer.GetReadOnlyData(vertexformat.GetOffset(index));
        const auto type = vertexformat.GetAttributeType(index);
        dataChannels = System::EnumCastUnderlying(type) - System::EnumCastUnderlying(baseType);
        if (4 < dataChannels)
        {
            dataChannels = 0;
        }
    }
    else
    {
        data = nullptr;
        dataChannels = 0;
    }
}

template <>
void Rendering::VertexBufferAccessorData<Rendering::VertexFormatFlags::AttributeUsage::BlendIndices>::Init(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer, int number)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto index = vertexformat.GetIndex(VertexFormatFlags::AttributeUsage::BlendIndices, number);
    if (0 <= index)
    {
        data = vertexbuffer.GetReadOnlyData(vertexformat.GetOffset(index));
        dataChannels = 0;
    }
    else
    {
        data = nullptr;
        dataChannels = 0;
    }
}

template <>
void Rendering::VertexBufferAccessorData<Rendering::VertexFormatFlags::AttributeUsage::BlendWeight>::Init(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer, int number)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto index = vertexformat.GetIndex(VertexFormatFlags::AttributeUsage::BlendWeight, number);
    if (0 <= index)
    {
        data = vertexbuffer.GetReadOnlyData(vertexformat.GetOffset(index));
        dataChannels = 0;
    }
    else
    {
        data = nullptr;
        dataChannels = 0;
    }
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
const char* Rendering::VertexBufferAccessorData<usage>::GetData(int stride, int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto next = index * stride;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

    return data + next;

#include STSTEM_WARNING_POP
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
bool Rendering::VertexBufferAccessorData<usage>::HasData() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return data != nullptr;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
int Rendering::VertexBufferAccessorData<usage>::GetDataChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return dataChannels;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage>
const float* Rendering::VertexBufferAccessorData<usage>::GetDataTuple(int stride, int index) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto next = index * stride;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<const float*>(data + next);

#include STSTEM_WARNING_POP
}

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H
