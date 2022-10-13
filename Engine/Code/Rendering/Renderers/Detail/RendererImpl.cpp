///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/20 14:34)

#include "Rendering/RenderingExport.h"

#include "RendererImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"
#include "Rendering/LocalEffects/Font.h"
#include "Rendering/LocalEffects/TextEffect.h"
#include "Rendering/Renderers/BufferManagementDetail.h"
#include "Rendering/Renderers/RenderTargetManagement.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/ShaderManagementDetail.h"
#include "Rendering/Renderers/TextureManagementDetail.h"
#include "Rendering/Renderers/VertexFormatManagement.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/SceneGraph/Visual.h"

#include <memory>

Rendering::RendererImpl::RendererImpl(const RenderingEnvironment& renderingEnvironment, const RendererBasis& basis)
    : ParentType{ renderingEnvironment, basis },

      defaultAlphaState{ std::make_shared<AlphaState>(CoreTools::DisableNotThrow::Disable) },
      defaultCullState{ std::make_shared<CullState>(CoreTools::DisableNotThrow::Disable) },
      defaultDepthState{ std::make_shared<DepthState>(CoreTools::DisableNotThrow::Disable) },
      defaultOffsetState{ std::make_shared<OffsetState>(CoreTools::DisableNotThrow::Disable) },
      defaultStencilState{ std::make_shared<StencilState>(CoreTools::DisableNotThrow::Disable) },
      defaultWireState{ std::make_shared<WireState>(CoreTools::DisableNotThrow::Disable) },

      globalAlphaState{ defaultAlphaState },
      globalCullState{ defaultCullState },
      globalDepthState{ defaultDepthState },
      globalOffsetState{ defaultOffsetState },
      globalStencilState{ defaultStencilState },
      globalWireState{ defaultWireState },
      reverseCullOrder{ false },

      vertexFormatManagement{},
      vertexBufferManagement{},
      indexBufferManagement{},
      texture1DManagement{},
      texture2DManagement{},
      texture3DManagement{},
      textureCubeManagement{},
      renderTargetManagement{},
      vertexShaderManagement{},
      pixelShaderManagement{},

      globalState{},
      cameraState{},
      clearParameter{},
      viewportManagement{},
      drawManagement{},

      rendererData{},

      overrideAlphaState{},
      overrideCullState{},
      overrideDepthState{},
      overrideOffsetState{},
      overrideStencilState{},
      overrideWireState{},

      camera{},

      bufferAllowRed{ true },
      bufferAllowGreen{ true },
      bufferAllowBlue{ true },
      bufferAllowAlpha{ true },

      realRenderer{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RendererImpl::SetRealRenderer(const RendererSharedPtr& renderer)
{
    RENDERING_CLASS_IS_VALID_1;

    realRenderer = renderer;

    vertexFormatManagement = make_shared<VertexFormatManagement>(renderer);
    vertexBufferManagement = make_shared<VertexBufferManagement>(renderer);
    indexBufferManagement = make_shared<IndexBufferManagement>(renderer);
    texture1DManagement = make_shared<Texture1DManagement>(renderer);
    texture2DManagement = make_shared<Texture2DManagement>(renderer);
    texture3DManagement = make_shared<Texture3DManagement>(renderer);
    textureCubeManagement = make_shared<TextureCubeManagement>(renderer);
    renderTargetManagement = make_shared<RenderTargetManagement>(renderer);
    vertexShaderManagement = make_shared<VertexShaderManagement>(renderer);
    pixelShaderManagement = make_shared<PixelShaderManagement>(renderer);
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::RendererImpl::IsValid() const noexcept
{
    if (!realRenderer.lock() ||
        (vertexFormatManagement &&
         vertexBufferManagement &&
         indexBufferManagement &&
         texture1DManagement &&
         texture2DManagement &&
         texture3DManagement &&
         textureCubeManagement &&
         renderTargetManagement &&
         vertexShaderManagement &&
         pixelShaderManagement))
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::RendererImpl::Bind(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexFormatManagement->Bind(vertexFormat);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)

void Rendering::RendererImpl::Bind(MAYBE_UNUSED const std::shared_ptr<const GraphicsObject>& object) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

void Rendering::RendererImpl::Unbind(MAYBE_UNUSED const std::shared_ptr<const GraphicsObject>& texture) noexcept
{
    RENDERING_CLASS_IS_VALID_1;
}

#include STSTEM_WARNING_POP

void Rendering::RendererImpl::Unbind(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexFormatManagement->Unbind(vertexFormat);
}

void Rendering::RendererImpl::Enable(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexFormatManagement->Enable(vertexFormat);
}

void Rendering::RendererImpl::Disable(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexFormatManagement->Disable(vertexFormat);
}

Rendering::RendererImpl::PlatformVertexFormatSharedPtr Rendering::RendererImpl::GetResource(const ConstVertexFormatSharedPtr& vertexFormat)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexFormatManagement->GetResource(vertexFormat);
}

void Rendering::RendererImpl::Bind(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->Bind(vertexBuffer);
}

void Rendering::RendererImpl::Unbind(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->Unbind(vertexBuffer);
}

void Rendering::RendererImpl::Enable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex, int offset)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->EnableVertexBuffer(vertexBuffer, streamIndex, offset);
}

