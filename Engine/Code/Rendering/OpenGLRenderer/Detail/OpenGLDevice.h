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

#include "Rendering/RendererEngine/Detail/RenderingDeviceImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLDevice : public RenderingDeviceImpl
    {
    public:
        using ClassType = OpenGLDevice;
        using ParentType = RenderingDeviceImpl;

    public:
        OpenGLDevice() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers(int syncInterval) override;
        void ResetSize() override;
        void InitDevice() noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;
        NODISCARD Viewport GetViewport() const override;
        void SetDepthRange(const DepthRange& depthRange) noexcept override;
        NODISCARD DepthRange GetDepthRange() const override;

        NODISCARD bool HasDepthRange01() const noexcept override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        NODISCARD void Resize(int width, int height) override;

        NODISCARD int64_t DrawPrimitive(const ConstVertexBufferSharedPtr& vertexBuffer,
                                        const ConstIndexBufferSharedPtr& indexBuffer,
                                        const ConstVisualEffectSharedPtr& effect) noexcept override;

        void ClearColorBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearDepthBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearStencilBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearBuffers(const RendererClear& rendererClear) noexcept override;

        void WaitForFinish() noexcept override;
        void Flush() noexcept override;
        void Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept override;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_DEVICE_H
