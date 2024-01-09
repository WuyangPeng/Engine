/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
/// ÁªÏµ×÷Õß£º94458936@qq.com
///
/// ±ê×¼£ºstd:c++20
/// °æ±¾£º1.0.0.3 (2024/01/09 10:02)

#include "Rendering/RenderingExport.h"

#include "OpenGLDevice.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/Network/SocketPrototypes.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBase.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "System/OpenGL/OpenGLProgram.h"
#include "System/OpenGL/OpenGLSamplers.h"
#include "System/OpenGL/OpenGLShader.h"
#include "System/OpenGL/OpenGLTextures.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLAtomicCounterBuffer.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLConstantBuffer.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLStructuredBuffer.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureArray.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureSingle.h"
#include "Rendering/OpenGLRenderer/State/OpenGLSamplerState.h"
#include "Rendering/RendererEngine/Detail/RendererClear.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Flags/UsageType.h"
#include "Rendering/Resources/Textures/TextureArray.h"
#include "Rendering/Shaders/ComputeProgram.h"
#include "Rendering/Shaders/Flags/ShaderDataLookup.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/Shaders/VisualProgram.h"
#include "Rendering/State/SamplerState.h"

#include <gsl/util>

Rendering::OpenGLDevice::OpenGLDevice(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{},
      openGLInputLayoutManager{ disableNotThrow },
      textureSamplerUnit{},
      textureImageUnit{},
      uniformUnit{},
      shaderStorageUnit{},
      atomicCounterRawBuffers{}
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

    System::SetGLDepthRange(depthRange.GetZMin(), depthRange.GetZMax());
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

    System::UnusedFunction(effect);

    const auto gl4Program = effect->GetProgram();
    if (gl4Program == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("A visual program must exist."))
    }

    int64_t numPixelsDrawn{};
    const auto programHandle = gl4Program->GetProgramHandle();

    System::SetUseProgram(programHandle);

    if (EnableShaders(rendererObjectBridge, *effect, programHandle))
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

        numPixelsDrawn = DrawPrimitive(*vertexBuffer, *indexBuffer);

        if (vertexBuffer->StandardUsage())
        {
            gl4Layout->Disable();
        }

        if (gl4IndexBuffer != nullptr)
        {
            gl4IndexBuffer->Disable();
        }

        DisableShaders(rendererObjectBridge, *effect, programHandle);
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

void Rendering::OpenGLDevice::Execute(RendererObjectBridge& rendererObjectBridge, ComputeProgram& computeProgram, int numXGroups, int numYGroups, int numZGroups)
{
    RENDERING_CLASS_IS_VALID_9;

    if (numXGroups > 0 && numYGroups > 0 && numZGroups > 0)
    {
        const auto computeShader = computeProgram.GetComputeShader();
        const auto programHandle = computeProgram.GetProgramHandle();
        if (computeShader && programHandle > 0)
        {
            System::SetUseProgram(programHandle);
            Enable(rendererObjectBridge, *computeShader, programHandle);
            System::SetGLDispatchCompute(numXGroups, numYGroups, numZGroups);
            Disable(rendererObjectBridge, *computeShader, programHandle);
            System::SetUseProgram(0);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Invalid input parameter."))
    }
}

bool Rendering::OpenGLDevice::EnableShaders(RendererObjectBridge& rendererObjectBridge, VisualEffect& effect, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto vertexShader = effect.GetVertexShader();
    if (vertexShader == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Effect does not have a vertex shader."))
    }

    const auto pixelShader = effect.GetPixelShader();
    if (pixelShader == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Effect does not have a pixel shader."))
    }

    const auto geometryShader = effect.GetGeometryShader();

    Enable(rendererObjectBridge, *vertexShader, program);
    Enable(rendererObjectBridge, *pixelShader, program);
    if (geometryShader != nullptr)
    {
        Enable(rendererObjectBridge, *geometryShader, program);
    }

    return true;
}

void Rendering::OpenGLDevice::DisableShaders(RendererObjectBridge& rendererObjectBridge, VisualEffect& effect, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto vertexShader = effect.GetVertexShader();
    const auto pixelShader = effect.GetPixelShader();

    if (const auto geometryShader = effect.GetGeometryShader();
        geometryShader != nullptr)
    {
        Disable(rendererObjectBridge, *geometryShader, program);
    }

    Disable(rendererObjectBridge, *vertexShader, program);
    Disable(rendererObjectBridge, *pixelShader, program);
}

void Rendering::OpenGLDevice::Enable(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    EnableConstantBuffers(rendererObjectBridge, shader, program);
    EnableStructuredBuffers(rendererObjectBridge, shader, program);
    EnableTextures(rendererObjectBridge, shader, program);
    EnableTextureArrays(rendererObjectBridge, shader, program);
    EnableSamplers(rendererObjectBridge, shader, program);
}

void Rendering::OpenGLDevice::Disable(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    DisableSamplers(rendererObjectBridge, shader, program);
    DisableTextureArrays(rendererObjectBridge, shader, program);
    DisableTextures(rendererObjectBridge, shader, program);
    DisableStructuredBuffers(rendererObjectBridge, shader, program);
    DisableConstantBuffers(shader, program);
}

void Rendering::OpenGLDevice::EnableConstantBuffers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = ConstantBuffer::GetShaderDataLookup();
         auto& constantBuffer : shader.GetData(index))
    {
        const auto constantBufferRendererObject = boost::polymorphic_pointer_cast<OpenGLConstantBuffer>(rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, constantBuffer.GetGraphicsObject()));

        if (const auto blockIndex = constantBuffer.GetBindPoint();
            gsl::narrow_cast<uint32_t>(blockIndex) != GL_INVALID_INDEX)
        {
            auto const unit = uniformUnit.AcquireUnit(program, blockIndex);
            System::SetGLUniformBlockBinding(program, blockIndex, unit);
            constantBufferRendererObject->AttachToUnit(unit);
        }
    }
}

