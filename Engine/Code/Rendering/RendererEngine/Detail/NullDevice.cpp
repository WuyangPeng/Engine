/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/02 16:12)

#include "Rendering/RenderingExport.h"

#include "NullDevice.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::NullDevice::NullDevice() noexcept
    : ParentType{},
      nullViewport{ 0, 0, 1024, 768 },
      nullDepthRange{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, NullDevice)

Rendering::NullDevice::RenderingDeviceSharedPtr Rendering::NullDevice::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::NullDevice::SwapBuffers(int syncInterval) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(syncInterval);
}

void Rendering::NullDevice::ResetSize() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::InitDevice() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::Release() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::SetViewport(const Viewport& viewport) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    nullViewport = viewport;
}

Rendering::Viewport Rendering::NullDevice::GetViewport() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return nullViewport;
}

void Rendering::NullDevice::SetDepthRange(const DepthRange& depthRange) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    nullDepthRange = depthRange;
}

Rendering::DepthRange Rendering::NullDevice::GetDepthRange() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return nullDepthRange;
}

bool Rendering::NullDevice::HasDepthRange01() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return true;
}

std::string Rendering::NullDevice::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name + ".hlsl";
}

std::string Rendering::NullDevice::GetShaderExtendName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ".hlsl";
}

void Rendering::NullDevice::Resize(int width, int height) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(width, height);
}

int64_t Rendering::NullDevice::DrawPrimitive(RendererObjectBridge& rendererObjectBridge, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer, const VisualEffectSharedPtr& effect) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererObjectBridge, vertexBuffer, indexBuffer, effect);

    return 0;
}

void Rendering::NullDevice::ClearColorBuffer(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererClear);
}

void Rendering::NullDevice::ClearDepthBuffer(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererClear);
}

void Rendering::NullDevice::ClearStencilBuffer(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererClear);
}

void Rendering::NullDevice::ClearBuffers(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererClear);
}

void Rendering::NullDevice::WaitForFinish() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::Flush() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::NullDevice::Execute(RendererObjectBridge& rendererObjectBridge, ComputeProgram& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererObjectBridge, computeProgram, numXGroups, numYGroups, numZGroups);
}
