///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:19)

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

        using OpenGLUInt = System::OpenGLUnsignedInt;
        using OpenGLInputLayoutSharedPtr = std::shared_ptr<OpenGLInputLayout>;

    public:
        explicit OpenGLInputLayoutManager(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD OpenGLInputLayoutSharedPtr Bind(OpenGLUInt programHandle, OpenGLUInt vertexBufferHandle, const VertexBufferSharedPtr& vertexBuffer);

        NODISCARD bool Unbind(const ShaderSharedPtr& vertexShader) override;
        NODISCARD bool Unbind(const VertexBufferSharedPtr& vertexBuffer) override;
        void UnbindAll() noexcept override;
        NODISCARD bool HasElements() const noexcept override;

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_INPUT_LAYOUT_MANAGER_H