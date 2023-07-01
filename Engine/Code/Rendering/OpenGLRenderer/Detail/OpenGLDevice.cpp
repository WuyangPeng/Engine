///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:58)

#include "Rendering/RenderingExport.h"

#include "OpenGLDevice.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/RendererEngine/Detail/RendererClear.h"

Rendering::OpenGLDevice::OpenGLDevice() noexcept
    : ParentType{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLDevice)

Rendering::OpenGLDevice::RenderingDeviceSharedPtr Rendering::OpenGLDevice::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

void Rendering::OpenGLDevice::SwapBuffers(int syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(syncInterval);

    CoreTools::DisableNoexcept();
}

void Rendering::OpenGLDevice::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    CoreTools::DisableNoexcept();
}

void Rendering::OpenGLDevice::InitDevice() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLViewport(0, 0, GetXSize(), GetYSize());
    System::SetGLDepthRange(0.0, 1.0);
}

void Rendering::OpenGLDevice::SetViewport(const Viewport& viewport) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLViewport(viewport.GetXPosition(), viewport.GetYPosition(), viewport.GetWidth(), viewport.GetHeight());
}

Rendering::Viewport Rendering::OpenGLDevice::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    std::array<System::OpenGLInt, 4> viewport{};
    GetGLInteger(System::OpenGLQuery::Viewport, viewport.data());

    return Viewport{ viewport.at(0), viewport.at(1), viewport.at(2), viewport.at(3) };
}

void Rendering::OpenGLDevice::SetDepthRange(const DepthRange& depthRange) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLDepthRange(static_cast<GLdouble>(depthRange.GetZMin()), static_cast<GLdouble>(depthRange.GetZMax()));
}

Rendering::DepthRange Rendering::OpenGLDevice::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    std::array<System::OpenGLDouble, 1> depthRange{};
    GetGLDouble(System::OpenGLQuery::DepthRange, depthRange.data());

    return DepthRange{ boost::numeric_cast<float>(depthRange.at(0)), boost::numeric_cast<float>(depthRange.at(1)) };
}

bool Rendering::OpenGLDevice::HasDepthRange01() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return false;
}

std::string Rendering::OpenGLDevice::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name + ".glsl";
}

void Rendering::OpenGLDevice::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    std::array<System::OpenGLInt, 4> viewport{};
    GetGLInteger(System::OpenGLQuery::Viewport, viewport.data());

    System::SetGLViewport(viewport.at(0), viewport.at(1), width, height);
}

int64_t Rendering::OpenGLDevice::DrawPrimitive(const ConstVertexBufferSharedPtr& vertexBuffer, const ConstIndexBufferSharedPtr& indexBuffer, const ConstVisualEffectSharedPtr& effect) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(vertexBuffer, indexBuffer, effect);

    return 0;
}

void Rendering::OpenGLDevice::ClearColorBuffer(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    const auto clearColor = rendererClear.GetClearColor();

    System::SetGLClearColor(clearColor.GetRed(), clearColor.GetGreen(), clearColor.GetBlue(), clearColor.GetAlpha());
    SetGLClear(System::OpenGLClearMask::ColorBufferBit);
}

void Rendering::OpenGLDevice::ClearDepthBuffer(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLClearDepth(rendererClear.GetClearDepth());
    SetGLClear(System::OpenGLClearMask::DepthBufferBit);
}

void Rendering::OpenGLDevice::ClearStencilBuffer(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLClearStencil(rendererClear.GetClearStencil());
    SetGLClear(System::OpenGLClearMask::StencilBufferBit);
}

void Rendering::OpenGLDevice::ClearBuffers(const RendererClear& rendererClear) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    const auto clearColor = rendererClear.GetClearColor();

    System::SetGLClearColor(clearColor.GetRed(), clearColor.GetGreen(), clearColor.GetRed(), clearColor.GetAlpha());
    System::SetGLClearDepth(rendererClear.GetClearDepth());
    System::SetGLClearStencil(rendererClear.GetClearStencil());
    System::ClearAllGLBufferBit();
}

void Rendering::OpenGLDevice::WaitForFinish() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLDevice::Flush() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLFlush();
}

void Rendering::OpenGLDevice::Execute(const ComputeProgramSharedPtr& computeProgram, int numXGroups, int numYGroups, int numZGroups) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(computeProgram, numXGroups, numYGroups, numZGroups);
}
