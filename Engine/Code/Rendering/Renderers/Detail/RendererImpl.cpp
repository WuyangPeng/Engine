// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.3.0 (2020/03/27 16:07)

#include "Rendering/RenderingExport.h"

#include "RendererImpl.h"


#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h" 
#include "Rendering/SceneGraph/Visual.h"
#include "Rendering/SceneGraph/VisibleSet.h"
#include "Rendering/GlobalEffects/GlobalEffect.h"
#include "Rendering/Renderers/RendererBasis.h"
#include "Rendering/Renderers/VertexFormatManagement.h"
#include "Rendering/Renderers/BufferManagementDetail.h"
#include "Rendering/Renderers/TextureManagementDetail.h"
#include "Rendering/Renderers/RenderTargetManagement.h"
#include "Rendering/Renderers/ShaderManagementDetail.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::RendererImpl
	::RendererImpl(const RendererBasis& basis)
	: m_RendererBasis{ basis }, 

	  m_DefaultAlphaState{ std::make_shared<AlphaState>() }, m_DefaultCullState{ std::make_shared<CullState>() }, m_DefaultDepthState{ std::make_shared<DepthState>() }, 
	  m_DefaultOffsetState{ std::make_shared<OffsetState>() }, m_DefaultStencilState{ std::make_shared<StencilState>() }, m_DefaultWireState{ std::make_shared<WireState>() },

	  m_AlphaState{ m_DefaultAlphaState }, m_CullState{ m_DefaultCullState }, m_DepthState{ m_DefaultDepthState }, 
	  m_OffsetState{ m_DefaultOffsetState }, m_StencilState{ m_DefaultStencilState }, m_WireState{ m_DefaultWireState }, m_ReverseCullOrder{ false },
	
	  m_VertexFormatManagement{ }, m_VertexBufferManagement{ },m_IndexBufferManagement{ }, m_Texture1DManagement{ }, m_Texture2DManagement{ },
	  m_Texture3DManagement{ }, m_TextureCubeManagement{ }, m_RenderTargetManagement{ }, m_VertexShaderManagement{ }, m_PixelShaderManagement{ },

	  m_GlobalState{ }, m_CameraState{ }, m_ClearParameter{ }, m_ViewportManagement{ }, m_DrawManagement{ },

	  m_Data{ },

	  m_OverrideAlphaState{ }, m_OverrideCullState{ },
	  m_OverrideDepthState{ }, m_OverrideOffsetState{ },
	  m_OverrideStencilState{ }, m_OverrideWireState{ },

	  m_Camera{ },

	  m_ClearColor{ 1.0f, 1.0f, 1.0f, 1.0f }, m_ClearDepth{ 0.0f }, m_ClearStencil{ 0 }, 

	  m_AllowRed{ true }, m_AllowGreen{ true },m_AllowBlue{ true },m_AllowAlpha{ true },

	  m_RealRenderer{ }	
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

void Rendering::RendererImpl
	::SetRealRenderer(const RendererSharedPtr& renderer)
{
	RENDERING_CLASS_IS_VALID_1;

	m_RealRenderer = renderer;

	m_VertexFormatManagement = make_shared<VertexFormatManagement>(renderer);
	m_VertexBufferManagement = make_shared<VertexBufferManagement>(renderer);
	m_IndexBufferManagement = make_shared<IndexBufferManagement>(renderer);
	m_Texture1DManagement = make_shared<Texture1DManagement>(renderer);
	m_Texture2DManagement = make_shared<Texture2DManagement>(renderer);
	m_Texture3DManagement = make_shared<Texture3DManagement>(renderer);
	m_TextureCubeManagement = make_shared<TextureCubeManagement>(renderer);
	m_RenderTargetManagement = make_shared<RenderTargetManagement>(renderer);
	m_VertexShaderManagement = make_shared<VertexShaderManagement>(renderer);
	m_PixelShaderManagement = make_shared<PixelShaderManagement>(renderer);
} 

