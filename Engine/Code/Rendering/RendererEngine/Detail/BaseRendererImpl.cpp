///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 12:31)

#include "Rendering/RenderingExport.h"

#include "BaseRendererImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Base/DrawTargetBridge.h"
#include "Rendering/Base/RendererObject.h"
#include "Rendering/Base/RendererObjectBridge.h"
#include "Rendering/Base/TotalAllocation.h"
#include "Rendering/LocalEffects/Flags/FontFlags.h"
#include "Rendering/LocalEffects/Font.h"
#include "Rendering/LocalEffects/OverlayEffect.h"
#include "Rendering/LocalEffects/TextEffect.h"
#include "Rendering/Resources/Buffers/Buffer.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/StructuredBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Textures/Texture.h"
#include "Rendering/Resources/Textures/TextureArray.h"
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/Shaders/ProgramFactory.h"
#include "Rendering/Shaders/Shader.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/DepthStencilState.h"
#include "Rendering/State/RasterizerState.h"

Rendering::BaseRendererImpl::BaseRendererImpl(RendererTypes rendererTypes, const RenderingEnvironment& renderingEnvironment)
    : rendererTypes{ rendererTypes },
      rendererAdapter{ renderingEnvironment },
      rendererClear{},
      globalFont{ CreateGlobalFont(rendererTypes, rendererAdapter) },
      globalState{ rendererTypes, "BlendState", "DepthStencilState", "RasterizerState", rendererAdapter.GetRendererObjectBridge() },
      allowOcclusionQuery{ false }
{
    rendererClear.SetClearColor(renderingEnvironment.GetClearColor());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GlobalFont Rendering::BaseRendererImpl::CreateGlobalFont(RendererTypes rendererTypes, const RendererAdapter& rendererAdapter)
{
    ProgramFactory programFactory{ rendererTypes };

    return GlobalFont{ FontType::ArialW400H18, programFactory, rendererAdapter.GetShaderExtendName(), 256 };
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BaseRendererImpl)

Rendering::RendererTypes Rendering::BaseRendererImpl::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererTypes;
}

int Rendering::BaseRendererImpl::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetWidth();
}

int Rendering::BaseRendererImpl::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetHeight();
}

Rendering::DataFormatType Rendering::BaseRendererImpl::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetColorFormat();
}

Rendering::DataFormatType Rendering::BaseRendererImpl::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetDepthStencilFormat();
}

int Rendering::BaseRendererImpl::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetNumMultiSamples();
}

void Rendering::BaseRendererImpl::SetViewport(const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.SetViewport(viewport);
}

Rendering::Viewport Rendering::BaseRendererImpl::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetViewport();
}

void Rendering::BaseRendererImpl::SetDepthRange(const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.SetDepthRange(depthRange);
}

Rendering::DepthRange Rendering::BaseRendererImpl::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetDepthRange();
}

bool Rendering::BaseRendererImpl::HasDepthRange01() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.HasDepthRange01();
}

std::string Rendering::BaseRendererImpl::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetShaderName(name);
}

void Rendering::BaseRendererImpl::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.Resize(width, height);
}

void Rendering::BaseRendererImpl::SetClearColor(const Colour& clearColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rendererClear.SetClearColor(clearColor);
}

Rendering::BaseRendererImpl::Colour Rendering::BaseRendererImpl::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererClear.GetClearColor();
}

void Rendering::BaseRendererImpl::SetClearDepth(float clearDepth) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rendererClear.SetClearDepth(clearDepth);
}

float Rendering::BaseRendererImpl::GetClearDepth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererClear.GetClearDepth();
}

void Rendering::BaseRendererImpl::SetClearStencil(int clearStencil) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    rendererClear.SetClearStencil(clearStencil);
}

int Rendering::BaseRendererImpl::GetClearStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererClear.GetClearStencil();
}

void Rendering::BaseRendererImpl::DisplayColorBuffer(int syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.SwapBuffers(syncInterval);
}

