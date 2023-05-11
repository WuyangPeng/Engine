///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/27 18:26)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_H
#define RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "Rendering/Base/InputLayoutManager.h"
#include "Rendering/OpenGLRenderer/InputLayout/OpenGLInputLayout.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(OpenGLInputLayoutManager, OpenGLInputLayoutManagerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE OpenGLInputLayoutManager : public InputLayoutManager
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(OpenGLInputLayoutManager);
        using ParentType = InputLayoutManager;
        using OpenGLUInt = System::OpenGLUInt;
        using OpenGLInputLayoutSharedPtr = std::shared_ptr<OpenGLInputLayout>;

    public:
        explicit OpenGLInputLayoutManager(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_DECLARE;

        NODISCARD OpenGLInputLayoutSharedPtr Bind(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBufferSharedPtr& vertexBuffer);
        void Unbind(const VertexBufferSharedPtr& vertexBuffer);
        void UnbindAll() noexcept;
        NODISCARD bool HasElements() const noexcept;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_H