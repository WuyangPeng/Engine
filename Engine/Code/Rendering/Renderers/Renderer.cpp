// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.3.0 (2020/03/27 11:12)

#include "Rendering/RenderingExport.h"

#include "Renderer.h"
#include "RendererFactory.h"
#include "Detail/RendererImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/DataTypes/ColourDetail.h"
#include "Rendering/Renderers/RendererManager.h"
using std::move;
using std::string;
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
Rendering::Renderer::Renderer(RendererTypes type, const RendererBasis& basis)
    : impl{ CoreTools::ImplCreateUseFactory::Default, type, basis }, m_RendererID{ 0 }
{
    // 初始化未完成
}

Rendering::Renderer::Renderer(const std::string& fileName)
    : impl{ CoreTools::ImplCreateUseFactory::Default, fileName }, m_RendererID{ 0 }
{
    // 初始化未完成
}

// private
void Rendering::Renderer::Init()
{
    m_RendererID = RENDERER_MANAGE_SINGLETON.Insert(shared_from_this());
    impl->SetRealRenderer(shared_from_this());

    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Renderer::Renderer(Renderer&& rhs) noexcept
    : impl{ move(rhs.impl) }, m_RendererID{ rhs.m_RendererID }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::Renderer& Rendering::Renderer::operator=(Renderer&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    impl = move(rhs.impl);
    m_RendererID = rhs.m_RendererID;

    return *this;
}

Rendering::Renderer::~Renderer()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
    EXCEPTION_TRY
    {
        if (!RENDERER_MANAGE_SINGLETON.Erase(m_RendererID))
        {
            LOG_SINGLETON_ENGINE_APPENDER(Error, Rendering)
                << SYSTEM_TEXT("Renderer没有调用Init。")
                << LOG_SINGLETON_TRIGGER_ASSERT;
        }
    }
    EXCEPTION_ALL_CATCH(Rendering)
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::Renderer::IsValid() const noexcept
{
    if (  0 < m_RendererID)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetWidth, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetHeight, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetColorFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetDepthStencilFormat, Rendering::TextureFormat)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetNumMultisamples, int)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Enable, ConstVertexFormatSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Disable, ConstVertexFormatSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstVertexBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstVertexBufferSharedPtr, void)

void Rendering::Renderer::Enable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex, int offset)
{
    ;

    return impl->Enable(vertexBuffer, streamIndex, offset);
}

void Rendering::Renderer::Disable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex)
{
    ;

    return impl->Disable(vertexBuffer, streamIndex);
}

void* Rendering::Renderer::Lock(const ConstVertexBufferSharedPtr& vertexBuffer, BufferLocking mode)
{
    ;

    return impl->Lock(vertexBuffer, mode);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unlock, ConstVertexBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Update, ConstVertexBufferSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstIndexBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstIndexBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Enable, ConstIndexBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Disable, ConstIndexBufferSharedPtr, void)

void* Rendering::Renderer::Lock(const ConstIndexBufferSharedPtr& indexbuffer, BufferLocking mode)
{
    ;

    return impl->Lock(indexbuffer, mode);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unlock, ConstIndexBufferSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Update, ConstIndexBufferSharedPtr, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstTexture1DSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstTexture1DSharedPtr, void)

void Rendering::Renderer::Enable(const ConstTexture1DSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Enable(texture, textureUnit);
}