void Rendering::BaseRendererImpl::Unbind(Font* currentActiveFont) noexcept
{
    /// 销毁GPU内存中的字体资源。
    /// 只有在创建defaultFont时，activeFont才应为null。
    if (currentActiveFont != nullptr)
    {
        using UnbindGraphicsObjectFuncType = void (ClassType::*)(const GraphicsObjectSharedPtr&);

        CoreTools::NoexceptNoReturn<ClassType, UnbindGraphicsObjectFuncType>(*this, &ClassType::Unbind, currentActiveFont->GetVertexBuffer());
        CoreTools::NoexceptNoReturn<ClassType, UnbindGraphicsObjectFuncType>(*this, &ClassType::Unbind, currentActiveFont->GetIndexBuffer());
        CoreTools::NoexceptNoReturn<ClassType, UnbindGraphicsObjectFuncType>(*this, &ClassType::Unbind, currentActiveFont->GetTextEffect()->GetTranslate());
        CoreTools::NoexceptNoReturn<ClassType, UnbindGraphicsObjectFuncType>(*this, &ClassType::Unbind, currentActiveFont->GetTextEffect()->GetColor());
        CoreTools::NoexceptNoReturn<ClassType, UnbindGraphicsObjectFuncType>(*this, &ClassType::Unbind, currentActiveFont->GetTextEffect()->GetVertexShader());
        CoreTools::NoexceptNoReturn<ClassType, UnbindGraphicsObjectFuncType>(*this, &ClassType::Unbind, currentActiveFont->GetTextEffect()->GetPixelShader());
    }
}

void Rendering::BaseRendererImpl::SetFont(const FontSharedPtr& font)
{
    RENDERING_CLASS_IS_VALID_9;

    if (font == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的字体为空。"))
    }

    if (const auto currentActiveFont = GetFont();
        font != currentActiveFont)
    {
        // 在GPU内存中创建字体资源。
        Bind(*font);

        globalFont.SetFont(font);

        Unbind(currentActiveFont.get());
    }
}

void Rendering::BaseRendererImpl::Bind(Font& font)
{
    Bind(font.GetVertexBuffer());
    Bind(font.GetIndexBuffer());
    Bind(font.GetTextEffect()->GetTranslate());
    Bind(font.GetTextEffect()->GetColor());
    Bind(font.GetTextEffect()->GetVertexShader());
    Bind(font.GetTextEffect()->GetPixelShader());
}

Rendering::BaseRendererImpl::FontSharedPtr Rendering::BaseRendererImpl::GetFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalFont.GetFont();
}

void Rendering::BaseRendererImpl::SetDefaultFont()
{
    RENDERING_CLASS_IS_VALID_9;

    globalFont.SetDefaultFont();
}

Rendering::BaseRendererImpl::FontSharedPtr Rendering::BaseRendererImpl::GetDefaultFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalFont.GetDefaultFont();
}

void Rendering::BaseRendererImpl::SetBlendState(const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    if (state != nullptr)
    {
        if (state != GetBlendState())
        {
            const auto bindState = rendererAdapter.BindRendererObject(rendererTypes, state);
            bindState->Enable();
            globalState.SetActiveBlendState(state);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的状态是空。"))
    }
}

Rendering::BaseRendererImpl::BlendStateSharedPtr Rendering::BaseRendererImpl::GetBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalState.GetActiveBlendState();
}

Rendering::BaseRendererImpl::BlendStateSharedPtr Rendering::BaseRendererImpl::GetDefaultBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalState.GetDefaultBlendState();
}

void Rendering::BaseRendererImpl::SetDefaultBlendState()
{
    RENDERING_CLASS_IS_VALID_9;

    return globalState.SetDefaultBlendState();
}

void Rendering::BaseRendererImpl::SetDepthStencilState(const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    if (state != nullptr)
    {
        if (state != GetDepthStencilState())
        {
            const auto bindState = rendererAdapter.BindRendererObject(rendererTypes, state);
            bindState->Enable();
            globalState.SetActiveDepthStencilState(state);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的状态是空。"))
    }
}

Rendering::BaseRendererImpl::DepthStencilStateSharedPtr Rendering::BaseRendererImpl::GetDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalState.GetActiveDepthStencilState();
}

Rendering::BaseRendererImpl::DepthStencilStateSharedPtr Rendering::BaseRendererImpl::GetDefaultDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalState.GetDefaultDepthStencilState();
}

void Rendering::BaseRendererImpl::SetRasterizerState(const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    if (state != nullptr)
    {
        if (state != GetRasterizerState())
        {
            const auto bindState = rendererAdapter.BindRendererObject(rendererTypes, state);
            bindState->Enable();
            globalState.SetActiveRasterizerState(state);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的状态是空。"))
    }
}

Rendering::BaseRendererImpl::RasterizerStateSharedPtr Rendering::BaseRendererImpl::GetRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalState.GetActiveRasterizerState();
}

Rendering::BaseRendererImpl::RasterizerStateSharedPtr Rendering::BaseRendererImpl::GetDefaultRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return globalState.GetDefaultRasterizerState();
}

void Rendering::BaseRendererImpl::InitDevice()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.InitDevice();
    globalState.CreateDefaultGlobalState();
}

