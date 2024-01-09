/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 14:50)

#include "Rendering/RenderingExport.h"

#include "OpenGLDepthStencilStateFace.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::OpenGLDepthStencilStateFace::OpenGLDepthStencilStateFace() noexcept
    : onFail{ DepthStencilStateOperation::Keep },
      onZFail{ DepthStencilStateOperation::Keep },
      onZPass{ DepthStencilStateOperation::Keep },
      comparison{ DepthStencilStateMode::Never }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLDepthStencilStateFace)

Rendering::OpenGLDepthStencilStateFace::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateFace::GetOnFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return onFail;
}

void Rendering::OpenGLDepthStencilStateFace::SetOnFail(DepthStencilStateOperation aOnFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    onFail = aOnFail;
}

Rendering::OpenGLDepthStencilStateFace::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateFace::GetOnZFail() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return onZFail;
}

void Rendering::OpenGLDepthStencilStateFace::SetOnZFail(DepthStencilStateOperation aOnZFail) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    onZFail = aOnZFail;
}

Rendering::OpenGLDepthStencilStateFace::DepthStencilStateOperation Rendering::OpenGLDepthStencilStateFace::GetOnZPass() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return onZPass;
}

void Rendering::OpenGLDepthStencilStateFace::SetOnZPass(DepthStencilStateOperation aOnZPass) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    onZPass = aOnZPass;
}

Rendering::OpenGLDepthStencilStateFace::DepthStencilStateMode Rendering::OpenGLDepthStencilStateFace::GetComparison() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return comparison;
}

void Rendering::OpenGLDepthStencilStateFace::SetComparison(DepthStencilStateMode aComparison) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    comparison = aComparison;
}