void Rendering::OpenGLDevice::DisableConstantBuffers(Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = ConstantBuffer::GetShaderDataLookup();
         const auto& constantBuffer : shader.GetData(index))
    {
        if (const auto blockIndex = constantBuffer.GetBindPoint();
            gsl::narrow_cast<uint32_t>(blockIndex) != GL_INVALID_INDEX)
        {
            const auto unit = uniformUnit.GetUnit(program, blockIndex);
            SetGLBindBufferBase(System::BindBuffer::UniformBuffer, unit, 0);
            uniformUnit.ReleaseUnit(unit);
        }
    }
}

void Rendering::OpenGLDevice::EnableStructuredBuffers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto& atomicCounters = shader.GetData(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterShaderDataLookup));
    const auto& atomicCounterBuffers = shader.GetData(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterBufferShaderDataLookup));
    for (auto atomicCounterBufferIndex = 0u; atomicCounterBufferIndex < atomicCounterBuffers.size(); ++atomicCounterBufferIndex)
    {
        auto const& atomicCounterBuffer = atomicCounterBuffers.at(atomicCounterBufferIndex);

        if (atomicCounterRawBuffers.size() <= atomicCounterBufferIndex)
        {
            atomicCounterRawBuffers.emplace_back(nullptr);
        }

        auto& rawBuffer = atomicCounterRawBuffers.at(atomicCounterBufferIndex);

        if (rawBuffer && rawBuffer->GetNumBytes() < (atomicCounterBuffer.GetNumBytes()))
        {
            rendererObjectBridge.UnbindRendererObject(rawBuffer);
            rawBuffer = nullptr;
        }

        std::shared_ptr<OpenGLAtomicCounterBuffer> openGLAtomicCounterBuffer = nullptr;
        if (rawBuffer)
        {
            openGLAtomicCounterBuffer = boost::polymorphic_pointer_cast<OpenGLAtomicCounterBuffer>(rendererObjectBridge.GetRendererObject(rawBuffer));
        }
        else
        {
            rawBuffer = std::make_shared<RawBuffer>("RawBuffer", (atomicCounterBuffer.GetNumBytes() + 3) / 4, false);
            rawBuffer->SetUsage(UsageType::DynamicUpdate);

            openGLAtomicCounterBuffer = boost::polymorphic_pointer_cast<OpenGLAtomicCounterBuffer>(rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, rawBuffer));
        }

        openGLAtomicCounterBuffer->AttachToUnit(atomicCounterBuffer.GetBindPoint());
    }

    for (constexpr auto indexStructuredBuffer = StructuredBuffer::GetShaderDataLookup();
         auto& structuredBuffer : shader.GetData(indexStructuredBuffer))
    {
        if (structuredBuffer.GetGraphicsObject())
        {
            const auto openGLStructuredBuffer = boost::polymorphic_pointer_cast<OpenGLStructuredBuffer>(rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, structuredBuffer.GetGraphicsObject()));

            if (const auto blockIndex = structuredBuffer.GetBindPoint();
                boost::numeric_cast<uint32_t>(blockIndex) != GL_INVALID_INDEX)
            {
                const auto unit = shaderStorageUnit.AcquireUnit(program, blockIndex);
                System::SetGLShaderStorageBlockBinding(program, blockIndex, unit);

                openGLStructuredBuffer->AttachToUnit(unit);

                if (structuredBuffer.IsGpuWritable())
                {
                    if (!openGLStructuredBuffer->SetNumActiveElements())
                    {
                        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("openGLStructuredBuffer SetNumActiveElements Ê§°Ü¡£"));
                    }

                    auto const acIndex = structuredBuffer.GetExtra();

                    auto const acbIndex = atomicCounters.at(acIndex).GetBindPoint();
                    auto const acbOffset = atomicCounters.at(acIndex).GetExtra();

                    auto openGLAtomicCounterBuffer = boost::polymorphic_pointer_cast<OpenGLAtomicCounterBuffer>(rendererObjectBridge.GetRendererObject(atomicCounterRawBuffers.at(acbIndex)));

                    if (!openGLStructuredBuffer->CopyCounterValueToBuffer(openGLAtomicCounterBuffer.get(), acbOffset))
                    {
                        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("openGLStructuredBuffer CopyCounterValueToBuffer Ê§°Ü¡£"));
                    }
                }
            }
        }
    }
}

