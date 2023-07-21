///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/28 15:19)

#include "Rendering/RenderingExport.h"

#include "BaseRenderer.h"
#include "RendererParameter.h"
#include "Detail/BaseRendererImpl.h"
#include "Detail/RendererFactory.h"
#include "CoreTools/Base/Flags/UniqueIdSelect.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Base/TotalAllocation.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/DataTypes/DataTypes.h"

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetColorFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetDepthStencilFormat, Rendering::DataFormatType)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetNumMultiSamples, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, BaseRenderer, SetRasterizerState, RasterizerStateSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, BaseRenderer, SetClearColor, Colour, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetClearColor, Rendering::BaseRenderer::Colour)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BaseRenderer, SetClearDepth, float, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetClearDepth, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BaseRenderer, SetClearStencil, int, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetClearStencil, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, BaseRenderer, SetViewport, Viewport, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BaseRenderer, GetViewport, Rendering::Viewport)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, BaseRenderer, SetDepthRange, DepthRange, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BaseRenderer, GetDepthRange, Rendering::DepthRange)

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

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BaseRenderer, ClearColorBuffer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BaseRenderer, ClearDepthBuffer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BaseRenderer, ClearStencilBuffer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, BaseRenderer, ClearBuffers, void)

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

int64_t Rendering::BaseRenderer::Draw(int x, int y, const Colour& color, const std::string& message)
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

Rendering::TotalAllocation Rendering::BaseRenderer::GetTotalAllocation()
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

void Rendering::BaseRenderer::Execute(const ComputeProgramSharedPtr& program, int numXGroups, int numYGroups, int numZGroups)
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

void Rendering::BaseRenderer::ResetSize()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->ResetSize();
}

void Rendering::BaseRenderer::InitDevice()
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->InitDevice();
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BaseRenderer, GetRendererType, Rendering::RendererTypes)

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
