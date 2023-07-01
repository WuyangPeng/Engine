///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 14:42)

#ifndef RENDERING_RENDERER_ENGINE_NULL_DEVICE_H
#define RENDERING_RENDERER_ENGINE_NULL_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "RenderingDeviceImpl.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE NullDevice final : public RenderingDeviceImpl
    {
    public:
        using ClassType = NullDevice;
        using ParentType = RenderingDeviceImpl;

    public:
        NullDevice() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD RenderingDeviceSharedPtr Clone() const override;

        void SwapBuffers(int syncInterval) noexcept override;

        void ResetSize() noexcept override;
        void InitDevice() noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;
        NODISCARD Viewport GetViewport() const noexcept override;
        void SetDepthRange(const DepthRange& depthRange) noexcept override;
        NODISCARD DepthRange GetDepthRange() const noexcept override;

        NODISCARD bool HasDepthRange01() const noexcept override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        NODISCARD void Resize(int width, int height) noexcept override;

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

    private:
        Viewport nullViewport;
        DepthRange nullDepthRange;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_NULL_DEVICE_H
