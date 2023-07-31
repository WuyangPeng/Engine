///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:34)

#ifndef RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_H
#define RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_H

#include "Rendering/RenderingDll.h"

#include "RendererEngineFwd.h"
#include "System/OpenGL/Using/WglExtensionsUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/DelayCopyUnsharedMacro.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
#include "Rendering/RendererEngine/RendererEngineInternalFwd.h"

RENDERING_DELAY_COPY_UNSHARED_EXPORT_IMPL(RenderingDevice, RenderingDeviceImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderingDevice
    {
    public:
        DELAY_COPY_UNSHARED_TYPE_DECLARE(RenderingDevice);

        using WindowsHDC = System::WindowsHDC;
        using OpenGLHglrc = System::OpenGLHglrc;
        using WindowsHWnd = System::WindowsHWnd;
        using RenderingDeviceSharedPtr = std::shared_ptr<RenderingDeviceImpl>;
        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using IndexBufferSharedPtr = std::shared_ptr<IndexBuffer>;
        using VisualEffectSharedPtr = std::shared_ptr<VisualEffect>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstVisualEffectSharedPtr = std::shared_ptr<const VisualEffect>;
        using ComputeProgramSharedPtr = std::shared_ptr<ComputeProgram>;

    public:
        RenderingDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate);
        NODISCARD static RenderingDevice Create();

        CLASS_INVARIANT_DECLARE;

        void SwapBuffers(int syncInterval);
        void ResetSize();
        void InitDevice();

        void SetViewport(const Viewport& viewport);
        NODISCARD Viewport GetViewport() const;
        void SetDepthRange(const DepthRange& depthRange);
        NODISCARD DepthRange GetDepthRange() const;

        NODISCARD bool HasDepthRange01() const;
        NODISCARD std::string GetShaderName(const std::string& name) const;
        NODISCARD std::string GetShaderExtendName() const;
        NODISCARD void Resize(int width, int height);

        NODISCARD int64_t DrawPrimitive(RendererObjectBridge& rendererObjectBridge,
                                        const VertexBufferSharedPtr& vertexBuffer,
                                        const IndexBufferSharedPtr& indexBuffer,
                                        const VisualEffectSharedPtr& effect);

        void ClearColorBuffer(const RendererClear& rendererClear);
        void ClearDepthBuffer(const RendererClear& rendererClear);
        void ClearStencilBuffer(const RendererClear& rendererClear);
        void ClearBuffers(const RendererClear& rendererClear);

        void WaitForFinish();
        void Flush();
        void Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups);

    private:
        enum class RenderingDeviceCreate
        {
            Init,
        };

    public:
        explicit RenderingDevice(RenderingDeviceCreate renderingDeviceCreate);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_RENDERING_DEVICE_H
