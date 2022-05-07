///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 14:51)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_DETAIL_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_DETAIL_H

#include "OpenGLMapping.h"
#include "OpenGLVertexFormatArrayData.h"
#include "OpenGLVertexFormatDataDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/VertexFormat.h"

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
Rendering::OpenGLVertexFormatArrayData<usage, number>::OpenGLVertexFormatArrayData() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::OpenGLVertexFormatArrayData<usage, number>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
void Rendering::OpenGLVertexFormatArrayData<usage, number>::Init(const VertexFormat* vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

    if (vertexFormat == nullptr)
    {
        return;
    }

    for (auto unit = 0; unit < System::EnumCastUnderlying(number); ++unit)
    {
        const auto index = vertexFormat->GetIndex(usage, unit);
        if (0 <= index)
        {
            constexpr auto has = 1u;
            const auto attributeType = vertexFormat->GetAttributeType(index);
            const auto channels = OpenGLConstant::GetOpenGLAttributeChannels(System::EnumCastUnderlying(attributeType));
            const auto type = System::UnderlyingCastEnum<System::OpenGLData>(OpenGLConstant::GetOpenGLAttributeType(System::EnumCastUnderlying(attributeType)));
            const auto offset = vertexFormat->GetOffset(index);

            data.at(unit).Set(has, channels, type, offset);
        }
    }
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
bool Rendering::OpenGLVertexFormatArrayData<usage, number>::IsHas(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number), "索引无效！");

    return data.at(index).IsHas();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
System::OpenGLUInt Rendering::OpenGLVertexFormatArrayData<usage, number>::GetChannels(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number), "索引无效！");

    return data.at(index).GetChannels();
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
System::OpenGLUInt Rendering::OpenGLVertexFormatArrayData<usage, number>::GetType(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number), "索引无效！");

    return System::EnumCastUnderlying<System::OpenGLUInt>(data.at(index).GetType());
}

template <Rendering::VertexFormatFlags::AttributeUsage usage, Rendering::VertexFormatFlags::MaximumNumber number>
System::OpenGLUInt Rendering::OpenGLVertexFormatArrayData<usage, number>::GetOffset(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < System::EnumCastUnderlying(number), "索引无效！");

    return data.at(index).GetOffset();
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::TextureCoord, Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::Color, Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::TextureCoord, Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::AttributeUsage::Color, Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>::Disable() noexcept;

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_ARRAY_DATA_DETAIL_H