Rendering::RendererImpl
	::~RendererImpl()
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::RendererImpl
	::IsValid() const noexcept
{
	if (!m_RealRenderer.lock() ||
		(m_VertexFormatManagement && m_VertexBufferManagement && m_IndexBufferManagement &&
		 m_Texture1DManagement && m_Texture2DManagement && m_Texture3DManagement &&
		 m_TextureCubeManagement && m_RenderTargetManagement && 
		 m_VertexShaderManagement && m_PixelShaderManagement))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

int Rendering::RendererImpl
	::GetWidth() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererBasis.GetWidth();
}

int Rendering::RendererImpl
	::GetHeight() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererBasis.GetHeight();
}

Rendering::TextureFormat Rendering::RendererImpl
	::GetColorFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererBasis.GetColorFormat();
}

Rendering::TextureFormat Rendering::RendererImpl
	::GetDepthStencilFormat() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererBasis.GetDepthStencilFormat();
}

int Rendering::RendererImpl
	::GetNumMultisamples() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_RendererBasis.GetNumMultisamples();
}

void Rendering::RendererImpl
	::Bind(const ConstVertexFormatSharedPtr& vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexFormatManagement->Bind(vertexFormat);
}

void Rendering::RendererImpl
	::Unbind(const ConstVertexFormatSharedPtr& vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexFormatManagement->Unbind(vertexFormat);
}

void Rendering::RendererImpl
	::Enable(const ConstVertexFormatSharedPtr& vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexFormatManagement->Enable(vertexFormat);
}

void Rendering::RendererImpl
	::Disable(const ConstVertexFormatSharedPtr& vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexFormatManagement->Disable(vertexFormat);
}

Rendering::RendererImpl::PlatformVertexFormatSharedPtr Rendering::RendererImpl
	::GetResource(const ConstVertexFormatSharedPtr& vertexFormat)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexFormatManagement->GetResource(vertexFormat);
}

void Rendering::RendererImpl
	::Bind(const ConstVertexBufferSharedPtr& vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->Bind(vertexBuffer);
}

void Rendering::RendererImpl
	::Unbind(const ConstVertexBufferSharedPtr& vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->Unbind(vertexBuffer);
}

void Rendering::RendererImpl
	::Enable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex, int offset)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->EnableVertexBuffer(vertexBuffer, streamIndex, offset);
}

void Rendering::RendererImpl
	::Disable(const ConstVertexBufferSharedPtr& vertexBuffer, int streamIndex)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->DisableVertexBuffer(vertexBuffer, streamIndex);
}

void* Rendering::RendererImpl
	::Lock(const ConstVertexBufferSharedPtr& vertexBuffer, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->Lock(vertexBuffer, mode);
}

void Rendering::RendererImpl
	::Unlock(const ConstVertexBufferSharedPtr& vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->Unlock(vertexBuffer);
}

void Rendering::RendererImpl
	::Update(const ConstVertexBufferSharedPtr& vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->Update(vertexBuffer);
}

void Rendering::RendererImpl
	::Bind(const ConstIndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->Bind(indexbuffer);
}

void Rendering::RendererImpl
	::Unbind(const ConstIndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->Unbind(indexbuffer);
}

void Rendering::RendererImpl
	::Enable(const ConstIndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->EnableIndexBuffer(indexbuffer);
}

void Rendering::RendererImpl
	::Disable(const ConstIndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->DisableIndexBuffer(indexbuffer);
}

void* Rendering::RendererImpl
	::Lock(const ConstIndexBufferSharedPtr& indexbuffer, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->Lock(indexbuffer, mode);
}

void Rendering::RendererImpl
	::Unlock(const ConstIndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->Unlock(indexbuffer);
}

void Rendering::RendererImpl
	::Update(const ConstIndexBufferSharedPtr& indexbuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->Update(indexbuffer);
}

Rendering::RendererImpl::PlatformVertexBufferSharedPtr Rendering::RendererImpl
	::GetResource(const ConstVertexBufferSharedPtr& vertexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexBufferManagement->GetResource(vertexBuffer);
}

