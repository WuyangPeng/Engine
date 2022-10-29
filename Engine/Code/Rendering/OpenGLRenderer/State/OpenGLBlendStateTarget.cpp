///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.1 (2022/08/18 17:19)

#include "Rendering/RenderingExport.h"

#include "OpenGLBlendStateTarget.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"

Rendering::OpenGLBlendStateTarget::OpenGLBlendStateTarget() noexcept
    : enable{ GL_FALSE },
      sourceColor{ BlendStateMode::Zero },
      destinationColor{ BlendStateMode::Zero },
      operationColor{ BlendStateOperation::FuncAdd },
      sourceAlpha{ BlendStateMode::Zero },
      destinationAlpha{ BlendStateMode::Zero },
      operationAlpha{ BlendStateOperation::FuncAdd },
      redMask{ GL_FALSE },
      greenMask{ GL_FALSE },
      blueMask{ GL_FALSE },
      alphaMask{ GL_FALSE }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLBlendStateTarget)

System::OpenGLBoolean Rendering::OpenGLBlendStateTarget::IsEnable() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return enable;
}

void Rendering::OpenGLBlendStateTarget::SetEnable(OpenGLBoolean aEnable) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    enable = aEnable;
}

System::BlendStateMode Rendering::OpenGLBlendStateTarget::GetSourceColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sourceColor;
}

void Rendering::OpenGLBlendStateTarget::SetSourceColor(BlendStateMode color) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sourceColor = color;
}

System::BlendStateMode Rendering::OpenGLBlendStateTarget::GetDestinationColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return destinationColor;
}

void Rendering::OpenGLBlendStateTarget::SetDestinationColor(BlendStateMode color) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    destinationColor = color;
}

System::BlendStateOperation Rendering::OpenGLBlendStateTarget::GetOperationColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return operationColor;
}

void Rendering::OpenGLBlendStateTarget::SetOperationColor(BlendStateOperation color) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    operationColor = color;
}

System::BlendStateMode Rendering::OpenGLBlendStateTarget::GetSourceAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return sourceAlpha;
}

void Rendering::OpenGLBlendStateTarget::SetSourceAlpha(BlendStateMode alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    sourceAlpha = alpha;
}

System::BlendStateMode Rendering::OpenGLBlendStateTarget::GetDestinationAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return destinationAlpha;
}

void Rendering::OpenGLBlendStateTarget::SetDestinationAlpha(BlendStateMode alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    destinationAlpha = alpha;
}

System::BlendStateOperation Rendering::OpenGLBlendStateTarget::GetOperationAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return operationAlpha;
}

void Rendering::OpenGLBlendStateTarget::SetOperationAlpha(BlendStateOperation alpha) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    operationAlpha = alpha;
}

System::OpenGLBoolean Rendering::OpenGLBlendStateTarget::IsRedMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return redMask;
}

void Rendering::OpenGLBlendStateTarget::SetRedMask(OpenGLBoolean mask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    redMask = mask;
}

System::OpenGLBoolean Rendering::OpenGLBlendStateTarget::IsGreenMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return greenMask;
}

void Rendering::OpenGLBlendStateTarget::SetGreenMask(OpenGLBoolean mask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    greenMask = mask;
}

System::OpenGLBoolean Rendering::OpenGLBlendStateTarget::IsBlueMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blueMask;
}

void Rendering::OpenGLBlendStateTarget::SetBlueMask(OpenGLBoolean mask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blueMask = mask;
}

System::OpenGLBoolean Rendering::OpenGLBlendStateTarget::IsAlphaMask() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return alphaMask;
}

void Rendering::OpenGLBlendStateTarget::SetAlphaMask(OpenGLBoolean mask) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    alphaMask = mask;
}
