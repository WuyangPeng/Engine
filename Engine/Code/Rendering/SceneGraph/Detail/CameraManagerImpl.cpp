///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.5 (2022/04/01 10:50)

#include "Rendering/RenderingExport.h"

#include "CameraManagerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Renderers/RendererInput.h"

Rendering::CameraManagerImpl::CameraManagerImpl() noexcept
    : depthType{ DepthType::Quantity }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, CameraManagerImpl)

void Rendering::CameraManagerImpl::SetDefaultDepthType(RendererTypes type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    switch (type)
    {
        case RendererTypes::Default:
            depthType = DepthType::MinusOneToOne;
            break;

        case RendererTypes::Window:
        case RendererTypes::Glut:
        case RendererTypes::OpenGL:
        case RendererTypes::OpenGLES:
            // OpenGL使用投影矩阵在深度[-1,1]。
            depthType = DepthType::MinusOneToOne;
            break;

        case RendererTypes::Dx9:
            // DirectX使用投影矩阵在深度[0,1]。
            depthType = DepthType::ZeroToOne;
            break;

        default:
            depthType = DepthType::MinusOneToOne;
            break;
    }
}

Rendering::DepthType Rendering::CameraManagerImpl::GetDepthType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return depthType;
}
