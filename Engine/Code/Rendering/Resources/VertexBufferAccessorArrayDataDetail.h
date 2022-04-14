///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/03/31 18:35)

#ifndef RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_DETAIL_H
#define RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_DETAIL_H

#include "Rendering/RenderingExport.h"

#include "VertexBuffer.h"
#include "VertexBufferAccessorArrayData.h"
#include "VertexFormat.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
Rendering::VertexBufferAccessorArrayData<usage, number>::VertexBufferAccessorArrayData()
    : data{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
Rendering::VertexBufferAccessorArrayData<usage, number>::VertexBufferAccessorArrayData(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer)
    : data{}
{
    Init(vertexformat, vertexbuffer);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::VertexBufferAccessorArrayData<usage, number>::IsValid() const noexcept
{
    return true;
}
#endif  // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
void Rendering::VertexBufferAccessorArrayData<usage, number>::Init(const VertexFormat& vertexformat, const VertexBuffer& vertexbuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    for (auto unit = 0; unit < System::EnumCastUnderlying(number); ++unit)
    {
        data.at(unit).Init(vertexformat, vertexbuffer, unit);
    }
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
const char* Rendering::VertexBufferAccessorArrayData<usage, number>::GetData(int stride, int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "索引错误。\n");

    return data.at(unit).GetData(stride, index);
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::VertexBufferAccessorArrayData<usage, number>::HasData(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "索引错误。\n");

    return data.at(unit).HasData();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
int Rendering::VertexBufferAccessorArrayData<usage, number>::GetDataChannels(int unit) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "索引错误。\n");

    return data.at(unit).GetDataChannels();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
const float* Rendering::VertexBufferAccessorArrayData<usage, number>::GetDataTuple(int stride, int unit, int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= unit && unit < System::EnumCastUnderlying(number), "索引错误。\n");

    return data.at(unit).GetDataTuple(stride, index);
}

#endif  // RENDERING_RESOURCES_VERTEX_BUFFER_ACCESSOR_ARRAY_DATA_DETAIL_H
