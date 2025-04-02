/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/17 10:51)

#include "Rendering/RenderingExport.h"

#include "BaseRenderer.h"
#include "RendererParameter.h"
#include "Detail/BaseRendererImpl.h"
#include "Detail/RendererFactory.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "Rendering/Base/TotalAllocation.h"
#include "Rendering/DataTypes/ColourDetail.h"

Rendering::BaseRenderer::BaseRenderer(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
    : impl{ CoreTools::ImplCreateUseFactory::Default, rendererParameter.GetRendererType(), RenderingEnvironment{ environmentParameter, rendererParameter } }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BaseRenderer::BaseRenderer(const EnvironmentParameter& environmentParameter, const std::string& fileName)
    : impl{ CoreTools::ImplCreateUseFactory::Default, environmentParameter, fileName }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BaseRenderer::BaseRendererSharedPtr Rendering::BaseRenderer::Create(const std::string& fileName, const EnvironmentParameter& environmentParameter)
{
    return std::make_shared<BaseRenderer>(environmentParameter, fileName);
}

void Rendering::BaseRenderer::Release()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Release();
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BaseRenderer)

bool Rendering::BaseRenderer::HasDepthRange01() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->HasDepthRange01();
}

std::string Rendering::BaseRenderer::GetShaderName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetShaderName(name);
}

void Rendering::BaseRenderer::Resize(int width, int height)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Resize(width, height);
}

int64_t Rendering::BaseRenderer::Draw(Visual& visual)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Draw(visual);
}

int64_t Rendering::BaseRenderer::Draw(const VisualContainer& visuals)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Draw(visuals);
}

int64_t Rendering::BaseRenderer::Draw(int x, int y, const ColourType& color, const std::string& message)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Draw(x, y, color, message);
}

int64_t Rendering::BaseRenderer::Draw(const OverlayEffectSharedPtr& overlay)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Draw(overlay);
}

void Rendering::BaseRenderer::SetAllowOcclusionQuery(bool allow) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAllowOcclusionQuery(allow);
}

void Rendering::BaseRenderer::Enable(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Enable(target);
}

void Rendering::BaseRenderer::Disable(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Disable(target);
}

Rendering::BaseRenderer::RendererObjectSharedPtr Rendering::BaseRenderer::Bind(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Bind(graphicsObject);
}

Rendering::BaseRenderer::RendererDrawTargetSharedPtr Rendering::BaseRenderer::Bind(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Bind(target);
}

Rendering::BaseRenderer::RendererObjectSharedPtr Rendering::BaseRenderer::Get(const GraphicsObjectSharedPtr& graphicsObject)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Get(graphicsObject);
}

Rendering::BaseRenderer::RendererDrawTargetSharedPtr Rendering::BaseRenderer::Get(const DrawTargetSharedPtr& target)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Get(target);
}

void Rendering::BaseRenderer::Unbind(const GraphicsObjectSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Unbind(object);
}

void Rendering::BaseRenderer::Unbind(const DrawTargetSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Unbind(object);
}

Rendering::TotalAllocation Rendering::BaseRenderer::GetTotalAllocation() const
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTotalAllocation();
}

bool Rendering::BaseRenderer::Update(const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update(buffer);
}

bool Rendering::BaseRenderer::Update(const TextureSingleSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update(texture);
}

bool Rendering::BaseRenderer::Update(const TextureSingleSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update(texture, level);
}

bool Rendering::BaseRenderer::Update(const TextureArraySharedPtr& textureArray)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update(textureArray);
}

bool Rendering::BaseRenderer::Update(const TextureArraySharedPtr& textureArray, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Update(textureArray, item, level);
}

bool Rendering::BaseRenderer::CopyCpuToGpu(const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyCpuToGpu(buffer);
}

bool Rendering::BaseRenderer::CopyCpuToGpu(const TextureSingleSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyCpuToGpu(texture);
}

bool Rendering::BaseRenderer::CopyCpuToGpu(const TextureSingleSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyCpuToGpu(texture, level);
}

bool Rendering::BaseRenderer::CopyCpuToGpu(const TextureArraySharedPtr& textureArray)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyCpuToGpu(textureArray);
}

bool Rendering::BaseRenderer::CopyCpuToGpu(const TextureArraySharedPtr& textureArray, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyCpuToGpu(textureArray, item, level);
}

bool Rendering::BaseRenderer::CopyGpuToCpu(const BufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToCpu(buffer);
}

bool Rendering::BaseRenderer::CopyGpuToCpu(const TextureSingleSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToCpu(texture);
}

bool Rendering::BaseRenderer::CopyGpuToCpu(const TextureSingleSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToCpu(texture, level);
}

bool Rendering::BaseRenderer::CopyGpuToCpu(const TextureArraySharedPtr& textureArray)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToCpu(textureArray);
}

bool Rendering::BaseRenderer::CopyGpuToCpu(const TextureArraySharedPtr& textureArray, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToCpu(textureArray, item, level);
}

bool Rendering::BaseRenderer::GetNumActiveElements(const StructuredBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetNumActiveElements(buffer);
}

void Rendering::BaseRenderer::Execute(ComputeProgram& program, int numXGroups, int numYGroups, int numZGroups)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Execute(program, numXGroups, numYGroups, numZGroups);
}

