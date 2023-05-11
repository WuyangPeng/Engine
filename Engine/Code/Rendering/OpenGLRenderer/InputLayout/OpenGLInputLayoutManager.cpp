///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/27 18:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLInputLayoutManager.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/InputLayout/OpenGLInputLayoutManagerImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, OpenGLInputLayoutManager)

Rendering::OpenGLInputLayoutManager::OpenGLInputLayoutManager(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, OpenGLInputLayoutManager)

Rendering::OpenGLInputLayoutManager::OpenGLInputLayoutSharedPtr Rendering::OpenGLInputLayoutManager::Bind(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Bind(programHandle, vertexBufferHandle, vertexBuffer);
}

void Rendering::OpenGLInputLayoutManager::Unbind(const VertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Unbind(vertexBuffer);
}

void Rendering::OpenGLInputLayoutManager::UnbindAll() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->UnbindAll();
}

bool Rendering::OpenGLInputLayoutManager::HasElements() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->HasElements();
}