void Rendering::BaseRendererImpl::Release()
{
    RENDERING_CLASS_IS_VALID_9;

    globalState.DestroyDefaultGlobalState();
    rendererAdapter.Release();
}

void Rendering::BaseRendererImpl::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.ResetSize();
}

void Rendering::BaseRendererImpl::ClearColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.ClearColorBuffer(rendererClear);
}

void Rendering::BaseRendererImpl::ClearDepthBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.ClearDepthBuffer(rendererClear);
}

void Rendering::BaseRendererImpl::ClearStencilBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.ClearStencilBuffer(rendererClear);
}

void Rendering::BaseRendererImpl::ClearBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.ClearBuffers(rendererClear);
}

int64_t Rendering::BaseRendererImpl::Draw(Visual& visual)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto vertexBuffer = visual.GetVertexBuffer();
    const auto indexBuffer = visual.GetIndexBuffer();
    const auto effect = visual.GetEffect();

    return DrawPrimitive(vertexBuffer, indexBuffer, effect);
}

int64_t Rendering::BaseRendererImpl::Draw(const VisualContainer& visuals)
{
    RENDERING_CLASS_IS_VALID_9;

    auto numPixelsDrawn = 0LL;
    for (const auto& visual : visuals)
    {
        numPixelsDrawn += Draw(*visual);
    }

    return numPixelsDrawn;
}

void Rendering::BaseRendererImpl::Update(Font& activeFont)
{
    if (!Update(activeFont.GetTextEffect()->GetTranslate()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("Translate Update Fail"));
    }

    if (!Update(activeFont.GetTextEffect()->GetColor()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("Color Update Fail"));
    }

    if (!Update(activeFont.GetVertexBuffer()))
    {
        LOG_SINGLETON_ENGINE_APPENDER(Info, Rendering, SYSTEM_TEXT("VertexBuffer Update Fail"));
    }
}

int64_t Rendering::BaseRendererImpl::SetState(Font& activeFont)
{
    // 我们需要恢复文本绘图的默认状态。记住当前状态，以便我们可以在绘制后重置它。
    const auto currentBlendState = GetBlendState();
    const auto currentDepthStencilState = GetDepthStencilState();
    const auto currentRasterizerState = GetRasterizerState();

    globalState.SetDefaultBlendState();
    globalState.SetDefaultDepthStencilState();
    globalState.SetDefaultRasterizerState();

    const auto numPixelsDrawn = DrawPrimitive(activeFont.GetVertexBuffer(), activeFont.GetIndexBuffer(), activeFont.GetTextEffect());

    SetBlendState(currentBlendState);
    SetDepthStencilState(currentDepthStencilState);
    SetRasterizerState(currentRasterizerState);

    return numPixelsDrawn;
}

int64_t Rendering::BaseRendererImpl::Draw(int x, int y, const Colour& color, const std::string& message)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!message.empty())
    {
        const auto viewport = GetViewport();
        const auto activeFont = GetFont();

        activeFont->Typeset(viewport.GetWidth(), viewport.GetHeight(), x, y, color, message);
        Update(*activeFont);

        return SetState(*activeFont);
    }
    else
    {
        return 0;
    }
}

int64_t Rendering::BaseRendererImpl::Draw(const OverlayEffectSharedPtr& overlay)
{
    RENDERING_CLASS_IS_VALID_9;

    if (overlay == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的overlay为空。"))
    }

    const auto vertexBuffer = overlay->GetVertexBuffer();
    const auto indexBuffer = overlay->GetIndexBuffer();
    const auto effect = overlay->GetEffect();

    return DrawPrimitive(vertexBuffer, indexBuffer, effect);
}

void Rendering::BaseRendererImpl::SetAllowOcclusionQuery(bool allow) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    allowOcclusionQuery = allow;
}

void Rendering::BaseRendererImpl::Enable(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindDrawTarget = Bind(target);
    bindDrawTarget->Enable();
}

void Rendering::BaseRendererImpl::Disable(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindDrawTarget = Bind(target);
    bindDrawTarget->Disable();
}

Rendering::BaseRendererImpl::RendererObjectSharedPtr Rendering::BaseRendererImpl::Bind(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.BindRendererObject(rendererTypes, graphicsObject);
}

Rendering::BaseRendererImpl::RendererDrawTargetSharedPtr Rendering::BaseRendererImpl::Bind(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!rendererAdapter.HasDrawTarget(target))
    {
        const auto numTargets = target->GetNumTargets();
        DrawTargetBridge::RendererObjectContainer renderTargetTexture{};
        for (auto i = 0; i < numTargets; ++i)
        {
            renderTargetTexture.emplace_back(Bind(target->GetRenderTargetTexture(i)));
        }

        const auto depthStencilTexture = Bind(target->GetDepthStencilTexture());

        return rendererAdapter.BindDrawTarget(rendererTypes, target, renderTargetTexture, depthStencilTexture);
    }
    else
    {
        return rendererAdapter.GetDrawTarget(target);
    }
}

