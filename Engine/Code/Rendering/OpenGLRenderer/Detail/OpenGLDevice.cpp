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
#include "System/Network/SocketPrototypes.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/RendererEngine/Detail/RendererClear.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Shaders/VisualProgram.h"

#include <gsl/util>

Rendering::OpenGLDevice::OpenGLDevice(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, openGLInputLayoutManager{ disableNotThrow }
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

void Rendering::OpenGLDevice::Release() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    openGLInputLayoutManager.UnbindAll();
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

std::string Rendering::OpenGLDevice::GetShaderExtendName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ".glsl";
}

void Rendering::OpenGLDevice::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    std::array<System::OpenGLInt, 4> viewport{};
    GetGLInteger(System::OpenGLQuery::Viewport, viewport.data());

    System::SetGLViewport(viewport.at(0), viewport.at(1), width, height);
}

int64_t Rendering::OpenGLDevice::DrawPrimitive(RendererObjectBridge& rendererObjectBridge, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer, const VisualEffectSharedPtr& effect)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(vertexBuffer, indexBuffer, effect);

    const auto gl4Program = effect->GetProgram();
    if (gl4Program == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("A visual program must exist."))
    }

    int64_t numPixelsDrawn{};
    const auto programHandle = gl4Program->GetProgramHandle();

    System::SetUseProgram(programHandle);

    if (EnableShaders(*effect, programHandle))
    {
        RendererObjectBridge::RendererObjectSharedPtr gl4VertexBuffer{};
        OpenGLInputLayoutManager::OpenGLInputLayoutSharedPtr gl4Layout{};
        if (vertexBuffer->StandardUsage())
        {
            gl4VertexBuffer = rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, vertexBuffer);

            gl4Layout = openGLInputLayoutManager.Bind(programHandle, gl4VertexBuffer->GetGLHandle(), vertexBuffer);
            gl4Layout->Enable();
        }

        RendererObjectBridge::RendererObjectSharedPtr gl4IndexBuffer{};
        if (indexBuffer != nullptr)
        {
            gl4IndexBuffer = rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, indexBuffer);
            gl4IndexBuffer->Enable();
        }

        numPixelsDrawn = DrawPrimitive(vertexBuffer, indexBuffer);

        if (vertexBuffer->StandardUsage())
        {
            gl4Layout->Disable();
        }

        if (gl4IndexBuffer != nullptr)
        {
            gl4IndexBuffer->Disable();
        }

        DisableShaders(*effect, programHandle);
    }

    System::SetUseProgram(0);

    return numPixelsDrawn;
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

bool Rendering::OpenGLDevice::EnableShaders(VisualEffect& effect, OpenGLUInt program)
{
    auto vertexShader = effect.GetVertexShader();
    if (vertexShader == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Effect does not have a vertex shader."))
    }

    auto pixelShader = effect.GetPixelShader();
    if (pixelShader == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Effect does not have a pixel shader."))
    }

    auto geometryShader = effect.GetGeometryShader();

    Enable(*vertexShader, program);
    Enable(*pixelShader, program);
    if (geometryShader != nullptr)
    {
        Enable(*geometryShader, program);
    }

    return true;
}

void Rendering::OpenGLDevice::DisableShaders(VisualEffect& effect, OpenGLUInt program) noexcept
{
    auto vertexShader = effect.GetVertexShader();
    auto pixelShader = effect.GetPixelShader();
    auto geometryShader = effect.GetGeometryShader();

    if (geometryShader != nullptr)
    {
        Disable(*geometryShader, program);
    }
    Disable(*vertexShader, program);
    Disable(*pixelShader, program);
}

void Rendering::OpenGLDevice::Enable(const Shader& shader, OpenGLUInt program) noexcept
{
    EnableConstantBuffers(shader, program);
    EnableSBuffers(shader, program);
    EnableTextures(shader, program);
    EnableTextureArrays(shader, program);
    EnableSamplers(shader, program);
}

void Rendering::OpenGLDevice::Disable(const Shader& shader, OpenGLUInt program) noexcept
{
    DisableSamplers(shader, program);
    DisableTextureArrays(shader, program);
    DisableTextures(shader, program);
    DisableSBuffers(shader, program);
    DisableConstantBuffers(shader, program);
}

void Rendering::OpenGLDevice::EnableConstantBuffers(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::DisableConstantBuffers(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::EnableSBuffers(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::DisableSBuffers(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::EnableTextures(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::DisableTextures(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::EnableTextureArrays(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::DisableTextureArrays(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::EnableSamplers(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

void Rendering::OpenGLDevice::DisableSamplers(const Shader& shader, OpenGLUInt program) noexcept
{
    System::UnusedFunction(shader, program);
}

int64_t Rendering::OpenGLDevice::DrawPrimitive(const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer)
{
    System::UnusedFunction(vertexBuffer, indexBuffer);

    const auto numActiveVertices = vertexBuffer->GetNumActiveElements();
    const auto vertexOffset = vertexBuffer->GetOffset();

    const auto numActiveIndices = indexBuffer->GetNumActiveIndices();
    const auto indexSize = indexBuffer->GetElementSize();
    const auto indexType = (indexSize == 4 ? System::OpenGLData::UnsignedInt : System::OpenGLData::UnsignedShort);

    auto topology = System::PrimitiveType::Point;

    switch (const auto type = indexBuffer->GetPrimitiveType();
            type)
    {
        case IndexFormatType::PolyPoint:
            topology = System::PrimitiveType::Point;
            break;
        case IndexFormatType::PolySegmentDisjoint:
            topology = System::PrimitiveType::Lines;
            break;
        case IndexFormatType::PolySegmentContiguous:
            topology = System::PrimitiveType::LinesStrip;
            break;
        case IndexFormatType::TriMesh:
            topology = System::PrimitiveType::Triangles;
            break;
        case IndexFormatType::TriStrip:
            topology = System::PrimitiveType::TrianglesStrip;
            break;
        case IndexFormatType::PolySegmentDisjointAdj:
            topology = System::PrimitiveType::LinesAdjacency;
            break;
        case IndexFormatType::PolySegmentContiguousAdj:
            topology = System::PrimitiveType::LinesStripAdjacency;
            break;
        case IndexFormatType::TriMeshAdj:
            topology = System::PrimitiveType::TrianglesAdjacency;
            break;
        case IndexFormatType::TriStripAdj:
            topology = System::PrimitiveType::TrianglesStripAdjacency;
            break;
        default:
            THROW_EXCEPTION(SYSTEM_TEXT("Unknown primitive topology = " + System::ToString(System::EnumCastUnderlying(type))))
    }

    const auto offset = indexBuffer->GetOffset();
    if (indexBuffer != nullptr)
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto* data = reinterpret_cast<const void*>(gsl::narrow_cast<size_t>(indexSize) * gsl::narrow_cast<size_t>(offset));

#include SYSTEM_WARNING_POP

        System::SetGLDrawRangeElements(topology, 0, numActiveVertices - 1, numActiveIndices, indexType, data);
    }
    else
    {
        System::SetGLDrawArrays(topology, vertexOffset, numActiveVertices);
    }
    return 0;
}
