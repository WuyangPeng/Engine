///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLVertexShader.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::PdrVertexShader::PdrVertexShader(Renderer*, MAYBE_UNUSED const VertexShader* vshader) noexcept
    : ParentType{}, shader{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PdrVertexShader)

void Rendering::PdrVertexShader::Enable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexShader* vshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::PdrVertexShader::Disable(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const VertexShader* vshader, MAYBE_UNUSED const ShaderParameters* parameters) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}
 