void Rendering::OpenGLDevice::DisableStructuredBuffers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto& atomicCounters = shader.GetData(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterShaderDataLookup));
    const auto& atomicCounterBuffers = shader.GetData(System::EnumCastUnderlying(ShaderDataLookup::AtomicCounterBufferShaderDataLookup));

    for (auto atomicCounterBufferIndex = 0u; atomicCounterBufferIndex < atomicCounterBuffers.size(); ++atomicCounterBufferIndex)
    {
        const auto& atomicCounterBuffer = atomicCounterBuffers.at(atomicCounterBufferIndex);
        SetGLBindBufferBase(System::BindBuffer::AtomicCounterBuffer, atomicCounterBuffer.GetBindPoint(), 0);
    }

    for (constexpr auto index = StructuredBuffer::GetShaderDataLookup();
         auto& structuredBuffer : shader.GetData(index))
    {
        if (structuredBuffer.GetGraphicsObject())
        {
            const auto openGLStructuredBuffer = boost::polymorphic_pointer_cast<OpenGLStructuredBuffer>(rendererObjectBridge.GetRendererObject(structuredBuffer.GetGraphicsObject()));

            if (const auto blockIndex = structuredBuffer.GetBindPoint();
                boost::numeric_cast<uint32_t>(blockIndex) != GL_INVALID_INDEX)
            {
                const auto unit = shaderStorageUnit.GetUnit(program, blockIndex);
                SetGLBindBufferBase(System::BindBuffer::ShaderStorageBuffer, unit, 0);
                shaderStorageUnit.ReleaseUnit(unit);

                if (structuredBuffer.IsGpuWritable())
                {
                    auto const acIndex = structuredBuffer.GetExtra();

                    auto const acbIndex = atomicCounters.at(acIndex).GetBindPoint();
                    auto const acbOffset = atomicCounters.at(acIndex).GetExtra();

                    auto openGLAtomicCounterBuffer = boost::polymorphic_pointer_cast<OpenGLAtomicCounterBuffer>(rendererObjectBridge.GetRendererObject(atomicCounterRawBuffers.at(acbIndex)));

                    if (!openGLStructuredBuffer->CopyCounterValueFromBuffer(openGLAtomicCounterBuffer.get(), acbOffset))
                    {
                        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("openGLStructuredBuffer openGLAtomicCounterBuffer Ê§°Ü¡£"));
                    }
                }
            }
        }
    }
}

