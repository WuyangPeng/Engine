///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:22)

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
