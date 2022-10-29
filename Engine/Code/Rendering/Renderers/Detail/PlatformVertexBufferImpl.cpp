///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/20 14:05)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Dx9Renderer/Dx9VertexBuffer.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Renderers/Renderer.h"

Rendering::PlatformVertexBufferImpl::PlatformVertexBufferImpl() noexcept
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexBufferImpl)

// static
Rendering::PlatformVertexBufferImpl::PlatformVertexBufferSharedPtr Rendering::PlatformVertexBufferImpl::Create(Renderer* renderer, const VertexBuffer* vertexBuffer)
{
    if (renderer == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("renderer Ϊ�ա�"s));
    }

    switch (renderer->GetRendererType())
    {
        case RendererTypes::Default:
            return CreateDefault(renderer, vertexBuffer);
        case RendererTypes::Windows:
            return make_shared<Dx9VertexBuffer>(renderer, vertexBuffer);
        case RendererTypes::Glut:
            return make_shared<Dx9VertexBuffer>(renderer, vertexBuffer);
        case RendererTypes::OpenGL:
            return make_shared<Dx9VertexBuffer>(renderer, vertexBuffer);
        case RendererTypes::Dx11:
            return make_shared<Dx9VertexBuffer>(renderer, vertexBuffer);
        case RendererTypes::OpenGLES:
            return make_shared<Dx9VertexBuffer>(renderer, vertexBuffer);
        default:
            return CreateDefault(renderer, vertexBuffer);
    }
}

// static
Rendering::PlatformVertexBufferImpl::PlatformVertexBufferSharedPtr Rendering::PlatformVertexBufferImpl::CreateDefault(Renderer* renderer, const VertexBuffer* vertexBuffer)
{
    return make_shared<Dx9VertexBuffer>(renderer, vertexBuffer);
}
