///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 14:58)

#include "Rendering/RenderingExport.h"

#include "RendererAdapter.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Base/DrawTargetBridge.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/Base/TotalAllocation.h"

Rendering::RendererAdapter::RendererAdapter(const RenderingEnvironment& renderingEnvironment)
    : renderingEnvironment{ renderingEnvironment },
      renderingDevice{ renderingEnvironment.GetRenderingDevice() },
      rendererObjectBridge{ RendererObjectBridge::Create() },
      drawTargetBridge{ DrawTargetBridge::Create() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererAdapter)

Rendering::RendererAdapter::RendererObjectBridgeSharedPtr Rendering::RendererAdapter::GetRendererObjectBridge() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererObjectBridge;
}

Rendering::RendererAdapter::DrawTargetBridgeSharedPtr Rendering::RendererAdapter::GetDrawTargetBridge() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return drawTargetBridge;
}

int Rendering::RendererAdapter::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingEnvironment.GetWidth();
}

int Rendering::RendererAdapter::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingEnvironment.GetHeight();
}

Rendering::DataFormatType Rendering::RendererAdapter::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingEnvironment.GetColorFormat();
}

Rendering::DataFormatType Rendering::RendererAdapter::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingEnvironment.GetDepthStencilFormat();
}

int Rendering::RendererAdapter::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingEnvironment.GetNumMultiSamples();
}

void Rendering::RendererAdapter::SetViewport(const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    return renderingDevice.SetViewport(viewport);
}

Rendering::Viewport Rendering::RendererAdapter::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingDevice.GetViewport();
}

void Rendering::RendererAdapter::SetDepthRange(const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    return renderingDevice.SetDepthRange(depthRange);
}

Rendering::DepthRange Rendering::RendererAdapter::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingDevice.GetDepthRange();
}

bool Rendering::RendererAdapter::HasDepthRange01() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingDevice.HasDepthRange01();
}

std::string Rendering::RendererAdapter::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingDevice.GetShaderName(name);
}

std::string Rendering::RendererAdapter::GetShaderExtendName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return renderingDevice.GetShaderExtendName();
}

void Rendering::RendererAdapter::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    return renderingDevice.Resize(width, height);
}

void Rendering::RendererAdapter::SwapBuffers(int syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.SwapBuffers(syncInterval);
}

int64_t Rendering::RendererAdapter::DrawPrimitive(const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer, const VisualEffectSharedPtr& effect)
{
    RENDERING_CLASS_IS_VALID_9;

    return renderingDevice.DrawPrimitive(*rendererObjectBridge, vertexBuffer, indexBuffer, effect);
}

void Rendering::RendererAdapter::Release()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererObjectBridge->Release();
    renderingEnvironment.Release();
}

void Rendering::RendererAdapter::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.ResetSize();
}

void Rendering::RendererAdapter::InitDevice()
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.InitDevice();
}

void Rendering::RendererAdapter::ClearColorBuffer(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.ClearColorBuffer(rendererClear);
}

void Rendering::RendererAdapter::ClearDepthBuffer(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.ClearDepthBuffer(rendererClear);
}

void Rendering::RendererAdapter::ClearStencilBuffer(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.ClearStencilBuffer(rendererClear);
}

void Rendering::RendererAdapter::ClearBuffers(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.ClearBuffers(rendererClear);
}

void Rendering::RendererAdapter::WaitForFinish()
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.WaitForFinish();
}

void Rendering::RendererAdapter::Flush()
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.Flush();
}

void Rendering::RendererAdapter::Execute(const std::shared_ptr<ComputeProgram>& shared, int numXGroups, int numYGroups, int numZGroups)
{
    RENDERING_CLASS_IS_VALID_9;

    renderingDevice.Execute(shared, numXGroups, numYGroups, numZGroups);
}

Rendering::RendererAdapter::RendererObjectSharedPtr Rendering::RendererAdapter::BindRendererObject(RendererTypes rendererTypes, const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererObjectBridge->BindRendererObject(rendererTypes, graphicsObject);
}

Rendering::RendererAdapter::RendererObjectSharedPtr Rendering::RendererAdapter::GetRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererObjectBridge->GetRendererObject(graphicsObject);
}

void Rendering::RendererAdapter::UnbindRendererObject(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererObjectBridge->UnbindRendererObject(graphicsObject);
}

Rendering::TotalAllocation Rendering::RendererAdapter::GetTotalAllocation() const
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererObjectBridge->GetTotalAllocation();
}

Rendering::RendererAdapter::RendererDrawTargetSharedPtr Rendering::RendererAdapter::BindDrawTarget(RendererTypes rendererTypes, const ConstDrawTargetSharedPtr& drawTarget, const RendererObjectContainer& renderTargetTextures, const RendererObjectSharedPtr& depthStencilTexture)
{
    RENDERING_CLASS_IS_VALID_9;

    return drawTargetBridge->BindDrawTarget(rendererTypes, drawTarget, renderTargetTextures, depthStencilTexture);
}

bool Rendering::RendererAdapter::HasDrawTarget(const ConstDrawTargetSharedPtr& drawTarget) const
{
    RENDERING_CLASS_IS_VALID_9;

    return drawTargetBridge->HasDrawTarget(drawTarget);
}

Rendering::RendererAdapter::RendererDrawTargetSharedPtr Rendering::RendererAdapter::GetDrawTarget(const ConstDrawTargetSharedPtr& drawTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    return drawTargetBridge->GetDrawTarget(drawTarget);
}

void Rendering::RendererAdapter::UnbindDrawTarget(const ConstDrawTargetSharedPtr& drawTarget)
{
    RENDERING_CLASS_IS_VALID_9;

    return drawTargetBridge->UnbindDrawTarget(drawTarget);
}