Rendering::RendererImpl::PlatformIndexBufferSharedPtr Rendering::RendererImpl
	::GetResource(const ConstIndexBufferSharedPtr& indexBuffer)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_IndexBufferManagement->GetResource(indexBuffer);
}

void Rendering::RendererImpl
	::Bind(const ConstTexture1DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Bind(texture);
}

void Rendering::RendererImpl
	::Unbind(const ConstTexture1DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Unbind(texture);
}

void Rendering::RendererImpl
	::Enable(const ConstTexture1DSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable(const ConstTexture1DSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock(const ConstTexture1DSharedPtr& texture,int level, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Lock(texture, level, mode);
}

void Rendering::RendererImpl
	::Unlock(const ConstTexture1DSharedPtr& texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Unlock(texture, level);
}

void Rendering::RendererImpl
	::Update(const ConstTexture1DSharedPtr& texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->Update(texture, level);
}

Rendering::RendererImpl::PlatformTexture1DSharedPtr Rendering::RendererImpl
	::GetResource(const ConstTexture1DSharedPtr& texture1D)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture1DManagement->GetResource(texture1D);
}

void Rendering::RendererImpl
	::Bind(const ConstTexture2DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Bind(texture);
}

void Rendering::RendererImpl
	::Unbind(const ConstTexture2DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Unbind(texture);
}

void Rendering::RendererImpl
	::Enable(const ConstTexture2DSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable(const ConstTexture2DSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock(const ConstTexture2DSharedPtr& texture, int level, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Lock(texture, level, mode);
}

void Rendering::RendererImpl
	::Unlock(const ConstTexture2DSharedPtr& texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Unlock(texture, level);
}

void Rendering::RendererImpl
	::Update(const ConstTexture2DSharedPtr& texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->Update(texture, level);
}

Rendering::RendererImpl::PlatformTexture2DSharedPtr Rendering::RendererImpl
	::GetResource(const ConstTexture2DSharedPtr& texture2D)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->GetResource(texture2D);
}

void Rendering::RendererImpl
	::Bind(const ConstTexture3DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Bind(texture);
}

void Rendering::RendererImpl
	::Unbind(const ConstTexture3DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Unbind(texture);
}

void Rendering::RendererImpl
	::Enable(const ConstTexture3DSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable(const ConstTexture3DSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock(const ConstTexture3DSharedPtr& texture, int level, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Lock(texture, level, mode);
}

void Rendering::RendererImpl
	::Unlock(const ConstTexture3DSharedPtr& texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Unlock(texture, level);
}

void Rendering::RendererImpl
	::Update(const ConstTexture3DSharedPtr& texture, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->Update(texture, level);
}

Rendering::RendererImpl::PlatformTexture3DSharedPtr Rendering::RendererImpl
	::GetResource(const ConstTexture3DSharedPtr& texture3D)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture3DManagement->GetResource(texture3D);
}

void Rendering::RendererImpl
	::Bind(const ConstTextureCubeSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->Bind(texture);
}

void Rendering::RendererImpl
	::Unbind(const ConstTextureCubeSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->Unbind(texture);
}

void Rendering::RendererImpl
	::Enable(const ConstTextureCubeSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->Enable(texture, textureUnit);
}

void Rendering::RendererImpl
	::Disable(const ConstTextureCubeSharedPtr& texture, int textureUnit)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->Disable(texture, textureUnit);
}

void* Rendering::RendererImpl
	::Lock(const ConstTextureCubeSharedPtr& texture, int face, int level, BufferLocking mode)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->LockCube(texture, face, level, mode);
}

void Rendering::RendererImpl
	::Unlock(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->UnlockCube(texture, face, level);
}

void Rendering::RendererImpl
	::Update(const ConstTextureCubeSharedPtr& texture, int face, int level)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->UpdateCube(texture, face, level);
}

Rendering::RendererImpl::PlatformTextureCubeSharedPtr Rendering::RendererImpl
	::GetResource(const ConstTextureCubeSharedPtr& textureCube)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_TextureCubeManagement->GetResource(textureCube);
}

