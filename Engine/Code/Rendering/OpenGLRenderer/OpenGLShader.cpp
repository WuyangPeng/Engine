///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:22)

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