void Rendering::RendererImpl::Disable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->DisableVertexBuffer(vertexBuffer, streamIndex);
}

void* Rendering::RendererImpl::Lock(const ConstVertexBufferSharedPtr& vertexBuffer, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->Lock(vertexBuffer, mode);
}

void Rendering::RendererImpl::Unlock(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->Unlock(vertexBuffer);
}

void Rendering::RendererImpl::Update(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->Update(vertexBuffer);
}

void Rendering::RendererImpl::Bind(const ConstIndexBufferSharedPtr& indexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->Bind(indexbuffer);
}

void Rendering::RendererImpl::Unbind(const ConstIndexBufferSharedPtr& indexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->Unbind(indexbuffer);
}

void Rendering::RendererImpl::Enable(const ConstIndexBufferSharedPtr& indexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->EnableIndexBuffer(indexbuffer);
}

void Rendering::RendererImpl::Disable(const ConstIndexBufferSharedPtr& indexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->DisableIndexBuffer(indexbuffer);
}

void* Rendering::RendererImpl::Lock(const ConstIndexBufferSharedPtr& indexbuffer, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->Lock(indexbuffer, mode);
}

void Rendering::RendererImpl::Unlock(const ConstIndexBufferSharedPtr& indexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->Unlock(indexbuffer);
}

void Rendering::RendererImpl::Update(const ConstIndexBufferSharedPtr& indexbuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->Update(indexbuffer);
}

Rendering::RendererImpl::PlatformVertexBufferSharedPtr Rendering::RendererImpl::GetResource(const ConstVertexBufferSharedPtr& vertexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexBufferManagement->GetResource(vertexBuffer);
}

Rendering::RendererImpl::PlatformIndexBufferSharedPtr Rendering::RendererImpl::GetResource(const ConstIndexBufferSharedPtr& indexBuffer)
{
    RENDERING_CLASS_IS_VALID_1;

    return indexBufferManagement->GetResource(indexBuffer);
}

void Rendering::RendererImpl::Bind(const ConstTexture1DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Bind(texture);
}

void Rendering::RendererImpl::Unbind(const ConstTexture1DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Unbind(texture);
}

