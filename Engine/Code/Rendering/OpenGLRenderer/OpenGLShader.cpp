///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:22)

#include "Rendering/RenderingExport.h"

#include "OpenGLMapping.h"
#include "OpenGLShader.h"

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLShader)

void Rendering::OpenGLShader::SetSamplerState(MAYBE_UNUSED BaseRenderer* renderer, MAYBE_UNUSED int profile, MAYBE_UNUSED int maxSamplers, MAYBE_UNUSED RendererData::SamplerState* currentSS) noexcept
{
}

void Rendering::OpenGLShader::DisableTextures(MAYBE_UNUSED BaseRenderer* renderer, MAYBE_UNUSED int profile, MAYBE_UNUSED int maxSamplers) noexcept
{
}
