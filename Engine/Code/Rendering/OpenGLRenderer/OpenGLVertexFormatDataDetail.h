///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 15:48)

#ifndef RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H
#define RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H

#include "OpenGLMapping.h"
#include "OpenGLVertexFormatData.h"
#include "System/Helper/PragmaWarning.h"
#include "System/OpenGL/OpenGLAPI.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"
#include "Rendering/Resources/Flags/DataFormatType.h"

template <Rendering::VertexFormatFlags::Semantic usage>
Rendering::OpenGLVertexFormatData<usage>::OpenGLVertexFormatData() noexcept
    : openGLHas{ 0 }, openGLChannels{ 0 }, openGLType{ System::OpenGLData::None }, openGLOffset{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <Rendering::VertexFormatFlags::Semantic usage>
bool Rendering::OpenGLVertexFormatData<usage>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIAN

template <Rendering::VertexFormatFlags::Semantic usage>
void Rendering::OpenGLVertexFormatData<usage>::Init(const VertexFormat* vertexFormat)
{
    RENDERING_CLASS_IS_VALID_9;

    if (vertexFormat == nullptr)
    {
        return;
    }

    const auto index = vertexFormat->GetIndex(usage);
    if (0 <= index)
    {
        openGLHas = 1;
        const auto type = vertexFormat->GetAttributeType(index);
        openGLChannels = OpenGLConstant::GetOpenGLAttributeChannels(System::EnumCastUnderlying(type));
        openGLType = System::UnderlyingCastEnum<System::OpenGLData>(OpenGLConstant::GetOpenGLAttributeType(System::EnumCastUnderlying(type)));
        openGLOffset = vertexFormat->GetOffset(index);
    }
}

template <Rendering::VertexFormatFlags::Semantic usage>
void Rendering::OpenGLVertexFormatData<usage>::Set(UInt has, UInt channels, DataType type, UInt offset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    openGLHas = has;
    openGLChannels = channels;
    openGLType = type;
    openGLOffset = offset;
}

template <Rendering::VertexFormatFlags::Semantic usage>
bool Rendering::OpenGLVertexFormatData<usage>::IsHas() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return openGLHas != 0;
}

template <Rendering::VertexFormatFlags::Semantic usage>
System::OpenGLUInt Rendering::OpenGLVertexFormatData<usage>::GetChannels() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return openGLChannels;
}

template <Rendering::VertexFormatFlags::Semantic usage>
System::OpenGLData Rendering::OpenGLVertexFormatData<usage>::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return openGLType;
}

template <Rendering::VertexFormatFlags::Semantic usage>
System::OpenGLUInt Rendering::OpenGLVertexFormatData<usage>::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return openGLOffset;
}

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Position>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Normal>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Tangent>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Binormal>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::BlendIndices>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::BlendWeight>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::FogCoord>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Psize>::Enable(int stride) noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Position>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Normal>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Tangent>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Binormal>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::BlendIndices>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::BlendWeight>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::FogCoord>::Disable() noexcept;

template <>
RENDERING_DEFAULT_DECLARE void Rendering::OpenGLVertexFormatData<Rendering::VertexFormatFlags::Semantic::Psize>::Disable() noexcept;

#endif  // RENDERING_RENDERERS_OPENGL_VERTEX_FORMAT_DATA_DETAIL_H