void Rendering::RendererImpl::Enable(const ConstTexture1DSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl::Disable(const ConstTexture1DSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl::Lock(const ConstTexture1DSharedPtr& texture, int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Lock(texture, level, mode);
}

void Rendering::RendererImpl::Unlock(const ConstTexture1DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Unlock(texture, level);
}

void Rendering::RendererImpl::Update(const ConstTexture1DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->Update(texture, level);
}

Rendering::RendererImpl::PlatformTexture1DSharedPtr Rendering::RendererImpl::GetResource(const ConstTexture1DSharedPtr& texture1D)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture1DManagement->GetResource(texture1D);
}

void Rendering::RendererImpl::Bind(const ConstTexture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Bind(texture);
}

void Rendering::RendererImpl::Unbind(const ConstTexture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Unbind(texture);
}

void Rendering::RendererImpl::Enable(const ConstTexture2DSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl::Disable(const ConstTexture2DSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl::Lock(const ConstTexture2DSharedPtr& texture, int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Lock(texture, level, mode);
}

void Rendering::RendererImpl::Unlock(const ConstTexture2DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Unlock(texture, level);
}

void Rendering::RendererImpl::Update(const ConstTexture2DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->Update(texture, level);
}

Rendering::RendererImpl::PlatformTexture2DSharedPtr Rendering::RendererImpl::GetResource(const ConstTexture2DSharedPtr& texture2D)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->GetResource(texture2D);
}

void Rendering::RendererImpl::Bind(const ConstTexture3DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Bind(texture);
}

void Rendering::RendererImpl::Unbind(const ConstTexture3DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Unbind(texture);
}

void Rendering::RendererImpl::Enable(const ConstTexture3DSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl::Disable(const ConstTexture3DSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl::Lock(const ConstTexture3DSharedPtr& texture, int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Lock(texture, level, mode);
}

void Rendering::RendererImpl::Unlock(const ConstTexture3DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Unlock(texture, level);
}

void Rendering::RendererImpl::Update(const ConstTexture3DSharedPtr& texture, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->Update(texture, level);
}

Rendering::RendererImpl::PlatformTexture3DSharedPtr Rendering::RendererImpl::GetResource(const ConstTexture3DSharedPtr& texture3D)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture3DManagement->GetResource(texture3D);
}

void Rendering::RendererImpl::Bind(const ConstTextureCubeSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->Bind(texture);
}

void Rendering::RendererImpl::Unbind(const ConstTextureCubeSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->Unbind(texture);
}

void Rendering::RendererImpl::Enable(const ConstTextureCubeSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl::Disable(const ConstTextureCubeSharedPtr& texture, int textureUnit)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl::Lock(const ConstTextureCubeSharedPtr& texture, int face, int level, BufferLocking mode)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->LockCube(texture, face, level, mode);
}

void Rendering::RendererImpl::Unlock(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->UnlockCube(texture, face, level);
}

void Rendering::RendererImpl::Update(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->UpdateCube(texture, face, level);
}

Rendering::RendererImpl::PlatformTextureCubeSharedPtr Rendering::RendererImpl::GetResource(const ConstTextureCubeSharedPtr& textureCube)
{
    RENDERING_CLASS_IS_VALID_1;

    return textureCubeManagement->GetResource(textureCube);
}

void Rendering::RendererImpl::Bind(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return renderTargetManagement->Bind(renderTarget);
}

void Rendering::RendererImpl::Unbind(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return renderTargetManagement->Unbind(renderTarget);
}

void Rendering::RendererImpl::Enable(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return renderTargetManagement->Enable(renderTarget);
}

void Rendering::RendererImpl::Disable(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return renderTargetManagement->Disable(renderTarget);
}

Rendering::ConstTexture2DSharedPtr Rendering::RendererImpl::ReadColor(int index, const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return renderTargetManagement->ReadColor(index, renderTarget);
}

Rendering::RendererImpl::PlatformRenderTargetSharedPtr Rendering::RendererImpl::GetResource(const ConstDrawTargetSharedPtr& renderTarget)
{
    RENDERING_CLASS_IS_VALID_1;

    return renderTargetManagement->GetResource(renderTarget);
}

void Rendering::RendererImpl::Bind(const ConstVertexShaderSharedPtr& vertexShader)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexShaderManagement->Bind(vertexShader);
}

void Rendering::RendererImpl::Unbind(const ConstVertexShaderSharedPtr& vertexShader)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexShaderManagement->Unbind(vertexShader);
}

void Rendering::RendererImpl::Enable(const ConstVertexShaderSharedPtr& vertexShader, const ShaderParameters& parameters)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexShaderManagement->Enable(vertexShader, parameters);
}

void Rendering::RendererImpl::Disable(const ConstVertexShaderSharedPtr& vertexShader, const ShaderParameters& parameters)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexShaderManagement->Disable(vertexShader, parameters);
}

Rendering::RendererImpl::PlatformVertexShaderSharedPtr Rendering::RendererImpl::GetResource(const ConstVertexShaderSharedPtr& vertexShader)
{
    RENDERING_CLASS_IS_VALID_1;

    return vertexShaderManagement->GetResource(vertexShader);
}

void Rendering::RendererImpl::Bind(const ConstPixelShaderSharedPtr& pixelShader)
{
    RENDERING_CLASS_IS_VALID_1;

    return pixelShaderManagement->Bind(pixelShader);
}

void Rendering::RendererImpl::Unbind(const ConstPixelShaderSharedPtr& pixelShader)
{
    RENDERING_CLASS_IS_VALID_1;

    return pixelShaderManagement->Unbind(pixelShader);
}