void Rendering::OpenGLDevice::EnableTextures(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = TextureSingle::GetShaderDataLookup();
         auto& textureSingle : shader.GetData(index))
    {
        if (!textureSingle.GetGraphicsObject())
        {
            THROW_EXCEPTION(CoreTools::StringConversion::MultiByteConversionStandard(textureSingle.GetName() + " is null texture."));
        }

        const auto texture = boost::polymorphic_pointer_cast<OpenGLTextureSingle>(rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, textureSingle.GetGraphicsObject()));

        const auto handle = texture->GetGLHandle();
        if (textureSingle.IsGpuWritable())
        {
            const auto unit = textureImageUnit.AcquireUnit(program, textureSingle.GetBindPoint());
            System::SetGLUniform1(textureSingle.GetBindPoint(), unit);
            const auto format = texture->GetTexture()->GetFormat();
            const auto internalFormat = texture->GetGLTextureInternalFormat(format);
            SetGLBindImageTexture(unit, handle, 0, true, 0, System::BufferLocking::ReadWrite, EnumCastUnderlying(internalFormat));
        }
        else
        {
            const auto unit = textureSamplerUnit.AcquireUnit(program, textureSingle.GetBindPoint());
            System::SetGLUniform1(textureSingle.GetBindPoint(), unit);
            System::SetGLActiveTexture(EnumCastUnderlying(System::TextureNumber::Type0) + unit);
            SetGLBindTexture(texture->GetTarget(), handle);
        }
    }
}

void Rendering::OpenGLDevice::DisableTextures(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = TextureSingle::GetShaderDataLookup();
         auto& textureSingle : shader.GetData(index))
    {
        if (!textureSingle.GetGraphicsObject())
        {
            THROW_EXCEPTION(CoreTools::StringConversion::MultiByteConversionStandard(textureSingle.GetName() + " is null texture."));
        }

        const auto texture = boost::polymorphic_pointer_cast<OpenGLTextureSingle>(rendererObjectBridge.GetRendererObject(textureSingle.GetGraphicsObject()));

        if (textureSingle.IsGpuWritable())
        {
            const auto unit = textureImageUnit.GetUnit(program, textureSingle.GetBindPoint());
            textureImageUnit.ReleaseUnit(unit);
        }
        else
        {
            const auto unit = textureSamplerUnit.GetUnit(program, textureSingle.GetBindPoint());
            System::SetGLActiveTexture(EnumCastUnderlying(System::TextureNumber::Type0) + unit);
            SetGLBindTexture(texture->GetTarget(), 0);
            textureSamplerUnit.ReleaseUnit(unit);
        }
    }
}

void Rendering::OpenGLDevice::EnableTextureArrays(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = TextureArray::GetShaderDataLookup();
         auto& textureArray : shader.GetData(index))
    {
        if (!textureArray.GetGraphicsObject())
        {
            THROW_EXCEPTION(CoreTools::StringConversion::MultiByteConversionStandard(textureArray.GetName() + " is null texture array."));
        }

        const auto texture = boost::polymorphic_pointer_cast<OpenGLTextureArray>(rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, textureArray.GetGraphicsObject()));

        const auto handle = texture->GetGLHandle();
        if (textureArray.IsGpuWritable())
        {
            const auto unit = textureImageUnit.AcquireUnit(program, textureArray.GetBindPoint());
            System::SetGLUniform1(textureArray.GetBindPoint(), unit);
            const auto format = texture->GetTexture()->GetFormat();
            const auto internalFormat = texture->GetGLTextureInternalFormat(format);
            SetGLBindImageTexture(unit, handle, 0, true, 0, System::BufferLocking::ReadWrite, EnumCastUnderlying(internalFormat));
        }
        else
        {
            const auto unit = textureSamplerUnit.AcquireUnit(program, textureArray.GetBindPoint());
            System::SetGLUniform1(textureArray.GetBindPoint(), unit);
            System::SetGLActiveTexture(EnumCastUnderlying(System::TextureNumber::Type0) + unit);
            SetGLBindTexture(texture->GetTarget(), handle);
        }
    }
}

void Rendering::OpenGLDevice::DisableTextureArrays(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = TextureArray::GetShaderDataLookup();
         auto& textureArray : shader.GetData(index))
    {
        if (!textureArray.GetGraphicsObject())
        {
            THROW_EXCEPTION(CoreTools::StringConversion::MultiByteConversionStandard(textureArray.GetName() + " is null texture."));
        }

        const auto texture = boost::polymorphic_pointer_cast<OpenGLTextureArray>(rendererObjectBridge.GetRendererObject(textureArray.GetGraphicsObject()));

        if (textureArray.IsGpuWritable())
        {
            const auto unit = textureImageUnit.GetUnit(program, textureArray.GetBindPoint());
            textureImageUnit.ReleaseUnit(unit);
        }
        else
        {
            const auto unit = textureSamplerUnit.GetUnit(program, textureArray.GetBindPoint());
            System::SetGLActiveTexture(EnumCastUnderlying(System::TextureNumber::Type0) + unit);
            SetGLBindTexture(texture->GetTarget(), 0);
            textureSamplerUnit.ReleaseUnit(unit);
        }
    }
}