void Rendering::RendererImpl
	::Bind(const ConstRenderTargetSharedPtr& renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_RenderTargetManagement->Bind(renderTarget);
}

void Rendering::RendererImpl
	::Unbind(const ConstRenderTargetSharedPtr& renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_RenderTargetManagement->Unbind(renderTarget);
}

void Rendering::RendererImpl
	::Enable(const ConstRenderTargetSharedPtr& renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_RenderTargetManagement->Enable(renderTarget);
}

void Rendering::RendererImpl
	::Disable(const ConstRenderTargetSharedPtr& renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_RenderTargetManagement->Disable(renderTarget);
}

Rendering::ConstTexture2DSharedPtr Rendering::RendererImpl
	::ReadColor(int index, const ConstRenderTargetSharedPtr& renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_RenderTargetManagement->ReadColor(index, renderTarget);
}

Rendering::RendererImpl::PlatformRenderTargetSharedPtr Rendering::RendererImpl
	::GetResource(const ConstRenderTargetSharedPtr& renderTarget)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_RenderTargetManagement->GetResource(renderTarget);
}

void Rendering::RendererImpl
	::Bind(const ConstVertexShaderSharedPtr& vertexShader)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexShaderManagement->Bind(vertexShader); 
}

void Rendering::RendererImpl
	::Unbind(const ConstVertexShaderSharedPtr& vertexShader)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexShaderManagement->Unbind(vertexShader);
}

void Rendering::RendererImpl
	::Enable(const ConstVertexShaderSharedPtr& vertexShader, const ConstShaderParametersSharedPtr& parameters)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexShaderManagement->Enable(vertexShader, parameters);
}

void Rendering::RendererImpl
	::Disable(const ConstVertexShaderSharedPtr& vertexShader, const ConstShaderParametersSharedPtr& parameters)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexShaderManagement->Disable(vertexShader, parameters);
}

Rendering::RendererImpl::PlatformVertexShaderSharedPtr Rendering::RendererImpl
	::GetResource(const ConstVertexShaderSharedPtr& vertexShader)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VertexShaderManagement->GetResource(vertexShader);
}

void Rendering::RendererImpl
	::Bind(const ConstPixelShaderSharedPtr& pixelShader)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_PixelShaderManagement->Bind(pixelShader);
}

void Rendering::RendererImpl
	::Unbind(const ConstPixelShaderSharedPtr& pixelShader)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_PixelShaderManagement->Unbind(pixelShader);
}

void Rendering::RendererImpl
	::Enable(const ConstPixelShaderSharedPtr& pixelShader, const ConstShaderParametersSharedPtr& parameters)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_PixelShaderManagement->Enable(pixelShader, parameters);
}

void Rendering::RendererImpl
	::Disable(const ConstPixelShaderSharedPtr& pixelShader, const ConstShaderParametersSharedPtr& parameters)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_PixelShaderManagement->Disable(pixelShader, parameters);
}

Rendering::RendererImpl::PlatformPixelShaderSharedPtr Rendering::RendererImpl
	::GetResource(const ConstPixelShaderSharedPtr& pixelShader)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_PixelShaderManagement->GetResource(pixelShader);
}

const Rendering::ConstAlphaStateSharedPtr Rendering::RendererImpl
	::GetAlphaState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_AlphaState;
}

const Rendering::ConstCullStateSharedPtr Rendering::RendererImpl
	::GetCullState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_CullState;
}

const Rendering::ConstDepthStateSharedPtr Rendering::RendererImpl
	::GetDepthState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_DepthState;
}

const Rendering::ConstOffsetStateSharedPtr Rendering::RendererImpl
	::GetOffsetState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OffsetState;
}

const Rendering::ConstStencilStateSharedPtr Rendering::RendererImpl
	::GetStencilState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_StencilState;
}

const Rendering::ConstWireStateSharedPtr Rendering::RendererImpl
	::GetWireState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_WireState;
}

