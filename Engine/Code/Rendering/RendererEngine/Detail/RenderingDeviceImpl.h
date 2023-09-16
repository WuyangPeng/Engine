///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:04)

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_IMPL_H
#define RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/RendererEngine/DepthRange.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"
#include "Rendering/RendererEngine/Viewport.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE RenderingDeviceImpl
    {
    public:
        using ClassType = RenderingDeviceImpl;
        using FactoryType = RenderingDeviceFactory;

        using RenderingDeviceSharedPtr = std::shared_ptr<RenderingDeviceImpl>;
        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using IndexBufferSharedPtr = std::shared_ptr<IndexBuffer>;
        using VisualEffectSharedPtr = std::shared_ptr<VisualEffect>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstVisualEffectSharedPtr = std::shared_ptr<const VisualEffect>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;

    public:
        RenderingDeviceImpl() noexcept;
        virtual ~RenderingDeviceImpl() noexcept = default;
        RenderingDeviceImpl(const RenderingDeviceImpl& rhs) = default;
        RenderingDeviceImpl& operator=(const RenderingDeviceImpl& rhs) = default;
        RenderingDeviceImpl(RenderingDeviceImpl&& rhs) noexcept = default;
        RenderingDeviceImpl& operator=(RenderingDeviceImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual RenderingDeviceSharedPtr Clone() const = 0;
        virtual void ResetSize() = 0;
        virtual void InitDevice() = 0;
        virtual void Release() = 0;

        virtual void SwapBuffers(int syncInterval) = 0;

        void SetSize(int x, int y) noexcept;

        NODISCARD int GetXSize() const noexcept;
        NODISCARD int GetYSize() const noexcept;

        virtual void SetViewport(const Viewport& viewport) = 0;
        NODISCARD virtual Viewport GetViewport() const = 0;
        virtual void SetDepthRange(const DepthRange& depthRange) = 0;
        NODISCARD virtual DepthRange GetDepthRange() const = 0;

        NODISCARD virtual bool HasDepthRange01() const = 0;
        NODISCARD virtual std::string GetShaderName(const std::string& name) const = 0;
        NODISCARD virtual std::string GetShaderExtendName() const = 0;
        NODISCARD virtual void Resize(int width, int height) = 0;

        NODISCARD virtual int64_t DrawPrimitive(RendererObjectBridge& rendererObjectBridge,
                                                const VertexBufferSharedPtr& vertexBuffer,
                                                const IndexBufferSharedPtr& indexBuffer,
                                                const VisualEffectSharedPtr& effect) = 0;

        virtual void ClearColorBuffer(const RendererClear& rendererClear) = 0;
        virtual void ClearDepthBuffer(const RendererClear& rendererClear) = 0;
        virtual void ClearStencilBuffer(const RendererClear& rendererClear) = 0;
        virtual void ClearBuffers(const RendererClear& rendererClear) = 0;

        virtual void WaitForFinish() = 0;
        virtual void Flush() = 0;

        virtual void Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups) = 0;

    private:
        int xSize;
        int ySize;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_ENVIRONMENT_IMPL_H