void Rendering::Renderer::Disable(const ConstTexture1DSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer::Lock(const ConstTexture1DSharedPtr& texture, int level, BufferLocking mode)
{
    ;

    return impl->Lock(texture, level, mode);
}

void Rendering::Renderer::Unlock(const ConstTexture1DSharedPtr& texture, int level)
{
    ;

    return impl->Unlock(texture, level);
}

void Rendering::Renderer::Update(const ConstTexture1DSharedPtr& texture, int level)
{
    ;

    return impl->Update(texture, level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstTexture2DSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstTexture2DSharedPtr, void)

void Rendering::Renderer::Enable(const ConstTexture2DSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Enable(texture, textureUnit);
}

void Rendering::Renderer::Disable(const ConstTexture2DSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer::Lock(const ConstTexture2DSharedPtr& texture, int level, BufferLocking mode)
{
    ;

    return impl->Lock(texture, level, mode);
}

void Rendering::Renderer::Unlock(const ConstTexture2DSharedPtr& texture, int level)
{
    ;

    return impl->Unlock(texture, level);
}

void Rendering::Renderer::Update(const ConstTexture2DSharedPtr& texture, int level)
{
    ;

    return impl->Update(texture, level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstTexture3DSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstTexture3DSharedPtr, void)

void Rendering::Renderer::Enable(const ConstTexture3DSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Enable(texture, textureUnit);
}

void Rendering::Renderer::Disable(const ConstTexture3DSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer::Lock(const ConstTexture3DSharedPtr& texture, int level, BufferLocking mode)
{
    ;

    return impl->Lock(texture, level, mode);
}

void Rendering::Renderer::Unlock(const ConstTexture3DSharedPtr& texture, int level)
{
    ;

    return impl->Unlock(texture, level);
}

void Rendering::Renderer::Update(const ConstTexture3DSharedPtr& texture, int level)
{
    ;

    return impl->Update(texture, level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstTextureCubeSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstTextureCubeSharedPtr, void)

void Rendering::Renderer::Enable(const ConstTextureCubeSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Enable(texture, textureUnit);
}

void Rendering::Renderer::Disable(const ConstTextureCubeSharedPtr& texture, int textureUnit)
{
    ;

    return impl->Disable(texture, textureUnit);
}

void* Rendering::Renderer::Lock(const ConstTextureCubeSharedPtr& texture, int face, int level, BufferLocking mode)
{
    ;

    return impl->Lock(texture, face, level, mode);
}

void Rendering::Renderer::Unlock(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
    ;

    return impl->Unlock(texture, face, level);
}

void Rendering::Renderer::Update(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
    ;

    return impl->Update(texture, face, level);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstRenderTargetSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstRenderTargetSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Enable, ConstRenderTargetSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Disable, ConstRenderTargetSharedPtr, void)

Rendering::ConstTexture2DSharedPtr Rendering::Renderer::ReadColor(int index, const ConstRenderTargetSharedPtr& renderTarget)
{
    ;

    return impl->ReadColor(index, renderTarget);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstVertexShaderSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstVertexShaderSharedPtr, void)

void Rendering::Renderer::Enable(const ConstVertexShaderSharedPtr& vshader, const ConstShaderParametersSharedPtr& parameters)
{
    ;

    return impl->Enable(vshader, parameters);
}

void Rendering::Renderer::Disable(const ConstVertexShaderSharedPtr& vshader, const ConstShaderParametersSharedPtr& parameters)
{
    ;

    return impl->Enable(vshader, parameters);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Bind, ConstPixelShaderSharedPtr, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, Unbind, ConstPixelShaderSharedPtr, void)

void Rendering::Renderer::Enable(const ConstPixelShaderSharedPtr& vshader, const ConstShaderParametersSharedPtr& parameters)
{
    ;

    return impl->Enable(vshader, parameters);
}

void Rendering::Renderer::Disable(const ConstPixelShaderSharedPtr& vshader, const ConstShaderParametersSharedPtr& parameters)
{
    ;

    return impl->Enable(vshader, parameters);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetAlphaState, const Rendering::ConstAlphaStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetCullState, const Rendering::ConstCullStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetDepthState, const Rendering::ConstDepthStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOffsetState, const Rendering::ConstOffsetStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetStencilState, const Rendering::ConstStencilStateSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetWireState, const Rendering::ConstWireStateSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideAlphaState, const Rendering::ConstAlphaStateSharedPtr);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideCullState, const Rendering::ConstCullStateSharedPtr);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideDepthState, const Rendering::ConstDepthStateSharedPtr);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideOffsetState, const Rendering::ConstOffsetStateSharedPtr);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideStencilState, const Rendering::ConstStencilStateSharedPtr);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetOverrideWireState, const Rendering::ConstWireStateSharedPtr);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideAlphaState, ConstAlphaStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideCullState, ConstCullStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideDepthState, ConstDepthStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideOffsetState, ConstOffsetStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideStencilState, ConstStencilStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOverrideWireState, ConstWireStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetReverseCullOrder, bool, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetReverseCullOrder, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetCamera, CameraSharedPtr, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetCamera, const Rendering::ConstCameraSharedPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetCamera, const Rendering::CameraSharedPtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetViewMatrix, const Rendering::Renderer::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetProjectionMatrix, const Rendering::Renderer::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetPostProjectionMatrix, const Rendering::Renderer::Matrix)