const Rendering::ConstAlphaStateSharedPtr Rendering::RendererImpl
	::GetOverrideAlphaState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OverrideAlphaState;
}

const Rendering::ConstCullStateSharedPtr Rendering::RendererImpl
	::GetOverrideCullState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OverrideCullState;
}

const Rendering::ConstDepthStateSharedPtr Rendering::RendererImpl
	::GetOverrideDepthState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OverrideDepthState;
}

const Rendering::ConstOffsetStateSharedPtr Rendering::RendererImpl
	::GetOverrideOffsetState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OverrideOffsetState;
}

const Rendering::ConstStencilStateSharedPtr Rendering::RendererImpl
	::GetOverrideStencilState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OverrideStencilState;
}

const Rendering::ConstWireStateSharedPtr Rendering::RendererImpl
	::GetOverrideWireState() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_OverrideWireState;
}

void Rendering::RendererImpl
	::SetOverrideAlphaState(const ConstAlphaStateSharedPtr& alphaState)
{
	RENDERING_CLASS_IS_VALID_1;

	m_OverrideAlphaState = alphaState;
	if (alphaState )
	{
		SetAlphaState(alphaState);
	}
	else
	{
		SetAlphaState(m_DefaultAlphaState);
	}
}

void Rendering::RendererImpl
	::SetOverrideCullState(const ConstCullStateSharedPtr& cullState)
{
	RENDERING_CLASS_IS_VALID_1;

	m_OverrideCullState = cullState;
	if (cullState )
	{
		SetCullState(cullState);
	}
	else
	{
		SetCullState(m_DefaultCullState);
	}
}

void Rendering::RendererImpl
	::SetOverrideDepthState(const ConstDepthStateSharedPtr& depthState)
{
	RENDERING_CLASS_IS_VALID_1;

	m_OverrideDepthState = depthState;
	if (depthState )
	{
		SetDepthState(depthState);
	}
	else
	{
		SetDepthState(m_DefaultDepthState);
	}
}

void Rendering::RendererImpl
	::SetOverrideOffsetState(const ConstOffsetStateSharedPtr& offsetState)
{
	RENDERING_CLASS_IS_VALID_1;

	m_OverrideOffsetState = offsetState;
	if (offsetState )
	{
		SetOffsetState(offsetState);
	}
	else
	{
		SetOffsetState(m_DefaultOffsetState);
	}
}

void Rendering::RendererImpl
	::SetOverrideStencilState(const ConstStencilStateSharedPtr& stencilState)
{
	RENDERING_CLASS_IS_VALID_1;

	m_OverrideStencilState = stencilState;
	if (stencilState )
	{
		SetStencilState(stencilState);
	}
	else
	{
		SetStencilState(m_DefaultStencilState);
	}
}

void Rendering::RendererImpl
	::SetOverrideWireState(const ConstWireStateSharedPtr& wireState)
{
	RENDERING_CLASS_IS_VALID_1;

	m_OverrideWireState = wireState;
	if (wireState )
	{
		SetWireState(wireState);
	}
	else
	{
		SetWireState(m_DefaultWireState);
	}
}

void Rendering::RendererImpl
	::SetReverseCullOrder(bool reverseCullOrder)
{
	RENDERING_CLASS_IS_VALID_1;

	m_ReverseCullOrder = reverseCullOrder;
}

bool Rendering::RendererImpl
	::GetReverseCullOrder() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ReverseCullOrder;
}

void Rendering::RendererImpl
	::SetCamera(const CameraSharedPtr& camera)
{
	RENDERING_CLASS_IS_VALID_1;

	m_Camera = camera;
}

const Rendering::ConstCameraSharedPtr Rendering::RendererImpl
	::GetCamera() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_Camera;
}

const Rendering::CameraSharedPtr Rendering::RendererImpl
	::GetCamera()
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Camera;
}

const Rendering::RendererImpl::Matrix Rendering::RendererImpl
	::GetViewMatrix() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (m_Camera )
	{
		return m_Camera->GetViewMatrix();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("摄像机不存在。"s));
	}
}

