///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/22 22:19)

#include "Rendering/RenderingExport.h"

#include "OpenGLMapping.h"
#include "OpenGLShader.h"

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLShader)

void Rendering::OpenGLShader::SetSamplerState(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const ShaderBase* shader, MAYBE_UNUSED int profile, MAYBE_UNUSED const ShaderParameters* parameters, MAYBE_UNUSED int maxSamplers, MAYBE_UNUSED RendererData::SamplerState* currentSS) noexcept
{
}

void Rendering::OpenGLShader::DisableTextures(MAYBE_UNUSED Renderer* renderer, MAYBE_UNUSED const ShaderBase* shader, MAYBE_UNUSED int profile, MAYBE_UNUSED const ShaderParameters* parameters, MAYBE_UNUSED int maxSamplers) noexcept
{
}