Rendering::PickRay Rendering::Renderer::GetPickRay(int x, int y) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->GetPickRay(x, y);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetClearColor, Colour, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetClearColor, const Rendering::Renderer::Colour)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetClearDepth, float, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetClearDepth, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetClearStencil, int, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetClearStencil, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetAllowRed, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetAllowGreen, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetAllowBlue, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetAllowAlpha, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetAllowRed, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetAllowGreen, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetAllowBlue, bool, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Renderer, SetAllowAlpha, bool, void);

void Rendering::Renderer::Draw(VisibleSet& visibleSet, const GlobalEffectSharedPtr& globalEffect)
{
    ;

    return impl->Draw(visibleSet, globalEffect);
}

void Rendering::Renderer::Draw(const VisualSharedPtr& visual)
{
    ;

    return impl->Draw(visual);
}

void Rendering::Renderer::Draw(const VisualSharedPtr& visual, const VisualEffectInstanceSharedPtr& instance)
{
    ;

    return impl->Draw(visual, instance);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetAlphaState, ConstAlphaStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetCullState, ConstCullStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetDepthState, ConstDepthStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetOffsetState, ConstOffsetStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetStencilState, ConstStencilStateSharedPtr, void);
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetWireState, ConstWireStateSharedPtr, void);

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetViewport, Viewport, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetViewport, Rendering::Viewport)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, SetDepthRange, DepthRange, void);
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetDepthRange, Rendering::DepthRange)

void Rendering::Renderer::Resize(int width, int height)
{
    ;

    return impl->Resize(width, height);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, ClearColorBuffer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, ClearDepthBuffer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, ClearStencilBuffer, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, ClearBuffers, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, DisplayColorBuffer, void)

void Rendering::Renderer::ClearColorBuffer(int x, int y, int w, int h)
{
    ;

    return impl->ClearColorBuffer(x, y, w, h);
}

void Rendering::Renderer::ClearDepthBuffer(int x, int y, int w, int h)
{
    ;

    return impl->ClearDepthBuffer(x, y, w, h);
}

void Rendering::Renderer::ClearStencilBuffer(int x, int y, int w, int h)
{
    ;

    return impl->ClearStencilBuffer(x, y, w, h);
}

void Rendering::Renderer::ClearBuffers(int x, int y, int w, int h)
{
    ;

    return impl->ClearBuffers(x, y, w, h);
}

void Rendering::Renderer::SetColorMask(bool allowRed, bool allowGreen, bool allowBlue, bool allowAlpha)
{
    ;

    impl->SetColorMask(allowRed, allowGreen, allowBlue, allowAlpha);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, PreDraw, bool)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, PostDraw, void)

void Rendering::Renderer::Draw(const uint8_t* screenBuffer, bool reflectY)
{
    ;

    return impl->Draw(screenBuffer, reflectY);
}

void Rendering::Renderer::Draw(const std::vector<ColourUByte>& screenBuffer, bool reflectY)
{
    ;

    return impl->Draw(screenBuffer.at(0).GetPoint().data(), reflectY);
}

void Rendering::Renderer::Draw(int x, int y, const Colour& color, const std::string& message)
{
    ;

    return impl->Draw(x, y, color, message);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Renderer, InTexture2DMap, ConstTexture2DSharedPtr, bool)

void Rendering::Renderer::InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture)
{
    ;

    return impl->InsertInTexture2DMap(texture, platformTexture);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Rendering, Renderer, GetRendererType, Rendering::RendererTypes)
#include STSTEM_WARNING_POP