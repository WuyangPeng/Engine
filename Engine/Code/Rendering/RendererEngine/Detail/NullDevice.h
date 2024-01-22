/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:10)

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

        void DisplayColorBuffer(int syncInterval) noexcept override;

        void InitDevice() noexcept override;
        void Release() noexcept override;

        void SetViewport(const Viewport& viewport) noexcept override;
        NODISCARD Viewport GetViewport() const noexcept override;
        void SetDepthRange(const DepthRange& depthRange) noexcept override;
        NODISCARD DepthRange GetDepthRange() const noexcept override;

        NODISCARD bool HasDepthRange01() const noexcept override;
        NODISCARD std::string GetShaderName(const std::string& name) const override;
        NODISCARD std::string GetShaderExtendName() const override;

        NODISCARD int64_t DrawPrimitive(RendererObjectBridge& rendererObjectBridge,
                                        const VertexBufferSharedPtr& vertexBuffer,
                                        const IndexBufferSharedPtr& indexBuffer,
                                        const VisualEffectSharedPtr& effect) noexcept override;

        void ClearColorBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearDepthBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearStencilBuffer(const RendererClear& rendererClear) noexcept override;
        void ClearBuffers(const RendererClear& rendererClear) noexcept override;

        void WaitForFinish() noexcept override;
        void Flush() noexcept override;
        void Execute(RendererObjectBridge& rendererObjectBridge, ComputeProgram& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept override;
        void Resize(int width, int height) noexcept override;

    private:
        Viewport nullViewport;
        DepthRange nullDepthRange;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_NULL_DEVICE_H
