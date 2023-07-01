///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 14:43)

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

void Rendering::NullDevice::Resize(int width, int height) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(width, height);
}

int64_t Rendering::NullDevice::DrawPrimitive(const ConstVertexBufferSharedPtr& vertexBuffer, const ConstIndexBufferSharedPtr& indexBuffer, const ConstVisualEffectSharedPtr& effect) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(vertexBuffer, indexBuffer, effect);

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

void Rendering::NullDevice::Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(computeProgram, numXGroups, numYGroups, numZGroups);
}
