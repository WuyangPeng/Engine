///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:58)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
#define RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "System/OpenGL/Using/OpenGLUsing.h"
#include "Rendering/OpenGLRenderer/InputLayout/OpenGLInputLayoutManager.h"
#include "Rendering/RendererEngine/Detail/RenderingDeviceImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLDevice : public RenderingDeviceImpl
    {
    public:
        using ClassType = OpenGLDevice;
        using ParentType = RenderingDeviceImpl;

    public:
        explicit OpenGLDevice(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers(int syncInterval) override;
        void ResetSize() override;
        void InitDevice() noexcept override;
        void Release() noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;
        NODISCARD Viewport GetViewport() const override;
        void SetDepthRange(const DepthRange& depthRange) noexcept override;
        NODISCARD DepthRange GetDepthRange() const override;

        NODISCARD bool HasDepthRange01() const noexcept override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        NODISCARD std::string GetShaderExtendName() const override;
        NODISCARD void Resize(int width, int height) override;

        NODISCARD int64_t DrawPrimitive(RendererObjectBridge& rendererObjectBridge,
                                        const VertexBufferSharedPtr& vertexBuffer,
                                        const IndexBufferSharedPtr& indexBuffer,
                                        const VisualEffectSharedPtr& effect) override;

        void ClearColorBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearDepthBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearStencilBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearBuffers(const RendererClear& rendererClear) noexcept override;

        void WaitForFinish() noexcept override;
        void Flush() noexcept override;
        void Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept override;

    private:
        using OpenGLUInt = System::OpenGLUInt;

    private:
        NODISCARD bool EnableShaders(VisualEffect& effect, OpenGLUInt program);
        void DisableShaders(VisualEffect& effect, OpenGLUInt program) noexcept;
        void Enable(const Shader& shader, OpenGLUInt program) noexcept;
        void Disable(const Shader& shader, OpenGLUInt program) noexcept;
        void EnableConstantBuffers(const Shader& shader, OpenGLUInt program) noexcept;
        void DisableConstantBuffers(const Shader& shader, OpenGLUInt program) noexcept;
        void EnableSBuffers(const Shader& shader, OpenGLUInt program) noexcept;
        void DisableSBuffers(const Shader& shader, OpenGLUInt program) noexcept;
        void EnableTextures(const Shader& shader, OpenGLUInt program) noexcept;
        void DisableTextures(const Shader& shader, OpenGLUInt program) noexcept;
        void EnableTextureArrays(const Shader& shader, OpenGLUInt program) noexcept;
        void DisableTextureArrays(const Shader& shader, OpenGLUInt program) noexcept;
        void EnableSamplers(const Shader& shader, OpenGLUInt program) noexcept;
        void DisableSamplers(const Shader& shader, OpenGLUInt program) noexcept;

        NODISCARD int64_t DrawPrimitive(const VertexBufferSharedPtr& vertexBuffer,
                                        const IndexBufferSharedPtr& indexBuffer);

    private:
        OpenGLInputLayoutManager openGLInputLayoutManager;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