void Rendering::RendererImpl::Enable(const ConstPixelShaderSharedPtr& pixelShader, const ShaderParameters& parameters)
{
    RENDERING_CLASS_IS_VALID_1;

    return pixelShaderManagement->Enable(pixelShader, parameters);
}

void Rendering::RendererImpl::Disable(const ConstPixelShaderSharedPtr& pixelShader, const ShaderParameters& parameters)
{
    RENDERING_CLASS_IS_VALID_1;

    return pixelShaderManagement->Disable(pixelShader, parameters);
}

Rendering::RendererImpl::PlatformPixelShaderSharedPtr Rendering::RendererImpl::GetResource(const ConstPixelShaderSharedPtr& pixelShader)
{
    RENDERING_CLASS_IS_VALID_1;

    return pixelShaderManagement->GetResource(pixelShader);
}

Rendering::ConstAlphaStateSharedPtr Rendering::RendererImpl::GetAlphaState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalAlphaState;
}

Rendering::ConstCullStateSharedPtr Rendering::RendererImpl::GetCullState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalCullState;
}

Rendering::ConstDepthStateSharedPtr Rendering::RendererImpl::GetDepthState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalDepthState;
}

Rendering::ConstOffsetStateSharedPtr Rendering::RendererImpl::GetOffsetState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalOffsetState;
}

Rendering::ConstStencilStateSharedPtr Rendering::RendererImpl::GetStencilState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalStencilState;
}

Rendering::ConstWireStateSharedPtr Rendering::RendererImpl::GetWireState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return globalWireState;
}

Rendering::ConstAlphaStateSharedPtr Rendering::RendererImpl::GetOverrideAlphaState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return overrideAlphaState;
}

Rendering::ConstCullStateSharedPtr Rendering::RendererImpl::GetOverrideCullState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return overrideCullState;
}

Rendering::ConstDepthStateSharedPtr Rendering::RendererImpl::GetOverrideDepthState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return overrideDepthState;
}

Rendering::ConstOffsetStateSharedPtr Rendering::RendererImpl::GetOverrideOffsetState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return overrideOffsetState;
}

Rendering::ConstStencilStateSharedPtr Rendering::RendererImpl::GetOverrideStencilState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return overrideStencilState;
}

Rendering::ConstWireStateSharedPtr Rendering::RendererImpl::GetOverrideWireState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return overrideWireState;
}

void Rendering::RendererImpl::SetOverrideAlphaState(const ConstAlphaStateSharedPtr& alphaState)
{
    RENDERING_CLASS_IS_VALID_1;

    overrideAlphaState = alphaState;
    if (alphaState)
    {
        SetAlphaState(alphaState);
    }
    else
    {
        SetAlphaState(defaultAlphaState);
    }
}

void Rendering::RendererImpl::SetOverrideCullState(const ConstCullStateSharedPtr& cullState)
{
    RENDERING_CLASS_IS_VALID_1;

    overrideCullState = cullState;
    if (cullState)
    {
        SetCullState(cullState);
    }
    else
    {
        SetCullState(defaultCullState);
    }
}

void Rendering::RendererImpl::SetOverrideDepthState(const ConstDepthStateSharedPtr& depthState)
{
    RENDERING_CLASS_IS_VALID_1;

    overrideDepthState = depthState;
    if (depthState)
    {
        SetDepthState(depthState);
    }
    else
    {
        SetDepthState(defaultDepthState);
    }
}

void Rendering::RendererImpl::SetOverrideOffsetState(const ConstOffsetStateSharedPtr& offsetState)
{
    RENDERING_CLASS_IS_VALID_1;

    overrideOffsetState = offsetState;
    if (offsetState)
    {
        SetOffsetState(offsetState);
    }
    else
    {
        SetOffsetState(defaultOffsetState);
    }
}

void Rendering::RendererImpl::SetOverrideStencilState(const ConstStencilStateSharedPtr& stencilState)
{
    RENDERING_CLASS_IS_VALID_1;

    overrideStencilState = stencilState;
    if (stencilState)
    {
        SetStencilState(stencilState);
    }
    else
    {
        SetStencilState(defaultStencilState);
    }
}