Rendering::BaseRendererImpl::RendererObjectSharedPtr Rendering::BaseRendererImpl::Get(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.GetRendererObject(graphicsObject);
}

Rendering::BaseRendererImpl::RendererDrawTargetSharedPtr Rendering::BaseRendererImpl::Get(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.GetDrawTarget(target);
}

void Rendering::BaseRendererImpl::Unbind(const GraphicsObjectSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.UnbindRendererObject(object);
}

void Rendering::BaseRendererImpl::Unbind(const DrawTargetSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_9;

    rendererAdapter.UnbindDrawTarget(object);
}

Rendering::TotalAllocation Rendering::BaseRendererImpl::GetTotalAllocation()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return rendererAdapter.GetTotalAllocation();
}

bool Rendering::BaseRendererImpl::Update(const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindBuffer = rendererAdapter.BindRendererObject(rendererTypes, buffer);

    return bindBuffer->Update();
}

bool Rendering::BaseRendererImpl::Update(const TextureSingleSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, texture);

    return bindTexture->Update();
}

bool Rendering::BaseRendererImpl::Update(const TextureSingleSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, texture);

    return bindTexture->Update(level);
}

bool Rendering::BaseRendererImpl::Update(const TextureArraySharedPtr& textureArray)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, textureArray);

    return bindTexture->Update();
}

bool Rendering::BaseRendererImpl::Update(const TextureArraySharedPtr& textureArray, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, textureArray);

    return bindTexture->Update(item, level);
}

bool Rendering::BaseRendererImpl::CopyGpuToCpu(const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindBuffer = rendererAdapter.BindRendererObject(rendererTypes, buffer);

    return bindBuffer->CopyGpuToCpu();
}

bool Rendering::BaseRendererImpl::CopyGpuToCpu(const TextureSingleSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, texture);

    return bindTexture->CopyGpuToCpu();
}

bool Rendering::BaseRendererImpl::CopyGpuToCpu(const TextureSingleSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, texture);

    return bindTexture->CopyGpuToCpu(level);
}

bool Rendering::BaseRendererImpl::CopyGpuToCpu(const TextureArraySharedPtr& textureArray)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, textureArray);

    return bindTexture->CopyGpuToCpu();
}

bool Rendering::BaseRendererImpl::CopyGpuToCpu(const TextureArraySharedPtr& textureArray, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, textureArray);

    return bindTexture->CopyGpuToCpu(item, level);
}

bool Rendering::BaseRendererImpl::CopyCpuToGpu(const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindBuffer = rendererAdapter.BindRendererObject(rendererTypes, buffer);

    return bindBuffer->CopyCpuToGpu();
}

bool Rendering::BaseRendererImpl::CopyCpuToGpu(const TextureSingleSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, texture);

    return bindTexture->CopyCpuToGpu();
}

bool Rendering::BaseRendererImpl::CopyCpuToGpu(const TextureSingleSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, texture);

    return bindTexture->CopyCpuToGpu(level);
}

bool Rendering::BaseRendererImpl::CopyCpuToGpu(const TextureArraySharedPtr& textureArray)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, textureArray);

    return bindTexture->CopyCpuToGpu();
}

bool Rendering::BaseRendererImpl::CopyCpuToGpu(const TextureArraySharedPtr& textureArray, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto bindTexture = rendererAdapter.BindRendererObject(rendererTypes, textureArray);

    return bindTexture->CopyCpuToGpu(item, level);
}

bool Rendering::BaseRendererImpl::GetNumActiveElements(const StructuredBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto object = rendererAdapter.GetRendererObject(buffer);

    return object->GetNumActiveElements();
}

void Rendering::BaseRendererImpl::Execute(const ComputeProgramSharedPtr& program, int numXGroups, int numYGroups, int numZGroups)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.Execute(program, numXGroups, numYGroups, numZGroups);
}

void Rendering::BaseRendererImpl::WaitForFinish()
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.WaitForFinish();
}

void Rendering::BaseRendererImpl::Flush()
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.Flush();
}

int64_t Rendering::BaseRendererImpl::DrawPrimitive(const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer, const VisualEffectSharedPtr& effect)
{
    RENDERING_CLASS_IS_VALID_9;

    return rendererAdapter.DrawPrimitive(vertexBuffer, indexBuffer, effect);
}
