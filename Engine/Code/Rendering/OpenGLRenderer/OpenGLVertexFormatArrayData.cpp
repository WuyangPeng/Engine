///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/23 14:51)

#include "Rendering/RenderingExport.h"

#include "OpenGLVertexFormatArrayDataDetail.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

template <>
void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::Semantic::TextureCoord, Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>::Enable(MAYBE_UNUSED int stride) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
}

void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::Semantic::Color, Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>::Enable(MAYBE_UNUSED int stride) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
}

template <>
void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::Semantic::TextureCoord, Rendering::VertexFormatFlags::MaximumNumber::TextureCoordinateUnits>::Disable() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
}

void Rendering::OpenGLVertexFormatArrayData<Rendering::VertexFormatFlags::Semantic::Color, Rendering::VertexFormatFlags::MaximumNumber::ColorUnits>::Disable() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    static_assert(System::EnumCastUnderlying(Rendering::VertexFormatFlags::MaximumNumber::ColorUnits) <= 2);
}