const Rendering::RendererImpl::Matrix Rendering::RendererImpl
	::GetProjectionMatrix() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (m_Camera )
	{
		return m_Camera->GetProjectionMatrix();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("摄像机不存在。"s));
	}
}

const Rendering::RendererImpl::Matrix Rendering::RendererImpl
	::GetPostProjectionMatrix() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if (m_Camera )
	{
		return m_Camera->GetPostProjectionMatrix();
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("摄像机不存在。"s));
	}
}

Rendering::PickRay Rendering::RendererImpl
	::GetPickRay(int x, int y) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	const PickRay errorPickRay{ };

	if (!m_Camera)
	{
		return errorPickRay;
	}

	// 获取当前视口，并测试其中是否包含（x，y）。
	const auto viewport = GetViewport();
	if (!viewport.IsInViewport(x,y))
	{
		return errorPickRay;
	}
 
	// 获取(x,y)的[0,1]^2归一化坐标。
	auto r = (boost::numeric_cast<float>(x - viewport.GetXPosition())) / boost::numeric_cast<float>(viewport.GetWidth());
	auto u = (boost::numeric_cast<float>(y - viewport.GetYPosition())) / boost::numeric_cast<float>(viewport.GetHeight());

 	// 获取相对坐标，单位为[rmin,rmax] x [umin,umax]。
	const auto rightBlend = (1.0f - r) * m_Camera->GetRightMin() + r * m_Camera->GetRightMax();
	const auto upBlend = (1.0f - u) * m_Camera->GetUpMin() + u * m_Camera->GetUpMax();

	Mathematics::FloatAPoint origin{ };
        Mathematics::FloatAVector direction{   };

	if (m_Camera->IsPerspective())
	{
		origin = m_Camera->GetPosition();
		direction = m_Camera->GetDirectionMin() * m_Camera->GetDirectionVector() + rightBlend * m_Camera->GetRightVector() + upBlend * m_Camera->GetUpVector();
		direction.Normalize();
	}
	else
	{
		origin = m_Camera->GetPosition() + rightBlend * m_Camera->GetRightVector() + upBlend * m_Camera->GetUpVector();
		direction = m_Camera->GetDirectionVector();
	}
 
	return PickRay{ true, origin, direction };
}

void Rendering::RendererImpl
	::SetClearColor(const Colour& clearColor)
{
	RENDERING_CLASS_IS_VALID_1;

	m_ClearColor = clearColor;
}

const Rendering::RendererImpl::Colour Rendering::RendererImpl
	::GetClearColor() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ClearColor;
}

void Rendering::RendererImpl
	::SetClearDepth(float clearDepth)
{
	RENDERING_CLASS_IS_VALID_1;

	m_ClearDepth = clearDepth;
}

float Rendering::RendererImpl
	::GetClearDepth() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ClearDepth;
}

void Rendering::RendererImpl
	::SetClearStencil(int clearStencil)
{
	RENDERING_CLASS_IS_VALID_1;

	m_ClearStencil = clearStencil;
}

int Rendering::RendererImpl
	::GetClearStencil() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_ClearStencil;
}

bool Rendering::RendererImpl
	::GetAllowRed() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_AllowRed;
}

bool Rendering::RendererImpl
	::GetAllowGreen() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_AllowGreen;
}

bool Rendering::RendererImpl
	::GetAllowBlue() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_AllowBlue;
}

bool Rendering::RendererImpl
	::GetAllowAlpha() const
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	return m_AllowAlpha;
}

void Rendering::RendererImpl
	::SetAllowRed(bool allowRed)
{
	RENDERING_CLASS_IS_VALID_1;

	m_AllowRed = allowRed;
}

void Rendering::RendererImpl
	::SetAllowGreen(bool allowGreen)
{
	RENDERING_CLASS_IS_VALID_1;

	m_AllowGreen = allowGreen;
}

void Rendering::RendererImpl
	::SetAllowBlue(bool allowBlue)
{
	RENDERING_CLASS_IS_VALID_1;

	m_AllowBlue = allowBlue;
}