void Rendering::OpenGLDevice::EnableSamplers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = SamplerState::GetShaderDataLookup();
         auto& sampler : shader.GetData(index))
    {
        if (sampler.GetGraphicsObject())
        {
            const auto openGLSamplerState = boost::polymorphic_pointer_cast<OpenGLSamplerState>(rendererObjectBridge.BindRendererObject(RendererTypes::OpenGL, sampler.GetGraphicsObject()));

            const auto location = sampler.GetBindPoint();
            const auto unit = textureSamplerUnit.AcquireUnit(program, location);
            System::SetGLBindSampler(unit, openGLSamplerState->GetGLHandle());
        }
    }
}

void Rendering::OpenGLDevice::DisableSamplers(RendererObjectBridge& rendererObjectBridge, Shader& shader, OpenGLUInt program)
{
    RENDERING_CLASS_IS_VALID_9;

    for (constexpr auto index = SamplerState::GetShaderDataLookup();
         auto& sampler : shader.GetData(index))
    {
        if (sampler.GetGraphicsObject())
        {
            const auto openGLSamplerState = boost::polymorphic_pointer_cast<OpenGLSamplerState>(rendererObjectBridge.GetRendererObject(sampler.GetGraphicsObject()));

            const auto location = sampler.GetBindPoint();
            const auto unit = textureSamplerUnit.AcquireUnit(program, location);
            System::SetGLBindSampler(unit, 0);
            textureSamplerUnit.ReleaseUnit(unit);
        }
    }
}

int64_t Rendering::OpenGLDevice::DrawPrimitive(const VertexBuffer& vertexBuffer, const IndexBuffer& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto numActiveVertices = vertexBuffer.GetNumActiveElements();
    const auto vertexOffset = vertexBuffer.GetOffset();

    const auto numActiveIndices = indexBuffer.GetNumActiveIndices();
    const auto indexSize = indexBuffer.GetElementSize();
    const auto indexType = (indexSize == 4 ? System::OpenGLData::UnsignedInt : System::OpenGLData::UnsignedShort);

    auto topology = System::PrimitiveType::Point;

    switch (const auto type = indexBuffer.GetPrimitiveType();
            type)
    {
        case IndexFormatType::PolygonPoint:
            topology = System::PrimitiveType::Point;
            break;
        case IndexFormatType::PolygonSegmentDisjoint:
            topology = System::PrimitiveType::Lines;
            break;
        case IndexFormatType::PolygonSegmentContiguous:
            topology = System::PrimitiveType::LinesStrip;
            break;
        case IndexFormatType::TriangleMesh:
            topology = System::PrimitiveType::Triangles;
            break;
        case IndexFormatType::TriangleStrip:
            topology = System::PrimitiveType::TrianglesStrip;
            break;
        case IndexFormatType::PolygonSegmentDisjointAdjacency:
            topology = System::PrimitiveType::LinesAdjacency;
            break;
        case IndexFormatType::PolygonSegmentContiguousAdjacency:
            topology = System::PrimitiveType::LinesStripAdjacency;
            break;
        case IndexFormatType::TriangleMeshAdjacency:
            topology = System::PrimitiveType::TrianglesAdjacency;
            break;
        case IndexFormatType::TriangleStripAdjacency:
            topology = System::PrimitiveType::TrianglesStripAdjacency;
            break;
        default:
            THROW_EXCEPTION(SYSTEM_TEXT("Unknown primitive topology = " + System::ToString(System::EnumCastUnderlying(type))))
    }

    const auto offset = indexBuffer.GetOffset();
    if (indexBuffer.IsIndexed())
    {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)

        const auto* data = reinterpret_cast<const void*>(gsl::narrow_cast<size_t>(indexSize) * gsl::narrow_cast<size_t>(offset));

#include SYSTEM_WARNING_POP

        SetGLDrawRangeElements(topology, 0, numActiveVertices - 1, numActiveIndices, indexType, data);
    }
    else
    {
        SetGLDrawArrays(topology, vertexOffset, numActiveVertices);
    }

    return 0;
}
