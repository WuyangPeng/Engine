/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 15:11)

#ifndef RENDERING_RENDERER_ENGINE_RENDERER_ADAPTER_H
#define RENDERING_RENDERER_ENGINE_RENDERER_ADAPTER_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RendererEngine/DepthRange.h"
#include "Rendering/RendererEngine/RenderingEnvironment.h"
#include "Rendering/RendererEngine/Viewport.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RendererAdapter
    {
    public:
        using ClassType = RendererAdapter;

        using RendererObjectBridgeSharedPtr = std::shared_ptr<RendererObjectBridge>;
        using DrawTargetBridgeSharedPtr = std::shared_ptr<DrawTargetBridge>;

        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using IndexBufferSharedPtr = std::shared_ptr<IndexBuffer>;
        using VisualEffectSharedPtr = std::shared_ptr<VisualEffect>;

        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstVisualEffectSharedPtr = std::shared_ptr<const VisualEffect>;

        using GraphicsObjectSharedPtr = std::shared_ptr<GraphicsObject>;
        using RendererObjectSharedPtr = std::shared_ptr<RendererObject>;
        using ConstRendererObjectSharedPtr = std::shared_ptr<const RendererObject>;
        using RendererObjectContainer = std::vector<RendererObjectSharedPtr>;

        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;
        using RendererDrawTargetSharedPtr = std::shared_ptr<RendererDrawTarget>;

    public:
        explicit RendererAdapter(const RenderingEnvironment& renderingEnvironment);

        CLASS_INVARIANT_DECLARE;

        NODISCARD RendererObjectBridgeSharedPtr GetRendererObjectBridge() noexcept;
        NODISCARD DrawTargetBridgeSharedPtr GetDrawTargetBridge() noexcept;

        NODISCARD int GetWidth() const noexcept;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD DataFormatType GetColorFormat() const noexcept;
        NODISCARD DataFormatType GetDepthStencilFormat() const noexcept;
        NODISCARD int GetNumMultiSamples() const noexcept;

        void SetViewport(const Viewport& viewport);
        NODISCARD Viewport GetViewport() const;
        void SetDepthRange(const DepthRange& depthRange);
        NODISCARD DepthRange GetDepthRange() const;

        NODISCARD bool HasDepthRange01() const;

        NODISCARD std::string GetShaderName(const std::string& name) const;
        NODISCARD std::string GetShaderExtendName() const;

        NODISCARD void Resize(int width, int height);

        void SwapBuffers(int syncInterval);

        NODISCARD int64_t DrawPrimitive(const VertexBufferSharedPtr& vertexBuffer,
                                        const IndexBufferSharedPtr& indexBuffer,
                                        const VisualEffectSharedPtr& effect);

        void ClearColorBuffer(const RendererClear& rendererClear);
        void ClearDepthBuffer(const RendererClear& rendererClear);
        void ClearStencilBuffer(const RendererClear& rendererClear);
        void ClearBuffers(const RendererClear& rendererClear);

        void InitDevice();
        void Release();
        void ResetSize();
        void WaitForFinish();
        void Flush();
        void Execute(ComputeProgram& shared, int numXGroups, int numYGroups, int numZGroups);

        NODISCARD RendererObjectSharedPtr BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD RendererObjectSharedPtr GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        void UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject);
        NODISCARD TotalAllocation GetTotalAllocation() const;

        NODISCARD RendererDrawTargetSharedPtr BindDrawTarget(RendererTypes rendererTypes, const ConstDrawTargetSharedPtr& drawTarget, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture);
        NODISCARD bool HasDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const;
        NODISCARD RendererDrawTargetSharedPtr GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget);
        void UnbindDrawTarget(const ConstDrawTargetSharedPtr& drawTarget);

    private:
        RenderingEnvironment renderingEnvironment;
        RenderingDevice renderingDevice;
        RendererObjectBridgeSharedPtr rendererObjectBridge;
        DrawTargetBridgeSharedPtr drawTargetBridge;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERER_ADAPTER_H