void Rendering::RendererImpl
	::SetAllowAlpha(bool allowAlpha)
{
	RENDERING_CLASS_IS_VALID_1;

	m_AllowAlpha = allowAlpha;
}

void Rendering::RendererImpl
	::Draw(VisibleSet& visibleSet, GlobalEffectSharedPtr globalEffect)
{
	RENDERING_CLASS_IS_VALID_1;

	if (!globalEffect )
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
		globalEffect->Draw(RendererSharedPtr{ m_RealRenderer }, visibleSet);
	}
}

void Rendering::RendererImpl
	::Draw(VisualSharedPtr visual)
{
	RENDERING_CLASS_IS_VALID_1;

	const auto instance = visual->GetEffectInstance();

	Draw(visual, instance);
}

void Rendering::RendererImpl
	::Draw(const VisualSharedPtr& visual, VisualEffectInstanceSharedPtr instance)
{	 
	RENDERING_ASSERTION_0(visual != nullptr , "visual对象必须存在。\n");	
	RENDERING_ASSERTION_0(instance != nullptr, "visual对象必须具有effect实例。\n");
		 
	const auto vertexFormat = visual->GetConstVertexFormat();
	const auto vertexBuffer = visual->GetConstVertexBuffer();
	const auto indexBuffer = visual->GetConstIndexBuffer();
 
	// OpenGL渲染器要求在启用顶点格式之前先启用顶点缓冲区。 该顺序与DirectX9渲染器无关。
	Enable(vertexBuffer);
	Enable(vertexFormat);
	if (indexBuffer )
	{
		Enable(indexBuffer);
	}

	const auto numPasses = instance->GetNumPasses();
	for (int i = 0; i < numPasses; ++i)
	{		 
	 	const auto pass = instance->GetConstPass(i);
		auto vertexParameters = instance->GetVertexParameters(i);
		auto pixelParameters = instance->GetPixelParameters(i);
		auto vertexShader = pass->GetVertexShader();
		auto pixelShader = pass->GetPixelShader();
		 
		// 更新在运行时变化的所有着色器常量。
		vertexParameters->UpdateConstants(visual, m_Camera);
		pixelParameters->UpdateConstants(visual, m_Camera);

		// 设置视觉状态。
		SetAlphaState(pass->GetAlphaState());
		SetCullState(pass->GetCullState());
		SetDepthState(pass->GetDepthState());
		SetOffsetState(pass->GetOffsetState());
		SetStencilState(pass->GetStencilState());
		SetWireState(pass->GetWireState());

		// 启用着色器。
		Enable(vertexShader, vertexParameters);
		Enable(pixelShader, pixelParameters);

		// 绘制图元。
		DrawPrimitive(visual);

		// 禁用着色器。
		Disable(vertexShader, vertexParameters);
		Disable(pixelShader, pixelParameters); 

	#ifdef RENDERING_RESET_STATE_AFTER_DRAW
		// 恢复视觉状态。
		SetAlphaState(m_DefaultAlphaState);
		SetCullState(m_DefaultCullState);
		SetDepthState(m_DefaultDepthState);
		SetOffsetState(m_DefaultOffsetState);
		SetStencilState(m_DefaultStencilState);
		SetWireState(m_DefaultWireState);
	#endif // RENDERING_RESET_STATE_AFTER_DRAW
	}

	if (indexBuffer )
	{
		Disable(indexBuffer);
	}

	Disable(vertexFormat);
	Disable(vertexBuffer);
} 

bool Rendering::RendererImpl
	::InTexture2DMap(const ConstTexture2DSharedPtr& texture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->IsInTextureMap(texture);
}

void Rendering::RendererImpl
	::InsertInTexture2DMap(const ConstTexture2DSharedPtr& texture, const PlatformTexture2DSharedPtr& platformTexture)
{
	RENDERING_CLASS_IS_VALID_1;

	return m_Texture2DManagement->InsertTextureMap(texture, platformTexture);
}
 #include STSTEM_WARNING_POP