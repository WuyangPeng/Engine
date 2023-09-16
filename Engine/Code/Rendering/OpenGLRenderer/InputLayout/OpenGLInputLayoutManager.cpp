///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:29)

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

bool Rendering::OpenGLInputLayoutManager::Unbind(const ShaderSharedPtr& vertexShader)
{
    System::UnusedFunction(vertexShader);

    CoreTools::DisableNoexcept();

    return true;
}

bool Rendering::OpenGLInputLayoutManager::Unbind(const VertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Unbind(vertexBuffer);

    return true;
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
