///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/04/01 10:50)

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
            // OpenGLʹ��ͶӰ���������[-1,1]��
            depthType = DepthType::MinusOneToOne;
            break;

        case RendererTypes::Dx9:
            // DirectXʹ��ͶӰ���������[0,1]��
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
