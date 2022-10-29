///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/27 13:48)

#include "Rendering/RenderingExport.h"

#include "OpenGLInputLayout.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/InputLayout/OpenGLInputLayoutImpl.h"
#include "Rendering/Resources/Flags/ChannelType.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLInputLayout)

Rendering::OpenGLInputLayout::OpenGLInputLayout(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBuffer& vertexBuffer)
    : impl{ programHandle, vertexBufferHandle, vertexBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLInputLayout)

void Rendering::OpenGLInputLayout::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Enable();
}

void Rendering::OpenGLInputLayout::Disable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Disable();
}