void Rendering::BaseRenderer::WaitForFinish()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->WaitForFinish();
}

void Rendering::BaseRenderer::Flush()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->Flush();
}

void Rendering::BaseRenderer::CopyGpuToGpu(const BufferSharedPtr& buffer0, const BufferSharedPtr& buffer1)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToGpu(buffer0, buffer1);
}

void Rendering::BaseRenderer::CopyGpuToGpu(const TextureSingleSharedPtr& texture0, const TextureSingleSharedPtr& texture1)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToGpu(texture0, texture1);
}

void Rendering::BaseRenderer::CopyGpuToGpu(const TextureSingleSharedPtr& texture0, const TextureSingleSharedPtr& texture1, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToGpu(texture0, texture1, level);
}

void Rendering::BaseRenderer::CopyGpuToGpu(const TextureArraySharedPtr& textureArray0, const TextureArraySharedPtr& textureArray1)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToGpu(textureArray0, textureArray1);
}

void Rendering::BaseRenderer::CopyGpuToGpu(const TextureArraySharedPtr& textureArray0, const TextureArraySharedPtr& textureArray1, int item, int level)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->CopyGpuToGpu(textureArray0, textureArray1, item, level);
}

void Rendering::BaseRenderer::InitDevice()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->InitDevice();
}

void Rendering::BaseRenderer::DisplayColorBuffer(int32_t syncInterval)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->DisplayColorBuffer(syncInterval);
}

void Rendering::BaseRenderer::SetFont(const FontSharedPtr& font)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFont(font);
}

Rendering::BaseRenderer::FontSharedPtr Rendering::BaseRenderer::GetFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetFont();
}

void Rendering::BaseRenderer::SetDefaultFont()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDefaultFont();
}

Rendering::BaseRenderer::FontSharedPtr Rendering::BaseRenderer::GetDefaultFont() const noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultFont();
}

void Rendering::BaseRenderer::SetBlendState(const BlendStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBlendState(state);
}

Rendering::BaseRenderer::BlendStateSharedPtr Rendering::BaseRenderer::GetBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetBlendState();
}

Rendering::BaseRenderer::BlendStateSharedPtr Rendering::BaseRenderer::GetDefaultBlendState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultBlendState();
}

void Rendering::BaseRenderer::SetDefaultBlendState()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDefaultBlendState();
}

void Rendering::BaseRenderer::SetDepthStencilState(const DepthStencilStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDepthStencilState(state);
}

Rendering::BaseRenderer::DepthStencilStateSharedPtr Rendering::BaseRenderer::GetDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDepthStencilState();
}

Rendering::BaseRenderer::DepthStencilStateSharedPtr Rendering::BaseRenderer::GetDefaultDepthStencilState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultDepthStencilState();
}

Rendering::BaseRenderer::RasterizerStateSharedPtr Rendering::BaseRenderer::GetRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetRasterizerState();
}

Rendering::BaseRenderer::RasterizerStateSharedPtr Rendering::BaseRenderer::GetDefaultRasterizerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetDefaultRasterizerState();
}

Rendering::RendererTypes Rendering::BaseRenderer::GetRendererType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRendererType();
}

int Rendering::BaseRenderer::GetWidth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetWidth();
}

int Rendering::BaseRenderer::GetHeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetHeight();
}

Rendering::DataFormatType Rendering::BaseRenderer::GetColorFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetColorFormat();
}

Rendering::DataFormatType Rendering::BaseRenderer::GetDepthStencilFormat() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthStencilFormat();
}

int Rendering::BaseRenderer::GetNumMultiSamples() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNumMultiSamples();
}

void Rendering::BaseRenderer::SetViewport(const Viewport& viewport)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetViewport(viewport);
}

Rendering::Viewport Rendering::BaseRenderer::GetViewport() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetViewport();
}

void Rendering::BaseRenderer::SetDepthRange(const DepthRange& depthRange)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetDepthRange(depthRange);
}

Rendering::DepthRange Rendering::BaseRenderer::GetDepthRange() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetDepthRange();
}

void Rendering::BaseRenderer::SetClearColor(const ColourType& clearColor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetClearColor(clearColor);
}

Rendering::BaseRenderer::ColourType Rendering::BaseRenderer::GetClearColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClearColor();
}

void Rendering::BaseRenderer::SetClearDepth(float clearDepth) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetClearDepth(clearDepth);
}

float Rendering::BaseRenderer::GetClearDepth() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClearDepth();
}

void Rendering::BaseRenderer::SetClearStencil(int clearStencil) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetClearStencil(clearStencil);
}

int Rendering::BaseRenderer::GetClearStencil() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetClearStencil();
}

void Rendering::BaseRenderer::SetRasterizerState(const RasterizerStateSharedPtr& state)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetRasterizerState(state);
}

void Rendering::BaseRenderer::ClearColorBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearColorBuffer();
}

void Rendering::BaseRenderer::ClearDepthBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearDepthBuffer();
}

void Rendering::BaseRenderer::ClearStencilBuffer()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearStencilBuffer();
}

void Rendering::BaseRenderer::ClearBuffers()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ClearBuffers();
}

void Rendering::BaseRenderer::SetWarnOnNonemptyBridges(bool warn) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetWarnOnNonemptyBridges(warn);
}