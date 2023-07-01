///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:35)

#include "Rendering/RenderingExport.h"

#include "RenderingDevice.h"
#include "Detail/RenderingDeviceFactory.h"
#include "Detail/RenderingDeviceImpl.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, RenderingDevice)

Rendering::RenderingDevice::RenderingDevice(WindowsHWnd hWnd, WindowsHDC device, OpenGLHglrc immediate)
    : impl{ CoreTools::ImplCreateUseFactory::Default, hWnd, device, immediate }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RenderingDevice Rendering::RenderingDevice::Create()
{
    return RenderingDevice{ RenderingDeviceCreate::Init };
}

Rendering::RenderingDevice::RenderingDevice(RenderingDeviceCreate renderingDeviceCreate)
    : impl{ CoreTools::ImplCreateUseFactory::Default }
{
    System::UnusedFunction(renderingDeviceCreate);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingDevice)

void Rendering::RenderingDevice::SwapBuffers(int syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SwapBuffers(syncInterval);
}

void Rendering::RenderingDevice::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->ResetSize();
}

void Rendering::RenderingDevice::InitDevice()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->InitDevice();
}

void Rendering::RenderingDevice::SetViewport(const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetViewport(viewport);
}

Rendering::Viewport Rendering::RenderingDevice::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetViewport();
}

void Rendering::RenderingDevice::SetDepthRange(const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDepthRange(depthRange);
}

Rendering::DepthRange Rendering::RenderingDevice::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthRange();
}

bool Rendering::RenderingDevice::HasDepthRange01() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasDepthRange01();
}

std::string Rendering::RenderingDevice::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetShaderName(name);
}

void Rendering::RenderingDevice::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Resize(width, height);
}

int64_t Rendering::RenderingDevice::DrawPrimitive(const ConstVertexBufferSharedPtr& vertexBuffer, const ConstIndexBufferSharedPtr& indexBuffer, const ConstVisualEffectSharedPtr& effect)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->DrawPrimitive(vertexBuffer, indexBuffer, effect);
}

void Rendering::RenderingDevice::ClearColorBuffer(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearColorBuffer(rendererClear);
}

void Rendering::RenderingDevice::ClearDepthBuffer(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearDepthBuffer(rendererClear);
}

void Rendering::RenderingDevice::ClearStencilBuffer(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearStencilBuffer(rendererClear);
}

void Rendering::RenderingDevice::ClearBuffers(const RendererClear& rendererClear)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearBuffers(rendererClear);
}

void Rendering::RenderingDevice::WaitForFinish()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->WaitForFinish();
}

void Rendering::RenderingDevice::Flush()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Flush();
}

void Rendering::RenderingDevice::Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Execute(computeProgram, numXGroups, numYGroups, numZGroups);
}