void Rendering::RendererImpl::SetOverrideWireState(const ConstWireStateSharedPtr& wireState)
{
    RENDERING_CLASS_IS_VALID_1;

    overrideWireState = wireState;
    if (wireState)
    {
        SetWireState(wireState);
    }
    else
    {
        SetWireState(defaultWireState);
    }
}

void Rendering::RendererImpl::SetReverseCullOrder(bool aReverseCullOrder) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    reverseCullOrder = aReverseCullOrder;
}

bool Rendering::RendererImpl::GetReverseCullOrder() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return reverseCullOrder;
}

void Rendering::RendererImpl::SetCamera(const CameraSharedPtr& aCamera) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    camera = aCamera;
}

Rendering::ConstCameraSharedPtr Rendering::RendererImpl::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return camera;
}

Rendering::CameraSharedPtr Rendering::RendererImpl::GetCamera() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return camera;
}

Rendering::RendererImpl::Matrix Rendering::RendererImpl::GetViewMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (camera)
    {
        return camera->GetViewMatrix();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("摄像机不存在。"s));
    }
}

Rendering::RendererImpl::Matrix Rendering::RendererImpl::GetProjectionMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (camera)
    {
        return camera->GetProjectionMatrix();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("摄像机不存在。"s));
    }
}

Rendering::RendererImpl::Matrix Rendering::RendererImpl::GetPostProjectionMatrix() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (camera)
    {
        return camera->GetPostProjectionMatrix();
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("摄像机不存在。"s));
    }
}

Rendering::PickRay Rendering::RendererImpl::GetPickRay(int x, int y) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const PickRay errorPickRay{ CoreTools::DisableNotThrow::Disable };

    if (!camera)
    {
        return errorPickRay;
    }

    // 获取当前视口，并测试其中是否包含（x，y）。
    const auto viewport = GetViewport();
    if (!viewport.IsInViewport(x, y))
    {
        return errorPickRay;
    }

    // 获取(x,y)的[0,1]^2归一化坐标。
    auto r = (boost::numeric_cast<float>(x - viewport.GetXPosition())) / boost::numeric_cast<float>(viewport.GetWidth());
    auto u = (boost::numeric_cast<float>(y - viewport.GetYPosition())) / boost::numeric_cast<float>(viewport.GetHeight());

    // 获取相对坐标，单位为[rmin,rmax] x [umin,umax]。
    const auto rightBlend = (1.0f - r) * camera->GetRightMin() + r * camera->GetRightMax();
    const auto upBlend = (1.0f - u) * camera->GetUpMin() + u * camera->GetUpMax();

    Mathematics::APointF origin{};
    Mathematics::AVectorF direction{};

    if (camera->IsPerspective())
    {
        origin = camera->GetPosition();
        direction = camera->GetDirectionMin() * camera->GetDirectionVector() + rightBlend * camera->GetRightVector() + upBlend * camera->GetUpVector();
        direction.Normalize();
    }
    else
    {
        origin = camera->GetPosition() + rightBlend * camera->GetRightVector() + upBlend * camera->GetUpVector();
        direction = camera->GetDirectionVector();
    }

    return PickRay{ true, origin, direction };
}

bool Rendering::RendererImpl::GetAllowRed() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return bufferAllowRed;
}

bool Rendering::RendererImpl::GetAllowGreen() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return bufferAllowGreen;
}

bool Rendering::RendererImpl::GetAllowBlue() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return bufferAllowBlue;
}

bool Rendering::RendererImpl::GetAllowAlpha() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return bufferAllowAlpha;
}

void Rendering::RendererImpl::SetAllowRed(bool allowRed) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    bufferAllowRed = allowRed;
}

void Rendering::RendererImpl::SetAllowGreen(bool allowGreen) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    bufferAllowGreen = allowGreen;
}

void Rendering::RendererImpl::SetAllowBlue(bool allowBlue) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    bufferAllowBlue = allowBlue;
}

void Rendering::RendererImpl::SetAllowAlpha(bool allowAlpha) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    bufferAllowAlpha = allowAlpha;
}

void Rendering::RendererImpl::Draw(VisibleSet& visibleSet, GlobalEffect* globalEffect)
{
    RENDERING_CLASS_IS_VALID_1;

    if (!globalEffect)
    {
        for (auto& visual : visibleSet)
        {
            EXCEPTION_TRY
            {
                const auto instance = visual->GetEffectInstance();
                Draw(visual, instance);
            }
            EXCEPTION_ENGINE_EXCEPTION_CATCH(Rendering)
        }
    }
    else
    {
        globalEffect->Draw(*realRenderer.lock(), visibleSet);
    }
}

