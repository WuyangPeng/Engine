///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/22 15:36)

#include "Rendering/RenderingExport.h"

#include "OpenGLBindTexture.h"
#include "OpenGLMapping.h"
#include "System/Helper/PragmaWarning.h"
#include "System/OpenGL/OpenGLBase.h"

#include <gsl/util>

Rendering::UInt Rendering::BindTexture(ShaderFlags::SamplerType target, MAYBE_UNUSED UInt texture)
{
    const auto current = System::GetGLInteger(System::UnderlyingCastEnum<System::OpenGLQuery>(OpenGLConstant::GetOpenGLTextureTargetBinding(System::EnumCastUnderlying(target))));

    return gsl::narrow_cast<UInt>(current);
}

Rendering::UInt Rendering::GetBoundTexture(ShaderFlags::SamplerType target)
{
    const auto current = System::GetGLInteger(System::UnderlyingCastEnum<System::OpenGLQuery>(OpenGLConstant::GetOpenGLTextureTargetBinding(System::EnumCastUnderlying(target))));

    return gsl::narrow_cast<UInt>(current);
}