void Rendering::RendererImpl::SetFont(const FontSharedPtr& font)
{
    if (font == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("输入的字体为空。"));
    }

    const auto mctiveFont = GetFont();
    if (font != mctiveFont)
    {
        Unbind(mctiveFont->GetVertexBuffer());
        Unbind(mctiveFont->GetIndexBuffer());
        Unbind(mctiveFont->GetTextEffect()->GetTranslate());
        Unbind(mctiveFont->GetTextEffect()->GetColor());
        Unbind(mctiveFont->GetTextEffect()->GetVertexShader());
        Unbind(mctiveFont->GetTextEffect()->GetPixelShader());

        ParentType::SetFont(font);

        Bind(font->GetVertexBuffer());
        Bind(font->GetIndexBuffer());
        Bind(font->GetTextEffect()->GetTranslate());
        Bind(font->GetTextEffect()->GetColor());
        Bind(font->GetTextEffect()->GetVertexShader());
        Bind(font->GetTextEffect()->GetPixelShader());
    }
}

void Rendering::RendererImpl::Draw(VisualSharedPtr visual)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto instance = visual->GetEffectInstance();

    Draw(visual, instance);
}

void Rendering::RendererImpl::Draw(const VisualSharedPtr& visual, VisualEffectInstanceSharedPtr instance)
{
    RENDERING_ASSERTION_0(visual != nullptr, "visual对象必须存在。\n");
    RENDERING_ASSERTION_0(instance != nullptr, "visual对象必须具有effect实例。\n");

    const auto vertexFormat = visual->GetConstVertexFormat();
    const auto vertexBuffer = visual->GetConstVertexBuffer();
    const auto indexBuffer = visual->GetConstIndexBuffer();

    // OpenGL渲染器要求在启用顶点格式之前先启用顶点缓冲区。 该顺序与DirectX9渲染器无关。
    Enable(vertexBuffer);
    Enable(vertexFormat);
    if (indexBuffer)
    {
        Enable(indexBuffer);
    }

    const auto numPasses = instance->GetNumPasses();
    for (auto i = 0; i < numPasses; ++i)
    {
        const auto pass = instance->GetConstPass(i);
        auto vertexParameters = instance->GetVertexParameters(i);
        auto pixelParameters = instance->GetPixelParameters(i);
        auto vertexShader = pass->GetVertexShader();
        auto pixelShader = pass->GetPixelShader();

        // 更新在运行时变化的所有着色器常量。
        vertexParameters->UpdateConstants(visual.get(), camera.get());
        pixelParameters->UpdateConstants(visual.get(), camera.get());

        // 设置视觉状态。
        SetAlphaState(pass->GetAlphaState());
        SetCullState(pass->GetCullState());
        SetDepthState(pass->GetDepthState());
        SetOffsetState(pass->GetOffsetState());
        SetStencilState(pass->GetStencilState());
        SetWireState(pass->GetWireState());

        // 启用着色器。
        Enable(vertexShader, *vertexParameters);
        Enable(pixelShader, *pixelParameters);

        // 绘制图元。
        DrawPrimitive(visual);

        // 禁用着色器。
        Disable(vertexShader, *vertexParameters);
        Disable(pixelShader, *pixelParameters);

#ifdef RENDERING_RESET_STATE_AFTER_DRAW

        // 恢复视觉状态。
        SetAlphaState(defaultAlphaState);
        SetCullState(defaultCullState);
        SetDepthState(defaultDepthState);
        SetOffsetState(defaultOffsetState);
        SetStencilState(defaultStencilState);
        SetWireState(defaultWireState);

#endif  // RENDERING_RESET_STATE_AFTER_DRAW
    }

    if (indexBuffer)
    {
        Disable(indexBuffer);
    }

    Disable(vertexFormat);
    Disable(vertexBuffer);
}

bool Rendering::RendererImpl::InTexture2DMap(const ConstTexture2DSharedPtr& texture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->IsInTextureMap(texture);
}

void Rendering::RendererImpl::InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture)
{
    RENDERING_CLASS_IS_VALID_1;

    return texture2DManagement->InsertTextureMap(texture, platformTexture);
}
